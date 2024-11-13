#ifndef  CAESAR_ENCRYPT_H
#define CAESAR_ENCRYPT_H
#include<iostream>
#include<string>
using namespace std;
char caesarChar(char c, int key);
std::string caesarEncrypt(const std::string& plainText, int key);

#endif