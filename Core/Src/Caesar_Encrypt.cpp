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

// int main() {
//     std::string plainText;
//     int key;

//     cout << "Nhập bản rõ: ";
//     std::getline(std::cin, plainText);

//     std::cout << "Nhập khóa (số nguyên): ";
//     std::cin >> key;

//     std::string encryptedText = caesarEncrypt(plainText, key);
//     std::cout << "Bản mã sau khi mã hóa Caesar: " << encryptedText << std::endl;

//     return 0;
// }

