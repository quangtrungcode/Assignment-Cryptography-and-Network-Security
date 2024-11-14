#include"Caesar_Encrypt.h"
char caesarChar(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        // Mã hóa cho chữ hoa (A-Z)
        return (c - 'A' + key) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
        // Mã hóa cho chữ thường (a-z)
        return (c - 'a' + key) % 26 + 'a';
    } else {
        // Giữ nguyên các ký tự không phải chữ cái
        return c;
    }
}

// Hàm mã hóa Caesar cho chuỗi
std::string caesarEncrypt(const std::string& plainText, int key) {
    std::string encryptedText;
    
    // Duyệt qua từng ký tự trong bản rõ và mã hóa nó
    for (char c : plainText) {
        encryptedText += caesarChar(c, key);
    }
    
    return encryptedText;
}

int main() {
    std::string plainText;
    int key;

    cout << "Nhập bản rõ: ";
    std::getline(std::cin, plainText);

    std::cout << "Nhập khóa (số nguyên): ";
    std::cin >> key;

    // Mã hóa bản rõ và in ra kết quả
    std::string encryptedText = caesarEncrypt(plainText, key);
    std::cout << "Bản mã sau khi mã hóa Caesar: " << encryptedText << std::endl;

    return 0;
}

