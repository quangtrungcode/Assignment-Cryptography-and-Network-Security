#include"Caesar_Decrypt.h"
char caesarDecryptChar(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' - key + 26) % 26 + 'A';  // Giải mã cho chữ hoa
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a' - key + 26) % 26 + 'a';  // Giải mã cho chữ thường
    } else {
        return c;  // Giữ nguyên các ký tự không phải chữ cái
    }
}

// Hàm giải mã Caesar cho chuỗi
std::string caesarDecrypt(const std::string& encryptedText, int key) {
    std::string decryptedText;
    for (char c : encryptedText) {
        decryptedText += caesarDecryptChar(c, key);
    }
    return decryptedText;
}

// Hàm thử tất cả các khóa từ 0 đến 25 để tìm bản rõ
void bruteForceCaesarDecrypt(const std::string& encryptedText) {
    std::cout << "Thử tất cả các khóa (0-25):" << std::endl;
    for (int key = 0; key < 26; ++key) {
        std::string decryptedText = caesarDecrypt(encryptedText, key);
        std::cout << "Khóa " << key << ": " << decryptedText << std::endl;
    }
}

int main() {
    std::string encryptedText;
    std::cout << "Nhập bản mã Caesar: ";
    std::getline(std::cin, encryptedText);

    // Giải mã Caesar với phương pháp thử khóa
    bruteForceCaesarDecrypt(encryptedText);

    return 0;
}