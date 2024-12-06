#include"Caesar_Decrypt.h"


#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <omp.h>

// Tải từ điển từ file
std::unordered_set<std::string> loadDictionary1(const std::string& dictionaryFile) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(dictionaryFile);
    if (!file) {
        std::cerr << "Error opening file: " << dictionaryFile << std::endl;
        return dictionary;
    }
    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        dictionary.insert(word);
    }
    return dictionary;
}


std::string caesarDecrypt1(const std::string& text, int shift) {
    std::string decryptedText = text;
   
    for (char& c : decryptedText) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return decryptedText;
}



int findValidWords1(const std::string& text, const std::unordered_set<std::string>& dictionary) {
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

int globalMaxValidWords = 0;
std::string bestDecryptedTextGlobal;
int bestKeyGlobal = 0;


void bruteForceCaesarDecrypt(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
    #pragma omp parallel for
    for (int key = 0; key < 26; ++key) {
        std::string decryptedText = caesarDecrypt1(encryptedText, key);
        int validWords = findValidWords1(decryptedText, dictionary);

        
        #pragma omp critical
        {
            std::cout << "Khóa " << key << ": " << decryptedText << " -> Số từ hợp lệ: " << validWords << std::endl;

            
            if (validWords > globalMaxValidWords) {
                globalMaxValidWords = validWords;
                bestDecryptedTextGlobal = decryptedText;
                bestKeyGlobal = key;
            }
        }
    }
}




