#include"Caesar_Decrypt.h"
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

// Hàm kiểm tra số lượng từ hợp lệ trong bản rõ
int countValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int validWords = 0;
    std::string word;
    std::istringstream stream(text);
    
    // Duyệt qua từng từ trong bản rõ (người dùng có thể tách các từ bằng khoảng trắng hoặc dấu phân cách)
    while (stream >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Đảm bảo từ là chữ thường
        if (dictionary.find(word) != dictionary.end()) {
            ++validWords;  // Nếu từ hợp lệ trong từ điển, tăng số lượng từ hợp lệ
        }
    }

    return validWords;
}

// Hàm giải mã Caesar cho một ký tự
char caesarDecryptChar(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' - key + 26) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a' - key + 26) % 26 + 'a';
    } else {
        return c;
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

// Hàm thử tất cả các khóa và kiểm tra bản rõ
void bruteForceCaesarDecrypt(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
    std::cout << "Thử tất cả các khóa (0-25):" << std::endl;
    int bestKey = 0;
    int maxValidWords = 0;
    std::string bestDecryptedText;

    for (int key = 0; key < 26; ++key) {
        std::string decryptedText = caesarDecrypt(encryptedText, key);
        int validWords = countValidWords(decryptedText, dictionary);
        
        std::cout << "Khóa " << key << ": " << decryptedText << " (Từ hợp lệ: " << validWords << ")" << std::endl;

        // Lưu bản rõ với số từ hợp lệ cao nhất
        if (validWords > maxValidWords) {
            maxValidWords = validWords;
            bestKey = key;
            bestDecryptedText = decryptedText;
        }
    }

    std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKey << ": " << bestDecryptedText << std::endl;
}

int main() {
    std::string encryptedText;
    std::cout << "Nhập bản mã Caesar: ";
    std::getline(std::cin, encryptedText);

    // Tải từ điển
    std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

    // Giải mã Caesar với phương pháp thử khóa và kiểm tra từ điển
    bruteForceCaesarDecrypt(encryptedText, dictionary);

    return 0;
}
