#include"Caesar_Rail_Fence_Encrypt.h"

char caesarChar(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + key) % 26 + 'A';  
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + key) % 26 + 'a';  
    } else {
        return c;  
    }
}


std::string caesarEncrypt(const std::string& plainText, int key) {
    std::string encryptedText;
    for (char c : plainText) {
        encryptedText += caesarChar(c, key);
    }
    return encryptedText;
}


std::string railFenceEncrypt(const std::string& plainText, int numRails) {
    if (numRails == 1) return plainText;  

    std::vector<std::string> rails(numRails);
    int rail = 0;
    bool directionDown = true;

   
    for (char c : plainText) {
        rails[rail] += c;
        if (rail == 0) {
            directionDown = true;  
        } else if (rail == numRails - 1) {
            directionDown = false; 
        }
        rail += directionDown ? 1 : -1;
    }

    
    std::string encryptedText;
    for (const auto& row : rails) {
        encryptedText += row;
    }
    return encryptedText;
}

// int main() {
//     std::string plainText;
//     int caesarKey, railKey;

   
//     std::cout << "Nhập bản rõ: ";
//     std::getline(std::cin, plainText);

//     std::cout << "Nhập khóa Caesar (số nguyên): ";
//     std::cin >> caesarKey;

//     std::cout << "Nhập số dòng Rail Fence: ";
//     std::cin >> railKey;

    
//     std::string caesarEncrypted = caesarEncrypt(plainText, caesarKey);
//     std::cout << "Bản mã sau khi mã hóa Caesar: " << caesarEncrypted << std::endl;

   
//     std::string railFenceEncrypted = railFenceEncrypt(caesarEncrypted, railKey);
//     std::cout << "Bản mã cuối cùng sau khi mã hóa Rail Fence: " << railFenceEncrypted << std::endl;

//     return 0;
// }