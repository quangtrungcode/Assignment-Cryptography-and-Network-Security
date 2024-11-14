#include"Rail_Fence_Encrypt.h"
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

        // Di chuyển "zic-zắc" giữa các dòng
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
    int numRails;

    // Nhập bản rõ và số dòng (rails)
    std::cout << "Nhập bản rõ: ";
    std::getline(std::cin, plainText);

    std::cout << "Nhập số dòng (rails): ";
    std::cin >> numRails;

    // Mã hóa bản rõ và in ra kết quả
    std::string encryptedText = railFenceEncrypt(plainText, numRails);
    std::cout << "Bản mã sau khi mã hóa Rail Fence: " << encryptedText << std::endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <cctype> // Để sử dụng isalpha

// // Hàm mã hóa Rail Fence
// std::string railFenceEncrypt(const std::string& plainText, int numRails) {
//     if (numRails == 1) return plainText;  // Nếu chỉ có 1 rail, không có sự thay đổi gì

//     std::vector<std::string> rails(numRails);
//     int rail = 0;
//     bool directionDown = true;

//     // Xếp các ký tự vào các dòng (rails), bỏ qua ký tự không phải chữ cái
//     for (char c : plainText) {
//         if (std::isalpha(c)) {  // Chỉ xếp các ký tự chữ cái vào rails
//             rails[rail] += c;

//             if (rail == 0) {
//                 directionDown = true;  // Di chuyển xuống
//             } else if (rail == numRails - 1) {
//                 directionDown = false; // Di chuyển lên
//             }

//             // Di chuyển "zic-zắc" giữa các dòng
//             rail += directionDown ? 1 : -1;
//         }
//     }

//     // Đọc từng dòng theo thứ tự từ trên xuống dưới để tạo ra bản mã
//     std::string encryptedText;
//     for (const auto& row : rails) {
//         encryptedText += row;
//     }

//     return encryptedText;
// }

// int main() {
//     std::string plainText;
//     int numRails;

//     // Nhập bản rõ và số dòng (rails)
//     std::cout << "Nhập bản rõ: ";
//     std::getline(std::cin, plainText);

//     std::cout << "Nhập số dòng (rails): ";
//     std::cin >> numRails;

//     // Mã hóa bản rõ và in ra kết quả
//     std::string encryptedText = railFenceEncrypt(plainText, numRails);
//     std::cout << "Bản mã sau khi mã hóa Rail Fence: " << encryptedText << std::endl;

//     return 0;
// }