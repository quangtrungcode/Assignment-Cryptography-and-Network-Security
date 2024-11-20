#include"Caesar_Decrypt.h"
// Hàm đọc từ điển từ file vào unordered_set
// std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
//     std::unordered_set<std::string> dictionary;
//     std::ifstream file(dictionaryFile);
//     std::string word;
//     while (file >> word) {
//         std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Đảm bảo từ trong từ điển là chữ thường
//         dictionary.insert(word);
//     }
//     return dictionary;
// }

// // Hàm kiểm tra số lượng từ hợp lệ trong bản rõ
// int countValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int validWords = 0;
//     std::string word;
//     std::istringstream stream(text);
    
//     // Duyệt qua từng từ trong bản rõ (người dùng có thể tách các từ bằng khoảng trắng hoặc dấu phân cách)
//     while (stream >> word) {
//         std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Đảm bảo từ là chữ thường
//         if (dictionary.find(word) != dictionary.end()) {
//             ++validWords;  // Nếu từ hợp lệ trong từ điển, tăng số lượng từ hợp lệ
//         }
//     }

//     return validWords;
// }

// // Hàm giải mã Caesar cho một ký tự
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';
//     } else {
//         return c;
//     }
// }

// // Hàm giải mã Caesar cho chuỗi
// std::string caesarDecrypt(const std::string& encryptedText, int key) {
//     std::string decryptedText;
//     for (char c : encryptedText) {
//         decryptedText += caesarDecryptChar(c, key);
//     }
//     return decryptedText;
// }

// // Hàm thử tất cả các khóa và kiểm tra bản rõ
// void bruteForceCaesarDecrypt(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     std::cout << "Thử tất cả các khóa (0-25):" << std::endl;
//     int bestKey = 0;
//     int maxValidWords = 0;
//     std::string bestDecryptedText;

//     for (int key = 0; key < 26; ++key) {
//         std::string decryptedText = caesarDecrypt(encryptedText, key);
//         int validWords = countValidWords(decryptedText, dictionary);
        
//         std::cout << "Khóa " << key << ": " << decryptedText << " (Từ hợp lệ: " << validWords << ")" << std::endl;

//         // Lưu bản rõ với số từ hợp lệ cao nhất
//         if (validWords > maxValidWords) {
//             maxValidWords = validWords;
//             bestKey = key;
//             bestDecryptedText = decryptedText;
//         }
//     }

//     std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKey << ": " << bestDecryptedText << std::endl;
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Caesar: ";
//     std::getline(std::cin, encryptedText);

//     // Tải từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     // Giải mã Caesar với phương pháp thử khóa và kiểm tra từ điển
//     bruteForceCaesarDecrypt(encryptedText, dictionary);

//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <string>
// #include <algorithm>
// #include <sstream>

// // Hàm tải từ điển từ file vào unordered_set
// std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
//     std::unordered_set<std::string> dictionary;
//     std::ifstream file(dictionaryFile);
//     std::string word;
//     while (file >> word) {
//         std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//         dictionary.insert(word);
//     }
//     return dictionary;
// }

// // Hàm giải mã Caesar cho một ký tự
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';
//     } else {
//         return c;
//     }
// }

// // Hàm giải mã Caesar cho chuỗi
// std::string caesarDecrypt(const std::string& encryptedText, int key) {
//     std::string decryptedText;
//     for (char c : encryptedText) {
//         decryptedText += caesarDecryptChar(c, key);
//     }
//     return decryptedText;
// }

// // Hàm tìm từ đơn lẻ
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     for (size_t len = 1; len <= text.size(); ++len) {
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             std::string word = text.substr(i, len);
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// // Hàm thử tất cả các khóa và tìm bản rõ có khả năng đúng nhất
// void bruteForceCaesarDecrypt(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     int bestKey = 0;
//     int maxValidWords = 0;
//     std::string bestDecryptedText;

//     for (int key = 0; key < 26; ++key) {
//         std::string decryptedText = caesarDecrypt(encryptedText, key);
//         int validWords = findValidWords(decryptedText, dictionary);

//         std::cout << "Khóa " << key << ": " << decryptedText << " (Từ hợp lệ: " << validWords << ")" << std::endl;

//         if (validWords > maxValidWords) {
//             maxValidWords = validWords;
//             bestKey = key;
//             bestDecryptedText = decryptedText;
//         }
//     }

//     std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKey << ": " << bestDecryptedText << std::endl;
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Caesar: ";
//     std::getline(std::cin, encryptedText);

//     // Tải từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     // Giải mã Caesar với phân tích từ
//     bruteForceCaesarDecrypt(encryptedText, dictionary);

//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <string>
// #include <algorithm>
// #include <sstream>
// #include <thread>
// #include <vector>
// #include <mutex>
// #include <chrono>
// // Tải từ điển từ file
// std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
//     std::unordered_set<std::string> dictionary;
//     std::ifstream file(dictionaryFile);
//     std::string word;
//     while (file >> word) {
//         std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//         dictionary.insert(word);
//     }
//     return dictionary;
// }

// // Giải mã Caesar cho một ký tự
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';
//     } else {
//         return c;
//     }
// }

// // Giải mã Caesar cho chuỗi
// std::string caesarDecrypt(const std::string& encryptedText, int key) {
//     std::string decryptedText;
//     for (char c : encryptedText) {
//         decryptedText += caesarDecryptChar(c, key);
//     }
//     return decryptedText;
// }

// // Kiểm tra từ đơn lẻ trong chuỗi giải mã được
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     for (size_t len = 1; len <= text.size(); ++len) {
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             std::string word = text.substr(i, len);
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// // Biến toàn cục để lưu bản rõ có khả năng đúng nhất
// std::mutex resultMutex;
// int globalMaxValidWords = 0;
// std::string bestDecryptedTextGlobal;
// int bestKeyGlobal = 0;

// // Hàm để mỗi thread xử lý một nhóm khóa
// void decryptRange(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, int startKey, int endKey) {
//     int localMaxValidWords = 0;
//     int localBestKey = startKey;
//     std::string localBestDecryptedText;

//     for (int key = startKey; key <= endKey; ++key) {
//         std::string decryptedText = caesarDecrypt(encryptedText, key);
//         int validWords = findValidWords(decryptedText, dictionary);

//         {
//             // Đồng bộ hóa khi in kết quả
//             std::lock_guard<std::mutex> lock(resultMutex);
//             std::cout << "Khóa " << key << ": " << decryptedText << " (Từ hợp lệ: " << validWords << ")" << std::endl;
//         }

//         if (validWords > localMaxValidWords) {
//             localMaxValidWords = validWords;
//             localBestKey = key;
//             localBestDecryptedText = decryptedText;
//         }
//     }

//     // Cập nhật kết quả toàn cục nếu cần thiết
//     std::lock_guard<std::mutex> lock(resultMutex);
//     if (localMaxValidWords > globalMaxValidWords) {
//         globalMaxValidWords = localMaxValidWords;
//         bestDecryptedTextGlobal = localBestDecryptedText;
//         bestKeyGlobal = localBestKey;
//     }
// }

// int main() {
//     auto programStart = std::chrono::high_resolution_clock::now();
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Caesar: ";
//     std::getline(std::cin, encryptedText);

//     // Tải từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     // Khởi tạo các thread để xử lý giải mã song song
//     const int numThreads = 4;  // Số lượng thread (có thể thay đổi tùy theo số nhân CPU)
//     int keysPerThread = 26 / numThreads;
//     std::vector<std::thread> threads;

//     for (int i = 0; i < numThreads; ++i) {
//         int startKey = i * keysPerThread;
//         int endKey = (i == numThreads - 1) ? 25 : (startKey + keysPerThread - 1);
//         threads.emplace_back(decryptRange, std::cref(encryptedText), std::cref(dictionary), startKey, endKey);
//     }

//     // Chờ tất cả các thread hoàn tất
//     for (auto& t : threads) {
//         t.join();
//     }

//     // Kết quả giải mã tốt nhất
//     std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKeyGlobal << ": " << bestDecryptedTextGlobal << std::endl;
//   auto programEnd = std::chrono::high_resolution_clock::now();
//     auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

//     std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <string>
// #include <algorithm>
// #include <sstream>
// #include <omp.h>  // Thư viện OpenMP
// #include <chrono>
// // Tải từ điển từ file
// std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
//     std::unordered_set<std::string> dictionary;
//     std::ifstream file(dictionaryFile);
//     std::string word;
//     while (file >> word) {
//         std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//         dictionary.insert(word);
//     }
//     return dictionary;
// }

// // Giải mã Caesar cho một ký tự
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';
//     } else {
//         return c;
//     }
// }

// // Giải mã Caesar cho chuỗi
// std::string caesarDecrypt(const std::string& encryptedText, int key) {
//     std::string decryptedText;
//     for (char c : encryptedText) {
//         decryptedText += caesarDecryptChar(c, key);
//     }
//     return decryptedText;
// }

// // Kiểm tra từ đơn lẻ trong chuỗi giải mã được
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     for (size_t len = 1; len <= text.size(); ++len) {
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             std::string word = text.substr(i, len);
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// // Biến toàn cục để lưu bản rõ có khả năng đúng nhất
// int globalMaxValidWords = 0;
// std::string bestDecryptedTextGlobal;
// int bestKeyGlobal = 0;

// // Hàm tìm bản rõ tốt nhất cho một nhóm khóa
// void decryptRange(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, int startKey, int endKey) {
//     int localMaxValidWords = 0;
//     int localBestKey = startKey;
//     std::string localBestDecryptedText;

//     for (int key = startKey; key <= endKey; ++key) {
//         std::string decryptedText = caesarDecrypt(encryptedText, key);
//         int validWords = findValidWords(decryptedText, dictionary);

//         // In kết quả trong vòng lặp song song
//         std::cout << "Khóa " << key << ": " << decryptedText << " (Từ hợp lệ: " << validWords << ")" << std::endl;

//         if (validWords > localMaxValidWords) {
//             localMaxValidWords = validWords;
//             localBestKey = key;
//             localBestDecryptedText = decryptedText;
//         }
//     }

//     // Cập nhật kết quả toàn cục nếu cần thiết
//     #pragma omp critical
//     {
//         if (localMaxValidWords > globalMaxValidWords) {
//             globalMaxValidWords = localMaxValidWords;
//             bestDecryptedTextGlobal = localBestDecryptedText;
//             bestKeyGlobal = localBestKey;
//         }
//     }
// }

// int main() {
//          auto programStart = std::chrono::high_resolution_clock::now();
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Caesar: ";
//     std::getline(std::cin, encryptedText);

//     // Tải từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     // Sử dụng OpenMP để giải mã song song
//     const int numThreads = 4;  // Số lượng thread (có thể thay đổi tùy theo số nhân CPU)

//     #pragma omp parallel for num_threads(numThreads)
//     for (int i = 0; i < numThreads; ++i) {
//         int keysPerThread = 26 / numThreads;
//         int startKey = i * keysPerThread;
//         int endKey = (i == numThreads - 1) ? 25 : (startKey + keysPerThread - 1);
//         decryptRange(encryptedText, dictionary, startKey, endKey);
//     }

//     // Kết quả giải mã tốt nhất
//     std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKeyGlobal << ": " << bestDecryptedTextGlobal << std::endl;
//   auto programEnd = std::chrono::high_resolution_clock::now();
//     auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

//     std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <omp.h>

// Tải từ điển từ file
std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(dictionaryFile);
    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        dictionary.insert(word);
    }
    return dictionary;
}

// Giải mã Caesar cho một ký tự
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';
//     } else {
//         return c;
//     }
// }

// // Giải mã Caesar cho chuỗi
// std::string caesarDecrypt(const std::string& encryptedText, int key) {
//     std::string decryptedText;
//     for (char c : encryptedText) {
//         decryptedText += caesarDecryptChar(c, key);
//     }
//     return decryptedText;
// }

std::string caesarDecrypt(const std::string& text, int shift) {
    std::string decryptedText = text;
   // #pragma omp parallel for
    for (char& c : decryptedText) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return decryptedText;
}

// Kiểm tra từ đơn lẻ trong chuỗi giải mã được
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     for (size_t len = 1; len <= text.size(); ++len) {
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             std::string word = text.substr(i, len);
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int count = 0;
    std::string lowerText = text;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);

    const int maxWordLength = 20;
    size_t textLength = lowerText.size();

    // Tạo một biến cục bộ cho mỗi luồng để lưu trữ số lượng từ hợp lệ tìm được
    int localCount = 0;

    #pragma omp parallel for reduction(+:localCount)
    for (size_t len = 1; len <= std::min(static_cast<std::size_t>(maxWordLength), textLength); ++len) {
        // Duyệt qua tất cả các chuỗi con với chiều dài len
        for (size_t i = 0; i + len <= textLength; ++i) {
            std::string word = lowerText.substr(i, len);
            if (dictionary.find(word) != dictionary.end()) {
                localCount++;  // Tăng đếm nếu từ có trong từ điển
            }
        }
    }

    // Cập nhật biến count toàn cục từ biến cục bộ
    count += localCount;

    return count;
}
// Biến toàn cục để lưu kết quả tốt nhất
int globalMaxValidWords = 0;
std::string bestDecryptedTextGlobal;
int bestKeyGlobal = 0;

// Hàm giải mã song song với OpenMP
void bruteForceCaesarDecrypt(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
    #pragma omp parallel for
    for (int key = 0; key < 26; ++key) {
        std::string decryptedText = caesarDecrypt(encryptedText, key);
        int validWords = findValidWords(decryptedText, dictionary);

        // In ra kết quả của từng khóa
        #pragma omp critical
        {
            std::cout << "Khóa " << key << ": " << decryptedText << " -> Số từ hợp lệ: " << validWords << std::endl;

            // Cập nhật kết quả tốt nhất
            if (validWords > globalMaxValidWords) {
                globalMaxValidWords = validWords;
                bestDecryptedTextGlobal = decryptedText;
                bestKeyGlobal = key;
            }
        }
    }
}

int main() {
    auto programStart = std::chrono::high_resolution_clock::now();

    std::string encryptedText;
    std::cout << "Nhập bản mã Caesar: ";
    std::getline(std::cin, encryptedText);

    // Tải từ điển
    std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

    // Giải mã Caesar với OpenMP
    bruteForceCaesarDecrypt(encryptedText, dictionary);

    // Kết quả giải mã tốt nhất
    std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKeyGlobal << ": " << bestDecryptedTextGlobal << std::endl;

    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
    return 0;
}


