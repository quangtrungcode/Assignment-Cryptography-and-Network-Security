#ifndef CAESAR_DECRYPT_H
#define CAESAR_DECRYPT_H
#include"Caesar_Encrypt.h"
std::unordered_set<std::string> loadDictionary1(const std::string& dictionaryFile);
std::string caesarDecrypt1(const std::string& text, int shift);
int findValidWords1(const std::string& text, const std::unordered_set<std::string>& dictionary);
void bruteForceCaesarDecrypt(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary);
extern int globalMaxValidWords ;
extern std::string bestDecryptedTextGlobal;
extern int bestKeyGlobal ;
#endif