#include"Caesar_Rail_Fence_Decrypt.h"


// Giải mã Rail Fence Cipher
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

// Giải mã Caesar Cipher
std::string caesarDecrypt(const std::string& text, int shift) {
    std::string decryptedText = text;
    for (char& c : decryptedText) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return decryptedText;
}

// Hàm đọc từ điển từ file vào unordered_set
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

// Kiểm tra số lượng từ hợp lệ trong bản rõ
int countValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int validWords = 0;
    std::string word;

    // Duyệt qua các ký tự trong văn bản và tách thành các từ
    for (char c : text) {
        if (std::isalpha(c)) {
            word += std::tolower(c);
        } else {
            if (!word.empty() && dictionary.find(word) != dictionary.end()) {
                ++validWords;
            }
            word.clear();
        }
    }

    // Kiểm tra từ cuối nếu nó không bị kết thúc bằng dấu cách
    if (!word.empty() && dictionary.find(word) != dictionary.end()) {
        ++validWords;
    }

    return validWords;
}

// Giải mã toàn bộ quy trình (Rail Fence + Caesar)
std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
    int bestValidWords = 0;
    std::string bestDecryptedText;

    // Bước 1: Giải mã Rail Fence (thử tất cả số đường ray từ 2 đến độ dài của bản mã)
    for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
        std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);

        // Bước 2: Giải mã Caesar (thử tất cả các shift từ 1 đến 25)
        for (int shift = 1; shift < 26; ++shift) {
            std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
            int validWords = countValidWords(caesarDecryptedText, dictionary);

            if (validWords > bestValidWords) {
                bestValidWords = validWords;
                bestDecryptedText = caesarDecryptedText;
            }
        }
    }

    return bestDecryptedText;
}

int main() {
    // Đọc từ điển
    std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

    // Bản mã (có thể thay đổi tùy theo bài toán)
    std::string encryptedText;
    
    // Yêu cầu người dùng nhập bản mã từ bàn phím
    std::cout << "Nhập bản mã: ";
    std::getline(std::cin, encryptedText);  // Đọc chuỗi từ bàn phím

    // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
    std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

    // Hiển thị bản rõ đã giải mã
    std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;

    return 0;
}
