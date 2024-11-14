#ifndef CAESAR_DECRYPT_H
#define CAESAR_DECRYPT_H
#include"Caesar_Encrypt.h"
char caesarDecryptChar(char c, int key);
std::string caesarDecrypt(const std::string& encryptedText, int key);
void bruteForceCaesarDecrypt(const std::string& encryptedText);
#endif