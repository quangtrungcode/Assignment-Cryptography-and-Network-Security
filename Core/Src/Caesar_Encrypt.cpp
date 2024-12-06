#include"Caesar_Encrypt.h"
char caesarChar1(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        
        return (c - 'A' + key) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
        
        return (c - 'a' + key) % 26 + 'a';
    } else {
        
        return c;
    }
}


std::string caesarEncrypt1(const std::string& plainText, int key) {
    std::string encryptedText;
    
    for (char c : plainText) {
        encryptedText += caesarChar1(c, key);
    }
    
    return encryptedText;
}



