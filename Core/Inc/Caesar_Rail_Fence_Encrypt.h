#ifndef CAESAR_RAIL_FENCE_ENCRYPT_H
#define CAESAR_RAIL_FENCE_ENCRYPT_
#include"Caesar_Encrypt.h"
char caesarChar(char c, int key);
std::string caesarEncrypt(const std::string& plainText, int key);
std::string railFenceEncrypt(const std::string& plainText, int numRails);
void decryptAndUpdateBestResult(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary,
                                int numRails, int& bestValidWords, std::string& bestDecryptedText,
                                int& bestShift, int& bestRails);
                                
#endif