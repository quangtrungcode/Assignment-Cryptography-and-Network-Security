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
    
//     // Duyệt qua các ký tự trong văn bản và tách thành các từ
//     for (char c : text) {
//         if (std::isalpha(c)) {
//             word += std::tolower(c); // Tạo từ trong suốt quá trình duyệt văn bản
//         } else {
//             if (!word.empty() && dictionary.find(word) != dictionary.end()) {
//                 ++validWords;  // Kiểm tra nếu từ hợp lệ trong từ điển
//             }
//             word.clear();  // Reset từ khi gặp dấu cách hoặc ký tự không phải chữ
//         }
//     }
    
//     // Kiểm tra từ cuối nếu nó không bị kết thúc bằng dấu cách
//     if (!word.empty() && dictionary.find(word) != dictionary.end()) {
//         ++validWords;
//     }

//     return validWords;
// }

// // Hàm giải mã Rail Fence
// std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
//     int len = encryptedText.length();
//     std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
//     std::vector<int> railPattern(len, -1);

//     int currentRail = 0;
//     bool goingDown = false;
//     for (int i = 0; i < len; ++i) {
//         railPattern[i] = currentRail;
//         if (currentRail == 0 || currentRail == numRails - 1)
//             goingDown = !goingDown;
//         currentRail += (goingDown ? 1 : -1);
//     }

//     int index = 0;
//     for (int r = 0; r < numRails; ++r) {
//         for (int i = 0; i < len; ++i) {
//             if (railPattern[i] == r) {
//                 rails[r][i] = encryptedText[index++];
//             }
//         }
//     }

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

//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     int bestNumRails = 2;
//     int maxValidWords = 0;
//     std::string bestDecryptedText;

//     for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
//         std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
//         int validWords = countValidWords(decryptedText, dictionary);

//         std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText 
//                   << " (Từ hợp lệ: " << validWords << ")" << std::endl;

//         if (validWords > maxValidWords) {
//             maxValidWords = validWords;
//             bestNumRails = numRails;
//             bestDecryptedText = decryptedText;
//         }
//     }

//     std::cout << "\nBản rõ có khả năng đúng nhất với " << bestNumRails 
//               << " dòng: " << bestDecryptedText << std::endl;

//     return 0;
// } 

// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <vector>
// #include <thread>
// #include <mutex>
// #include <string>
// #include <sstream>
// #include <algorithm>
// #include <cctype>

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

// // Hàm tìm tất cả các từ hợp lệ trong một chuỗi
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     for (size_t len = 1; len <= text.size(); ++len) {
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             std::string word = text.substr(i, len);
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Chuyển thành chữ thường
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;  // Nếu từ có trong từ điển, tăng số lượng từ hợp lệ
//             }
//         }
//     }
//     return count;
// }

// // Hàm giải mã Rail Fence
// std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
//     int len = encryptedText.length();
//     std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
//     std::vector<int> railPattern(len, -1);

//     int currentRail = 0;
//     bool goingDown = false;
//     for (int i = 0; i < len; ++i) {
//         railPattern[i] = currentRail;
//         if (currentRail == 0 || currentRail == numRails - 1)
//             goingDown = !goingDown;
//         currentRail += (goingDown ? 1 : -1);
//     }

//     int index = 0;
//     for (int r = 0; r < numRails; ++r) {
//         for (int i = 0; i < len; ++i) {
//             if (railPattern[i] == r) {
//                 rails[r][i] = encryptedText[index++];
//             }
//         }
//     }

//     std::string decryptedText;
//     for (int i = 0; i < len; ++i) {
//         decryptedText += rails[railPattern[i]][i];
//     }

//     return decryptedText;
// }

// // Biến toàn cục cho kết quả tốt nhất
// std::mutex mtx;
// int maxValidWords = 0;
// std::vector<std::pair<int, std::string>> bestDecryptedTexts;  // Lưu tất cả các bản rõ có số từ hợp lệ bằng nhau và số dòng

// void findBestDecryption(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, int startRail, int endRail) {
//     for (int numRails = startRail; numRails <= endRail; ++numRails) {
//         std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
//         int validWords = findValidWords(decryptedText, dictionary);

//         // In ra kết quả cho mỗi thử nghiệm
//         std::lock_guard<std::mutex> lock(mtx);
//         std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText 
//                   << " (Từ hợp lệ: " << validWords << ")" << std::endl;

//         if (validWords > maxValidWords) {
//             // Nếu có số từ hợp lệ cao hơn, cập nhật lại
//             maxValidWords = validWords;
//             bestDecryptedTexts.clear();  // Xóa danh sách cũ
//             bestDecryptedTexts.push_back({numRails, decryptedText});  // Lưu kết quả mới cùng với số dòng
//         } else if (validWords == maxValidWords) {
//             // Nếu số từ hợp lệ bằng nhau, thêm vào danh sách
//             bestDecryptedTexts.push_back({numRails, decryptedText});
//         }
//     }
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Rail Fence: ";
//     std::getline(std::cin, encryptedText);

//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     int numThreads = 4;
//     int maxRails = encryptedText.length();
//     int railsPerThread = maxRails / numThreads;
//     int remainder = maxRails % numThreads;

//     std::vector<std::thread> threads;
//     int startRail = 2;

//     // Chia số dòng cho từng thread
//     for (int i = 0; i < numThreads; ++i) {
//         int endRail = startRail + railsPerThread - 1;
//         if (i == numThreads - 1) {  // Thread cuối cùng xử lý phần còn lại
//             endRail += remainder;
//         }

//         threads.push_back(std::thread(findBestDecryption, encryptedText, std::ref(dictionary), startRail, endRail));
//         startRail = endRail + 1;
//     }

//     for (auto& t : threads) {
//         t.join();
//     }

//     // In kết quả các bản rõ có số từ hợp lệ cao nhất cùng với số dòng
//     std::cout << "\nCác bản rõ có số từ hợp lệ cao nhất (" << maxValidWords << " từ hợp lệ):\n";
//     for (const auto& result : bestDecryptedTexts) {
//         std::cout << "Sử dụng " << result.first << " dòng: " << result.second << std::endl;
//     }

//     return 0;
// }






// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <vector>
// #include <thread>
// #include <mutex>
// #include <string>
// #include <sstream>
// #include <algorithm>
// #include <cctype>

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

// // Hàm tìm tất cả các từ hợp lệ trong một chuỗi
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     for (size_t len = 1; len <= text.size(); ++len) {
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             std::string word = text.substr(i, len);
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Chuyển thành chữ thường
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;  // Nếu từ có trong từ điển, tăng số lượng từ hợp lệ
//             }
//         }
//     }
//     return count;
// }

// // Hàm giải mã Rail Fence (không bỏ qua ký tự không phải chữ cái)
// std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
//     int len = encryptedText.length();
//     std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
//     std::vector<int> railPattern(len, -1);

//     // Xác định mô hình đường ray
//     int currentRail = 0;
//     bool goingDown = false;
//     for (int i = 0; i < len; ++i) {
//         railPattern[i] = currentRail;
//         if (currentRail == 0 || currentRail == numRails - 1)
//             goingDown = !goingDown;
//         currentRail += (goingDown ? 1 : -1);
//     }

//     // Điền các ký tự vào các đường ray theo thứ tự của bản mã
//     int index = 0;
//     for (int r = 0; r < numRails; ++r) {
//         for (int i = 0; i < len; ++i) {
//             if (railPattern[i] == r) {
//                 rails[r][i] = encryptedText[index++];
//             }
//         }
//     }

//     // Xây dựng chuỗi giải mã từ các đường ray
//     std::string decryptedText;
//     for (int i = 0; i < len; ++i) {
//         decryptedText += rails[railPattern[i]][i];
//     }

//     return decryptedText;
// }

// // Biến toàn cục cho kết quả tốt nhất
// std::mutex mtx;
// int maxValidWords = 0;
// std::vector<std::pair<int, std::string>> bestDecryptedTexts;

// void findBestDecryption(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, int startRail, int endRail) {
//     for (int numRails = startRail; numRails <= endRail; ++numRails) {
//         std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
//         int validWords = findValidWords(decryptedText, dictionary);

//         std::lock_guard<std::mutex> lock(mtx);
//         std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText 
//                   << " (Từ hợp lệ: " << validWords << ")" << std::endl;

//         if (validWords > maxValidWords) {
//             maxValidWords = validWords;
//             bestDecryptedTexts.clear();
//             bestDecryptedTexts.push_back({numRails, decryptedText});
//         } else if (validWords == maxValidWords) {
//             bestDecryptedTexts.push_back({numRails, decryptedText});
//         }
//     }
// }

// int main() {
//          auto programStart = std::chrono::high_resolution_clock::now();
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Rail Fence: ";
//     std::getline(std::cin, encryptedText);

//     std::unordered_set<std::string> dictionary = loadDictionary("Src/dictionary.txt");

//     int numThreads = 4;
//     int maxRails = encryptedText.length();
//     int railsPerThread = maxRails / numThreads;
//     int remainder = maxRails % numThreads;

//     std::vector<std::thread> threads;
//     int startRail = 2;

//     for (int i = 0; i < numThreads; ++i) {
//         int endRail = startRail + railsPerThread - 1;
//         if (i == numThreads - 1) {
//             endRail += remainder;
//         }

//         threads.push_back(std::thread(findBestDecryption, encryptedText, std::ref(dictionary), startRail, endRail));
//         startRail = endRail + 1;
//     }

//     for (auto& t : threads) {
//         t.join();
//     }

//     std::cout << "\nCác bản rõ có số từ hợp lệ cao nhất (" << maxValidWords << " từ hợp lệ):\n";
//     for (const auto& result : bestDecryptedTexts) {
//         std::cout << "Sử dụng " << result.first << " dòng: " << result.second << std::endl;
//     }
//     auto programEnd = std::chrono::high_resolution_clock::now();
//     auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

//     std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <omp.h>
#include <chrono> 
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

    const int maxWordLength = 15;
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

// std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
//     int len = encryptedText.length();
//     std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
//     std::vector<int> railPattern(len, -1);

//     int currentRail = 0;
//     bool goingDown = false;
//     for (int i = 0; i < len; ++i) {
//         railPattern[i] = currentRail;
//         if (currentRail == 0 || currentRail == numRails - 1)
//             goingDown = !goingDown;
//         currentRail += (goingDown ? 1 : -1);
//     }

//     int index = 0;
//     for (int r = 0; r < numRails; ++r) {
//         for (int i = 0; i < len; ++i) {
//             if (railPattern[i] == r) {
//                 rails[r][i] = encryptedText[index++];
//             }
//         }
//     }

//     std::string decryptedText;
//     for (int i = 0; i < len; ++i) {
//         decryptedText += rails[railPattern[i]][i];
//     }

//     return decryptedText;
// }

std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
    int len = encryptedText.length();
    std::vector<int> railPattern(len, -1);
    std::vector<std::string> rails(numRails); // Chỉ cần lưu chuỗi thay vì ma trận

    // Tạo mẫu đường ray
    int currentRail = 0;
    bool goingDown = false;
    for (int i = 0; i < len; ++i) {
        railPattern[i] = currentRail;
        if (currentRail == 0 || currentRail == numRails - 1)
            goingDown = !goingDown;
        currentRail += (goingDown ? 1 : -1);
    }

    // Xác định số lượng ký tự trên mỗi đường ray
    std::vector<int> railLengths(numRails, 0);
    for (int r : railPattern) {
        railLengths[r]++;
    }

    // Chia các ký tự vào các đường ray
    int index = 0;
    for (int r = 0; r < numRails; ++r) {
        rails[r] = encryptedText.substr(index, railLengths[r]);
        index += railLengths[r];
    }

    // Xây dựng chuỗi giải mã
    std::string decryptedText;
    std::vector<int> railIndices(numRails, 0); // Chỉ số hiện tại cho từng đường ray
    for (int i = 0; i < len; ++i) {
        int r = railPattern[i];
        decryptedText += rails[r][railIndices[r]++];
    }

    return decryptedText;
}

void findBestDecryption(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary, 
                        int startRail, int endRail, int& maxValidWords, std::vector<std::pair<int, std::string>>& bestDecryptedTexts) {
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel for
    for (int numRails = startRail; numRails <= endRail; ++numRails) {
        std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
        int validWords = findValidWords(decryptedText, dictionary);

        // In kết quả của từng trường hợp
        #pragma omp critical
        {
            std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText 
                      << " (Từ hợp lệ: " << validWords << ")" << std::endl;
        }

        // Cập nhật kết quả tốt nhất
        omp_set_lock(&lock);
        if (validWords > maxValidWords) {
            maxValidWords = validWords;
            bestDecryptedTexts.clear();
            bestDecryptedTexts.push_back({numRails, decryptedText});
        } else if (validWords == maxValidWords) {
            bestDecryptedTexts.push_back({numRails, decryptedText});
        }
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
}

int main() {
    auto programStart = std::chrono::high_resolution_clock::now();
    std::string encryptedText;
    std::cout << "Nhập bản mã Rail Fence: ";
    std::getline(std::cin, encryptedText);

    std::unordered_set<std::string> dictionary = loadDictionary("Src/dictionary.txt");

    int maxRails = encryptedText.length();
    int maxValidWords = 0;
    std::vector<std::pair<int, std::string>> bestDecryptedTexts;
    
    findBestDecryption(encryptedText, dictionary, 2, maxRails, maxValidWords, bestDecryptedTexts);
    
    std::cout << "\nCác bản rõ có số từ hợp lệ cao nhất (" << maxValidWords << " từ hợp lệ):\n";
    for (const auto& result : bestDecryptedTexts) {
        std::cout << "Sử dụng " << result.first << " dòng: " << result.second << std::endl;
    }

    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
    return 0;
}

