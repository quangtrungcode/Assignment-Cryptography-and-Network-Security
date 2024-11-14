#ifndef CAESAR_RAIL_FENCE_ENCRYPT_H
#define CAESAR_RAIL_FENCE_ENCRYPT_
#include"Rail_Fence_Encrypt.h"
char caesarChar(char c, int key);
std::string caesarEncrypt(const std::string& plainText, int key);
std::string railFenceEncrypt(const std::string& plainText, int numRails);
#endif