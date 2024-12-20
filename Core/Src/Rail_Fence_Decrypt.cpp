#include"Rail_Fence_Decrypt.h"


#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <omp.h>
#include <chrono> 
std::unordered_set<std::string> loadDictionary2(const std::string& dictionaryFile) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(dictionaryFile);
    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        dictionary.insert(word);
    }
    return dictionary;
}



int findValidWords2(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int count = 0;
    std::string lowerText = text;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);

    const int maxWordLength = 15;
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



std::string railFenceDecrypt1(const std::string& encryptedText, int numRails) {
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

void findBestDecryption(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, 
                        int startRail, int endRail, int& maxValidWords, std::vector<std::pair<int, std::string>>& bestDecryptedTexts) {
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel for
    for (int numRails = startRail; numRails <= endRail; ++numRails) {
        std::string decryptedText = railFenceDecrypt1(encryptedText, numRails);
        int validWords = findValidWords2(decryptedText, dictionary);

        

       
        omp_set_lock(&lock);
        if (validWords > maxValidWords) {
            maxValidWords = validWords;
            bestDecryptedTexts.clear();
            bestDecryptedTexts.push_back({numRails, decryptedText});
        } else if (validWords == maxValidWords) {
            bestDecryptedTexts.push_back({numRails, decryptedText});
        }
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
}



