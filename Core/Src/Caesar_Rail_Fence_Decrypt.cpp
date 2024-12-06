#include"Caesar_Rail_Fence_Decrypt.h"





#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>
#include<chrono>

std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
    int len = encryptedText.length();
    std::vector<int> railPattern(len, -1);
    std::vector<std::string> rails(numRails); 

    
    int currentRail = 0;
    bool goingDown = false;
    for (int i = 0; i < len; ++i) {
        railPattern[i] = currentRail;
        if (currentRail == 0 || currentRail == numRails - 1)
            goingDown = !goingDown;
        currentRail += (goingDown ? 1 : -1);
    }

    
    std::vector<int> railLengths(numRails, 0);
    for (int r : railPattern) {
        railLengths[r]++;
    }

    
    int index = 0;
    for (int r = 0; r < numRails; ++r) {
        rails[r] = encryptedText.substr(index, railLengths[r]);
        index += railLengths[r];
    }

    
    std::string decryptedText;
    std::vector<int> railIndices(numRails, 0); 
    for (int i = 0; i < len; ++i) {
        int r = railPattern[i];
        decryptedText += rails[r][railIndices[r]++];
    }

    return decryptedText;
}


std::string caesarDecrypt(const std::string& text, int shift) {
    std::string decryptedText = text;
  
    for (char& c : decryptedText) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return decryptedText;
}


std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(dictionaryFile);
    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);  
        dictionary.insert(word);
    }
    return dictionary;
}


int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int count = 0;
    std::string lowerText = text;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);

    const int maxWordLength = 20;
    size_t textLength = lowerText.size();

    
    int localCount = 0;

    #pragma omp parallel for reduction(+:localCount)
    for (size_t len = 1; len <= std::min(static_cast<std::size_t>(maxWordLength), textLength); ++len) {
        
        for (size_t i = 0; i + len <= textLength; ++i) {
            std::string word = lowerText.substr(i, len);
            if (dictionary.find(word) != dictionary.end()) {
                localCount++;  
            }
        }
    }

    
    count += localCount;

    return count;
}



void decryptAndUpdateBestResult(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary,
                                int numRails, int& bestValidWords, std::string& bestDecryptedText,
                                int& bestShift, int& bestRails) {
    std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);
 
    #pragma omp parallel for
    for (int shift = 1; shift < 26; ++shift) {
        std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
        int validWords = findValidWords(caesarDecryptedText, dictionary);
        
        
        #pragma omp critical
        {
            if (validWords > bestValidWords) {
                bestValidWords = validWords;
                bestDecryptedText = caesarDecryptedText;
                bestShift = shift;
                bestRails = numRails;
            }
        }
    }
}


std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
    int bestValidWords = 0;
    std::string bestDecryptedText;
    int bestShift = 0;
    int bestRails = 0;

    #pragma omp parallel for
    for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
        decryptAndUpdateBestResult(encryptedText, dictionary, numRails, bestValidWords, bestDecryptedText, bestShift, bestRails);
    }
    std::cout << "Khóa giải mã:\n";
    std::cout << "Số đường ray (Rails): " << bestRails << std::endl;
    std::cout << "Độ lệch Caesar (Shift): " << bestShift << std::endl;
    return bestDecryptedText;
}






