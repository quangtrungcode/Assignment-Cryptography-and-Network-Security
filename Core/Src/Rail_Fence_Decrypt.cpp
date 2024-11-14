#include"Rail_Fence_Decrypt.h"
// std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
//     int len = encryptedText.length();
//     std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
//     std::vector<int> railPattern(len, -1);

//     // Bước 1: Xác định vị trí của từng ký tự trong chuỗi mã hóa theo mô hình zigzag.
//     int currentRail = 0;
//     bool goingDown = false;
//     for (int i = 0; i < len; ++i) {
//         railPattern[i] = currentRail;
//         if (currentRail == 0 || currentRail == numRails - 1)
//             goingDown = !goingDown;
//         currentRail += (goingDown ? 1 : -1);
//     }

//     // Bước 2: Xây dựng các rails từ bản mã đã cho
//     int index = 0;
//     for (int r = 0; r < numRails; ++r) {
//         for (int i = 0; i < len; ++i) {
//             if (railPattern[i] == r) {
//                 rails[r][i] = encryptedText[index++];
//             }
//         }
//     }

//     // Bước 3: Đọc lại các ký tự từ các rails và phục hồi bản rõ
//     std::string decryptedText;
//     for (int i = 0; i < len; ++i) {
//         decryptedText += rails[railPattern[i]][i];
//     }

//     return decryptedText;
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Rail Fence: ";
//     std::getline(std::cin, encryptedText);

//     // Thử giải mã với các số dòng từ 2 đến 10
//     for (int numRails = 2; numRails <= 9; ++numRails) {
//         std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
//         std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText << std::endl;
//     }

//     return 0;
// }


std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(dictionaryFile);
    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Đảm bảo từ trong từ điển là chữ thường
        dictionary.insert(word);
    }
    return dictionary;
}

// Hàm kiểm tra số lượng từ hợp lệ trong bản rõ
int countValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int validWords = 0;
    std::string word;
    
    // Duyệt qua các ký tự trong văn bản và tách thành các từ
    for (char c : text) {
        if (std::isalpha(c)) {
            word += std::tolower(c); // Tạo từ trong suốt quá trình duyệt văn bản
        } else {
            if (!word.empty() && dictionary.find(word) != dictionary.end()) {
                ++validWords;  // Kiểm tra nếu từ hợp lệ trong từ điển
            }
            word.clear();  // Reset từ khi gặp dấu cách hoặc ký tự không phải chữ
        }
    }
    
    // Kiểm tra từ cuối nếu nó không bị kết thúc bằng dấu cách
    if (!word.empty() && dictionary.find(word) != dictionary.end()) {
        ++validWords;
    }

    return validWords;
}

// Hàm giải mã Rail Fence
std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
    int len = encryptedText.length();
    std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
    std::vector<int> railPattern(len, -1);

    int currentRail = 0;
    bool goingDown = false;
    for (int i = 0; i < len; ++i) {
        railPattern[i] = currentRail;
        if (currentRail == 0 || currentRail == numRails - 1)
            goingDown = !goingDown;
        currentRail += (goingDown ? 1 : -1);
    }

    int index = 0;
    for (int r = 0; r < numRails; ++r) {
        for (int i = 0; i < len; ++i) {
            if (railPattern[i] == r) {
                rails[r][i] = encryptedText[index++];
            }
        }
    }

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

    std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

    int bestNumRails = 2;
    int maxValidWords = 0;
    std::string bestDecryptedText;

    for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
        std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
        int validWords = countValidWords(decryptedText, dictionary);

        std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText 
                  << " (Từ hợp lệ: " << validWords << ")" << std::endl;

        if (validWords > maxValidWords) {
            maxValidWords = validWords;
            bestNumRails = numRails;
            bestDecryptedText = decryptedText;
        }
    }

    std::cout << "\nBản rõ có khả năng đúng nhất với " << bestNumRails 
              << " dòng: " << bestDecryptedText << std::endl;

    return 0;
} 