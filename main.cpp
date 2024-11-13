// mã hóa Casear
// #include <iostream>
// #include <string>
#include"Caesar_Encrypt.h"
#include"Rail_Fence_Encrypt.h"
#include"Caesar_Rail_Fence_Encrypt.h"
#include"Caesar_Decrypt.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <sstream> // Thư viện cho istringstream
#include <algorithm> // Thư viện cho remove_if và transform
#include <cctype> // Thư viện cho ispunct và tolower

// Hàm đọc từ điển từ file vào unordered_set

std::unordered_set<std::string> loadDictionary(const std::string& dictionaryFile) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(dictionaryFile);
    std::string word;
    while (file >> word) {
        dictionary.insert(word);
    }
    return dictionary;
}

// Hàm kiểm tra số lượng chuỗi con hợp lệ trong bản rõ
int countValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
    int validWords = 0;
    int length = text.length();

    // Kiểm tra tất cả các chuỗi con
    for (int start = 0; start < length; ++start) {
        for (int len = 1; len <= length - start; ++len) {
            std::string subStr = text.substr(start, len);

            // Chuyển chuỗi con về chữ thường
            std::transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);

            // Kiểm tra nếu chuỗi con có trong từ điển
            if (dictionary.find(subStr) != dictionary.end()) {
                ++validWords;
            }
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
    std::unordered_set<std::string> dictionary = loadDictionary("words_alpha.txt");

    // Giải mã Caesar với phương pháp thử khóa và kiểm tra từ điển
    bruteForceCaesarDecrypt(encryptedText, dictionary);

    return 0;
}



// // Hàm mã hóa Caesar cho ký tự ASCII
// char caesarChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         // Mã hóa cho chữ hoa (A-Z)
//         return (c - 'A' + key) % 26 + 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         // Mã hóa cho chữ thường (a-z)
//         return (c - 'a' + key) % 26 + 'a';
//     } else {
//         // Giữ nguyên các ký tự không phải chữ cái
//         return c;
//     }
// }

// // Hàm mã hóa Caesar cho chuỗi
// std::string caesarEncrypt(const std::string& plainText, int key) {
//     std::string encryptedText;
    
//     // Duyệt qua từng ký tự trong bản rõ và mã hóa nó
//     for (char c : plainText) {
//         encryptedText += caesarChar(c, key);
//     }
    
//     return encryptedText;
// }

// int main() {
//     std::string plainText;
//     int key;

//     cout << "Nhập bản rõ: ";
//     std::getline(std::cin, plainText);

//     std::cout << "Nhập khóa (số nguyên): ";
//     std::cin >> key;

//     // Mã hóa bản rõ và in ra kết quả
//     std::string encryptedText = caesarEncrypt(plainText, key);
//     std::cout << "Bản mã sau khi mã hóa Caesar: " << encryptedText << std::endl;

//     return 0;
// }


// mã hóa rail fence
// #include <iostream>
// #include <string>
// #include <vector>

// // Hàm mã hóa Rail Fence
// std::string railFenceEncrypt(const std::string& plainText, int numRails) {
//     if (numRails == 1) return plainText;  // Nếu chỉ có 1 rail, không có sự thay đổi gì

//     std::vector<std::string> rails(numRails);
//     int rail = 0;
//     bool directionDown = true;

//     // Xếp các ký tự vào các dòng (rails)
//     for (char c : plainText) {
//         rails[rail] += c;

//         if (rail == 0) {
//             directionDown = true;  // Di chuyển xuống
//         } else if (rail == numRails - 1) {
//             directionDown = false; // Di chuyển lên
//         }

//         // Di chuyển "zic-zắc" giữa các dòng
//         rail += directionDown ? 1 : -1;
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


// mã hóa nhân 
// #include <iostream>
// #include <string>
// #include <vector>

// // Hàm mã hóa Caesar cho ký tự ASCII
// char caesarChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' + key) % 26 + 'A';  // Mã hóa cho chữ hoa
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' + key) % 26 + 'a';  // Mã hóa cho chữ thường
//     } else {
//         return c;  // Giữ nguyên các ký tự không phải chữ cái
//     }
// }

// // Hàm mã hóa Caesar cho chuỗi
// std::string caesarEncrypt(const std::string& plainText, int key) {
//     std::string encryptedText;
//     for (char c : plainText) {
//         encryptedText += caesarChar(c, key);
//     }
//     return encryptedText;
// }

// // Hàm mã hóa Rail Fence
// std::string railFenceEncrypt(const std::string& plainText, int numRails) {
//     if (numRails == 1) return plainText;  // Nếu chỉ có 1 rail, không có sự thay đổi gì

//     std::vector<std::string> rails(numRails);
//     int rail = 0;
//     bool directionDown = true;

//     // Xếp các ký tự vào các dòng (rails)
//     for (char c : plainText) {
//         rails[rail] += c;
//         if (rail == 0) {
//             directionDown = true;  // Di chuyển xuống
//         } else if (rail == numRails - 1) {
//             directionDown = false; // Di chuyển lên
//         }
//         rail += directionDown ? 1 : -1;
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
//     int caesarKey, railKey;

//     // Nhập bản rõ, khóa Caesar và số dòng Rail Fence
//     std::cout << "Nhập bản rõ: ";
//     std::getline(std::cin, plainText);

//     std::cout << "Nhập khóa Caesar (số nguyên): ";
//     std::cin >> caesarKey;

//     std::cout << "Nhập số dòng Rail Fence: ";
//     std::cin >> railKey;

//     // Mã hóa bản rõ bằng Caesar Cipher
//     std::string caesarEncrypted = caesarEncrypt(plainText, caesarKey);
//     std::cout << "Bản mã sau khi mã hóa Caesar: " << caesarEncrypted << std::endl;

//     // Mã hóa kết quả Caesar Cipher bằng Rail Fence Cipher
//     std::string railFenceEncrypted = railFenceEncrypt(caesarEncrypted, railKey);
//     std::cout << "Bản mã cuối cùng sau khi mã hóa Rail Fence: " << railFenceEncrypted << std::endl;

//     return 0;
// }



// giải mã bản mã Casear bằng cách thử từng khóa
// #include <iostream>
// #include <string>
// #include <cctype>

// // Hàm giải mã Caesar cho ký tự ASCII
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';  // Giải mã cho chữ hoa
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';  // Giải mã cho chữ thường
//     } else {
//         return c;  // Giữ nguyên các ký tự không phải chữ cái
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

// // Hàm thử tất cả các khóa từ 0 đến 25 để tìm bản rõ
// void bruteForceCaesarDecrypt(const std::string& encryptedText) {
//     std::cout << "Thử tất cả các khóa (0-25):" << std::endl;
//     for (int key = 0; key < 26; ++key) {
//         std::string decryptedText = caesarDecrypt(encryptedText, key);
//         std::cout << "Khóa " << key << ": " << decryptedText << std::endl;
//     }
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Caesar: ";
//     std::getline(std::cin, encryptedText);

//     // Giải mã Caesar với phương pháp thử khóa
//     bruteForceCaesarDecrypt(encryptedText);

//     return 0;
// }


// giải mã Casear bằng cách phân tích tần suất
// #include <iostream>
// #include <string>
// #include <map>
// #include <algorithm>

// // Hàm giải mã Caesar cho ký tự ASCII
// char caesarDecryptChar(char c, int key) {
//     if (c >= 'A' && c <= 'Z') {
//         return (c - 'A' - key + 26) % 26 + 'A';  // Giải mã cho chữ hoa
//     } else if (c >= 'a' && c <= 'z') {
//         return (c - 'a' - key + 26) % 26 + 'a';  // Giải mã cho chữ thường
//     } else {
//         return c;  // Giữ nguyên các ký tự không phải chữ cái
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

// // Hàm phân tích tần suất và tìm khóa
// int findKeyFromFrequency(const std::string& encryptedText) {
//     // Đếm tần suất xuất hiện của các ký tự
//     std::map<char, int> freqMap;
//     for (char c : encryptedText) {
//         if (isalpha(c)) {  // Chỉ tính các ký tự alphabet
//             c = tolower(c);  // Chuyển về chữ thường để đồng nhất
//             freqMap[c]++;
//         }
//     }

//     // Tìm ký tự có tần suất cao nhất
//     char mostFrequentChar = 'a';
//     int maxFrequency = 0;
//     for (const auto& pair : freqMap) {
//         if (pair.second > maxFrequency) {
//             mostFrequentChar = pair.first;
//             maxFrequency = pair.second;
//         }
//     }

//     // Giả sử ký tự phổ biến nhất là 'e', tìm khóa
//     int key = mostFrequentChar - 'e';
//     if (key < 0) {
//         key += 26;  // Đảm bảo khóa không âm
//     }

//     return key;
// }

// // Hàm giải mã bằng phương pháp phân tích tần suất
// std::string decryptWithFrequencyAnalysis(const std::string& encryptedText) {
//     int key = findKeyFromFrequency(encryptedText);
//     std::cout << "Khóa dự đoán bằng phân tích tần suất: " << key << std::endl;
//     return caesarDecrypt(encryptedText, key);
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Caesar: ";
//     std::getline(std::cin, encryptedText);

//     // Giải mã bằng phân tích tần suất
//     std::string decryptedText = decryptWithFrequencyAnalysis(encryptedText);
//     std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;

//     return 0;
// }


// giả mã bản mã rail fence với 1 luồng
// #include <iostream>
// #include <vector>
// #include <string>

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
//     for (int numRails = 2; numRails <= 10; ++numRails) {
//         std::string decryptedText = railFenceDecrypt(encryptedText, numRails);
//         std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText << std::endl;
//     }

//     return 0;
// }


// giải mã bản mã Rail fence với 2 luồng
// #include <iostream>
// #include <vector>
// #include <string>
// #include <thread>
// #include <mutex>

// // Hàm giải mã Rail Fence
// std::string railFenceDecrypt(const std::string& encryptedText, int numRails) {
//     int len = encryptedText.length();
//     std::vector<std::vector<char>> rails(numRails, std::vector<char>(len, '\0'));
//     std::vector<int> railPattern(len, -1);

//     // Xác định vị trí các ký tự theo mẫu zigzag
//     int currentRail = 0;
//     bool goingDown = false;
//     for (int i = 0; i < len; ++i) {
//         railPattern[i] = currentRail;
//         if (currentRail == 0 || currentRail == numRails - 1)
//             goingDown = !goingDown;
//         currentRail += (goingDown ? 1 : -1);
//     }

//     // Xây dựng lại các rail từ bản mã
//     int index = 0;
//     for (int r = 0; r < numRails; ++r) {
//         for (int i = 0; i < len; ++i) {
//             if (railPattern[i] == r) {
//                 rails[r][i] = encryptedText[index++];
//             }
//         }
//     }

//     // Đọc lại các ký tự từ các rail để phục hồi bản rõ
//     std::string decryptedText;
//     for (int i = 0; i < len; ++i) {
//         decryptedText += rails[railPattern[i]][i];
//     }

//     return decryptedText;
// }

// // Biến mutex để đồng bộ hóa việc in kết quả
// std::mutex printMutex;

// // Hàm in ra kết quả giải mã cho một dải các số dòng
// void decryptRange(const std::string& encryptedText, int start, int end) {
//     for (int numRails = start; numRails <= end; ++numRails) {
//         std::string decryptedText = railFenceDecrypt(encryptedText, numRails);

//         // Sử dụng lock_guard để đảm bảo chỉ một luồng có thể in kết quả
//         std::lock_guard<std::mutex> lock(printMutex);
//         std::cout << "Giải mã với " << numRails << " dòng: " << decryptedText << std::endl;
//     }
// }

// int main() {
//     std::string encryptedText;
//     std::cout << "Nhập bản mã Rail Fence: ";
//     std::getline(std::cin, encryptedText);

//     // Tạo 2 luồng để giải mã với các dải số dòng khác nhau
//     std::thread t1(decryptRange, encryptedText, 2, 5);  // Giải mã với 2 đến 5 dòng
//     std::thread t2(decryptRange, encryptedText, 6, 10); // Giải mã với 6 đến 10 dòng

//     // Chờ các luồng kết thúc
//     t1.join();
//     t2.join();

//     return 0;
// }

