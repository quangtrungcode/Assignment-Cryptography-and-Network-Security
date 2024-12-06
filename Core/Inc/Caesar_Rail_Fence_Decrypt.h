#ifndef CAESAR_RAIL_FENCE_DECRYPT_H
#define CAESAR_RAIL_FENCE_DECRY
#include"Caesar_Encrypt.h"
//#include<vector>
std::string railFenceDecrypt(const std::string& encryptedText, int numRails);
std::string caesarDecrypt(const std::string& text, int shift);
std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile);
int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary);
void decryptAndUpdateBestResult(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary,
                                int numRails, int& bestValidWords, std::string& bestDecryptedText,
                                int& bestShift, int& bestRails);
std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary);
#endif