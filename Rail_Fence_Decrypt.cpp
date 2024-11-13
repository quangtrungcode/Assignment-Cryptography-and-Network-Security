#include"Rail_Fence_Decrypt.h"
std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
    int len = encryptedText.length();
    std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
    std::vector<int> railPattern(len, -1);

    // Bước 1: Xác định vị trí của từng ký tự trong chuỗi mã hóa theo mô hình zigzag.
    int currentRail = 0;
    bool goingDown = false;
    for (int i = 0; i < len; ++i) {
        railPattern[i] = currentRail;
        if (currentRail == 0 || currentRail == numRails - 1)
            goingDown = !goingDown;
        currentRail += (goingDown ? 1 : -1);
    }

    // Bước 2: Xây dựng các rails từ bản mã đã cho
    int index = 0;
    for (int r = 0; r < numRails; ++r) {
        for (int i = 0; i < len; ++i) {
            if (railPattern[i] == r) {
                rails[r][i] = encryptedText[index++];
            }
        }
    }

    // Bước 3: Đọc lại các ký tự từ các rails và phục hồi bản rõ
    std::string decryptedText;
    for (int i = 0; i < len; ++i) {
        decryptedText += rails[railPattern[i]][i];
    }

    return decryptedText;
}

int main() {
    std::string encryptedText;
    std::cout << "Nhập bản mã Rail Fence: ";
    std::getline(std::cin, encryptedText);

    // Thử giải mã với các số dòng từ 2 đến 10
    for (int numRails = 2; numRails <= 10; ++numRails) {
        std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
        std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText << std::endl;
    }

    return 0;
}