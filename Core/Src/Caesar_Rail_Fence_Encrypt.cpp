#include"Caesar_Rail_Fence_Encrypt.h"

char caesarChar(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + key) % 26 + 'A';  // Mã hóa cho chữ hoa
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + key) % 26 + 'a';  // Mã hóa cho chữ thường
    } else {
        return c;  // Giữ nguyên các ký tự không phải chữ cái
    }
}

// Hàm mã hóa Caesar cho chuỗi
std::string caesarEncrypt(const std::string& plainText, int key) {
    std::string encryptedText;
    for (char c : plainText) {
        encryptedText += caesarChar(c, key);
    }
    return encryptedText;
}

// Hàm mã hóa Rail Fence
std::string railFenceEncrypt(const std::string& plainText, int numRails) {
    if (numRails == 1) return plainText;  // Nếu chỉ có 1 rail, không có sự thay đổi gì

    std::vector<std::string> rails(numRails);
    int rail = 0;
    bool directionDown = true;

    // Xếp các ký tự vào các dòng (rails)
    for (char c : plainText) {
        rails[rail] += c;
        if (rail == 0) {
            directionDown = true;  // Di chuyển xuống
        } else if (rail == numRails - 1) {
            directionDown = false; // Di chuyển lên
        }
        rail += directionDown ? 1 : -1;
    }

    // Đọc từng dòng theo thứ tự từ trên xuống dưới để tạo ra bản mã
    std::string encryptedText;
    for (const auto& row : rails) {
        encryptedText += row;
    }
    return encryptedText;
}

int main() {
    std::string plainText;
    int caesarKey, railKey;

    // Nhập bản rõ, khóa Caesar và số dòng Rail Fence
    std::cout << "Nhập bản rõ: ";
    std::getline(std::cin, plainText);

    std::cout << "Nhập khóa Caesar (số nguyên): ";
    std::cin >> caesarKey;

    std::cout << "Nhập số dòng Rail Fence: ";
    std::cin >> railKey;

    // Mã hóa bản rõ bằng Caesar Cipher
    std::string caesarEncrypted = caesarEncrypt(plainText, caesarKey);
    std::cout << "Bản mã sau khi mã hóa Caesar: " << caesarEncrypted << std::endl;

    // Mã hóa kết quả Caesar Cipher bằng Rail Fence Cipher
    std::string railFenceEncrypted = railFenceEncrypt(caesarEncrypted, railKey);
    std::cout << "Bản mã cuối cùng sau khi mã hóa Rail Fence: " << railFenceEncrypted << std::endl;

    return 0;
}