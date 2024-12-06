#ifndef  CAESAR_ENCRYPT_H
#define CAESAR_ENCRYPT_H
#include<iostream>
#include<string>
#include <cctype>
#include <fstream>
#include <unordered_set>
#include <sstream> // Thư viện cho istringstream
#include <algorithm>
#include<vector>
using namespace std;
char caesarChar1(char c, int key);
std::string caesarEncrypt1(const std::string& plainText, int key);

#endif