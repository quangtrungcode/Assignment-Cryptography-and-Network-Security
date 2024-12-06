#ifndef RAIL_FENCE_DECRYPT_H
#define RAIL_FENCE_DECRYPT_H
#include <thread>
#include <mutex>
#include"Caesar_Encrypt.h"
std::unordered_set<std::string> loadDictionary2(const std::string& dictionaryFile);
int findValidWords2(const std::string& text, const std::unordered_set<std::string>& dictionary);
std::string railFenceDecrypt1(const std::string& encryptedText, int numRails);
void findBestDecryption(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, 
                        int startRail, int endRail, int& maxValidWords, std::vector<std::pair<int, std::string>>& bestDecryptedTexts);
#endif