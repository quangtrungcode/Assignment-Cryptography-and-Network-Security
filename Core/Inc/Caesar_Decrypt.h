#ifndef CAESAR_DECRYPT_H
#define CAESAR_DECRYPT_H
#include <cctype>
#include <fstream>
#include <unordered_set>
#include <sstream> // Thư viện cho istringstream
#include <algorithm>
#include"Caesar_Encrypt.h"
char caesarDecryptChar(char c, int key);
std::string caesarDecrypt(const std::string& encryptedText, int key);
void bruteForceCaesarDecrypt(const std::string& encryptedText);
#endif