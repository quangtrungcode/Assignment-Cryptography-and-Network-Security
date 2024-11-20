#include"Caesar_Rail_Fence_Decrypt.h"


// Giải mã Rail Fence Cipher
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

// // Giải mã Caesar Cipher
// std::string caesarDecrypt(const std::string& text, int shift) {
//     std::string decryptedText = text;
//     for (char& c : decryptedText) {
//         if (std::isalpha(c)) {
//             char base = std::islower(c) ? 'a' : 'A';
//             c = (c - base - shift + 26) % 26 + base;
//         }
//     }
//     return decryptedText;
// }

// // Hàm đọc từ điển từ file vào unordered_set
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

// // Kiểm tra số lượng từ hợp lệ trong bản rõ
// int countValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int validWords = 0;
//     std::string word;

//     // Duyệt qua các ký tự trong văn bản và tách thành các từ
//     for (char c : text) {
//         if (std::isalpha(c)) {
//             word += std::tolower(c);
//         } else {
//             if (!word.empty() && dictionary.find(word) != dictionary.end()) {
//                 ++validWords;
//             }
//             word.clear();
//         }
//     }

//     // Kiểm tra từ cuối nếu nó không bị kết thúc bằng dấu cách
//     if (!word.empty() && dictionary.find(word) != dictionary.end()) {
//         ++validWords;
//     }

//     return validWords;
// }

// // Giải mã toàn bộ quy trình (Rail Fence + Caesar)
// std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     int bestValidWords = 0;
//     std::string bestDecryptedText;

//     // Bước 1: Giải mã Rail Fence (thử tất cả số đường ray từ 2 đến độ dài của bản mã)
//     for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
//         std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);

//         // Bước 2: Giải mã Caesar (thử tất cả các shift từ 1 đến 25)
//         for (int shift = 1; shift < 26; ++shift) {
//             std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
//             int validWords = countValidWords(caesarDecryptedText, dictionary);

//             if (validWords > bestValidWords) {
//                 bestValidWords = validWords;
//                 bestDecryptedText = caesarDecryptedText;
//             }
//         }
//     }

//     return bestDecryptedText;
// }

// int main() {
//     // Đọc từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     // Bản mã (có thể thay đổi tùy theo bài toán)
//     std::string encryptedText;
    
//     // Yêu cầu người dùng nhập bản mã từ bàn phím
//     std::cout << "Nhập bản mã: ";
//     std::getline(std::cin, encryptedText);  // Đọc chuỗi từ bàn phím

//     // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
//     std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

//     // Hiển thị bản rõ đã giải mã
//     std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <vector>
// #include <string>
// #include <algorithm>

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

// // Hàm giải mã Caesar Cipher
// std::string caesarDecrypt(const std::string& text, int shift) {
//     std::string decryptedText = text;
//     for (char& c : decryptedText) {
//         if (std::isalpha(c)) {
//             char base = std::islower(c) ? 'a' : 'A';
//             c = (c - base - shift + 26) % 26 + base;
//         }
//     }
//     return decryptedText;
// }

// // Hàm đọc từ điển từ file vào unordered_set
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

// // Hàm tìm và đếm số lượng từ có trong từ điển bằng cách kiểm tra tất cả các chuỗi con
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     // Duyệt qua các chiều dài từ 1 đến chiều dài chuỗi đầu vào
//     for (size_t len = 1; len <= text.size(); ++len) {
//         // Duyệt qua tất cả các chuỗi con với chiều dài len
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             // Tạo chuỗi con
//             std::string word = text.substr(i, len);
//             // Chuyển chuỗi con thành chữ thường
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             // Kiểm tra chuỗi con có trong từ điển không
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;  // Tăng đếm nếu từ có trong từ điển
//             }
//         }
//     }
//     return count;
// }

// // Giải mã toàn bộ quy trình (Rail Fence + Caesar)
// std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     int bestValidWords = 0;
//     std::string bestDecryptedText;

//     // Bước 1: Giải mã Rail Fence (thử tất cả số đường ray từ 2 đến độ dài của bản mã)
//     for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
//         std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);

//         // Bước 2: Giải mã Caesar (thử tất cả các shift từ 1 đến 25)
//         for (int shift = 1; shift < 26; ++shift) {
//             std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
//             int validWords = findValidWords(caesarDecryptedText, dictionary);

//             if (validWords > bestValidWords) {
//                 bestValidWords = validWords;
//                 bestDecryptedText = caesarDecryptedText;
//             }
//         }
//     }

//     return bestDecryptedText;
// }

// int main() {
//     // Đọc từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/words_alpha.txt");

//     // Bản mã (có thể thay đổi tùy theo bài toán)
//     std::string encryptedText;
    
//     // Yêu cầu người dùng nhập bản mã từ bàn phím
//     std::cout << "Nhập bản mã: ";
//     std::getline(std::cin, encryptedText);  // Đọc chuỗi từ bàn phím

//     // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
//     std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

//     // Hiển thị bản rõ đã giải mã
//     std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;

//     return 0;
// }




// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <vector>
// #include <string>
// #include <algorithm>

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

// // Hàm giải mã Caesar Cipher
// std::string caesarDecrypt(const std::string& text, int shift) {
//     std::string decryptedText = text;
//     for (char& c : decryptedText) {
//         if (std::isalpha(c)) {
//             char base = std::islower(c) ? 'a' : 'A';
//             c = (c - base - shift + 26) % 26 + base;
//         }
//     }
//     return decryptedText;
// }

// // Hàm đọc từ điển từ file vào unordered_set
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

// // Hàm tìm và đếm số lượng từ có trong từ điển bằng cách kiểm tra tất cả các chuỗi con
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     // Duyệt qua các chiều dài từ 1 đến chiều dài chuỗi đầu vào
//     for (size_t len = 1; len <= text.size(); ++len) {
//         // Duyệt qua tất cả các chuỗi con với chiều dài len
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             // Tạo chuỗi con
//             std::string word = text.substr(i, len);
//             // Chuyển chuỗi con thành chữ thường
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             // Kiểm tra chuỗi con có trong từ điển không
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;  // Tăng đếm nếu từ có trong từ điển
//             }
//         }
//     }
//     return count;
// }

// // Giải mã toàn bộ quy trình (Rail Fence + Caesar)
// std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     int bestValidWords = 0;
//     std::string bestDecryptedText;
//     int bestShift = 0;  // Thêm biến để lưu lại shift tốt nhất
//     int bestRails = 0;  // Thêm biến để lưu lại số đường ray tốt nhất

//     // Bước 1: Giải mã Rail Fence (thử tất cả số đường ray từ 2 đến độ dài của bản mã)
//     for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
//         std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);
//         std::cout << "Giải mã Rail Fence với " << numRails << " đường ray: " << railDecryptedText << std::endl;

//         // Bước 2: Giải mã Caesar (thử tất cả các shift từ 1 đến 25)
//         for (int shift = 1; shift < 26; ++shift) {
//             std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
//             std::cout << "Giải mã Caesar với shift " << shift << ": " << caesarDecryptedText << std::endl;

//             int validWords = findValidWords(caesarDecryptedText, dictionary);
//             std::cout << "Số từ hợp lệ trong bản rõ: " << validWords << std::endl;

//             if (validWords > bestValidWords) {
//                 bestValidWords = validWords;
//                 bestDecryptedText = caesarDecryptedText;
//                 bestShift = shift;  // Cập nhật shift tốt nhất
//                 bestRails = numRails;  // Cập nhật số đường ray tốt nhất
//             }
//         }
//     }

//     // In số lượng shift và số đường ray của bản rõ cuối cùng
//     std::cout << "Số lượng shift tốt nhất của bản rõ: " << bestShift << std::endl;
//     std::cout << "Số đường ray tốt nhất của bản rõ: " << bestRails << std::endl;

//     return bestDecryptedText;
// }

// int main() {
//     // Đọc từ điển
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/vocabulary.txt");

//     // Bản mã (có thể thay đổi tùy theo bài toán)
//     std::string encryptedText;
    
//     // Yêu cầu người dùng nhập bản mã từ bàn phím
//     std::cout << "Nhập bản mã: ";
//     std::getline(std::cin, encryptedText);  // Đọc chuỗi từ bàn phím

//     // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
//     std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

//     // Hiển thị bản rõ đã giải mã
//     std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <thread>
// #include <mutex>
//#include<chrono>
// std::mutex mtx;  // Mutex để bảo vệ việc truy cập vào các biến chia sẻ

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

// // Hàm giải mã Caesar Cipher
// std::string caesarDecrypt(const std::string& text, int shift) {
//     std::string decryptedText = text;
//     for (char& c : decryptedText) {
//         if (std::isalpha(c)) {
//             char base = std::islower(c) ? 'a' : 'A';
//             c = (c - base - shift + 26) % 26 + base;
//         }
//     }
//     return decryptedText;
// }

// // Hàm đọc từ điển từ file vào unordered_set
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

// // Hàm tìm và đếm số lượng từ có trong từ điển bằng cách kiểm tra tất cả các chuỗi con
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     // Duyệt qua các chiều dài từ 1 đến chiều dài chuỗi đầu vào
//     for (size_t len = 1; len <= text.size(); ++len) {
//         // Duyệt qua tất cả các chuỗi con với chiều dài len
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             // Tạo chuỗi con
//             std::string word = text.substr(i, len);
//             // Chuyển chuỗi con thành chữ thường
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             // Kiểm tra chuỗi con có trong từ điển không
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;  // Tăng đếm nếu từ có trong từ điển
//             }
//         }
//     }
//     return count;
// }

// // Hàm để giải mã và cập nhật kết quả tốt nhất cho các số đường ray và độ lệch Caesar
// void decryptAndUpdateBestResult(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary,
//                                 int numRails, int& bestValidWords, std::string& bestDecryptedText,
//                                 int& bestShift, int& bestRails) {
//     std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);
    
//     // Giải mã Caesar cho các shift từ 1 đến 25
//     for (int shift = 1; shift < 26; ++shift) {
//         std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
//         int validWords = findValidWords(caesarDecryptedText, dictionary);
        
//         // Cập nhật kết quả tốt nhất nếu có số từ hợp lệ cao hơn
//         std::lock_guard<std::mutex> lock(mtx);  // Đảm bảo truy cập an toàn vào các biến chia sẻ
//         if (validWords > bestValidWords) {
//             bestValidWords = validWords;
//             bestDecryptedText = caesarDecryptedText;
//             bestShift = shift;
//             bestRails = numRails;
//         }
//     }
// }

// // Giải mã toàn bộ quy trình (Rail Fence + Caesar) với đa luồng
// std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     int bestValidWords = 0;
//     std::string bestDecryptedText;
//     int bestShift = 0;
//     int bestRails = 0;

//     std::vector<std::thread> threads;

//     // Bước 1: Tạo các luồng cho từng số đường ray
//     for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
//         threads.push_back(std::thread(decryptAndUpdateBestResult, encryptedText, std::cref(dictionary), numRails,
//                                       std::ref(bestValidWords), std::ref(bestDecryptedText),
//                                       std::ref(bestShift), std::ref(bestRails)));
//     }

//     // Chờ tất cả các luồng hoàn thành
//     for (auto& t : threads) {
//         t.join();
//     }

//     return bestDecryptedText;
// }

// int main() {
//     // Đọc từ điển
      //  auto programStart = std::chrono::high_resolution_clock::now();
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/vocabulary.txt");

//     // Bản mã (có thể thay đổi tùy theo bài toán)
//     std::string encryptedText;
    
//     // Yêu cầu người dùng nhập bản mã từ bàn phím
//     std::cout << "Nhập bản mã: ";
//     std::getline(std::cin, encryptedText);

//     // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
//     std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

//     // Hiển thị bản rõ đã giải mã
//     std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;
    // auto programEnd = std::chrono::high_resolution_clock::now();
    // auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    // std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
//     return 0;
// }



// #include <iostream>
// #include <fstream>
// #include <unordered_set>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <omp.h>  // Thêm thư viện OpenMP
// #include<chrono>
// //std::mutex mtx;  // Mutex để bảo vệ việc truy cập vào các biến chia sẻ

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

// // Hàm giải mã Caesar Cipher
// std::string caesarDecrypt(const std::string& text, int shift) {
//     std::string decryptedText = text;
//     for (char& c : decryptedText) {
//         if (std::isalpha(c)) {
//             char base = std::islower(c) ? 'a' : 'A';
//             c = (c - base - shift + 26) % 26 + base;
//         }
//     }
//     return decryptedText;
// }

// // Hàm đọc từ điển từ file vào unordered_set
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

// // Hàm tìm và đếm số lượng từ có trong từ điển bằng cách kiểm tra tất cả các chuỗi con
// int findValidWords(const std::string& text, const std::unordered_set<std::string>& dictionary) {
//     int count = 0;
//     // Duyệt qua các chiều dài từ 1 đến chiều dài chuỗi đầu vào
//     for (size_t len = 1; len <= text.size(); ++len) {
//         // Duyệt qua tất cả các chuỗi con với chiều dài len
//         for (size_t i = 0; i + len <= text.size(); ++i) {
//             // Tạo chuỗi con
//             std::string word = text.substr(i, len);
//             // Chuyển chuỗi con thành chữ thường
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             // Kiểm tra chuỗi con có trong từ điển không
//             if (dictionary.find(word) != dictionary.end()) {
//                 count++;  // Tăng đếm nếu từ có trong từ điển
//             }
//         }
//     }
//     return count;
// }

// // Hàm để giải mã và cập nhật kết quả tốt nhất cho các số đường ray và độ lệch Caesar
// void decryptAndUpdateBestResult(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary,
//                                 int numRails, int& bestValidWords, std::string& bestDecryptedText,
//                                 int& bestShift, int& bestRails) {
//     std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);
    
//     // Giải mã Caesar cho các shift từ 1 đến 25
//     for (int shift = 1; shift < 26; ++shift) {
//         std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
//         int validWords = findValidWords(caesarDecryptedText, dictionary);
        
//         // Cập nhật kết quả tốt nhất nếu có số từ hợp lệ cao hơn
//         #pragma omp critical
//         {
//             if (validWords > bestValidWords) {
//                 bestValidWords = validWords;
//                 bestDecryptedText = caesarDecryptedText;
//                 bestShift = shift;
//                 bestRails = numRails;
//             }
//         }
//     }
// }

// // Giải mã toàn bộ quy trình (Rail Fence + Caesar) với OpenMP
// std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
//     int bestValidWords = 0;
//     std::string bestDecryptedText;
//     int bestShift = 0;
//     int bestRails = 0;

//     // Bước 1: Song song hóa vòng lặp sử dụng OpenMP
//     #pragma omp parallel for
//     for (int numRails = 2; numRails <= encryptedText.length()-1200; ++numRails) {
//         decryptAndUpdateBestResult(encryptedText, dictionary, numRails, bestValidWords, bestDecryptedText, bestShift, bestRails);
//     }

//     return bestDecryptedText;
// }

// int main() {
//     // Đọc từ điển
//     auto programStart = std::chrono::high_resolution_clock::now();
//     std::unordered_set<std::string> dictionary = loadDictionary("Src/vocabulary.txt");

//     // Bản mã (có thể thay đổi tùy theo bài toán)
//     std::string encryptedText;
    
//     // Yêu cầu người dùng nhập bản mã từ bàn phím
//     std::cout << "Nhập bản mã: ";
//     std::getline(std::cin, encryptedText);

//     // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
//     std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

//     // Hiển thị bản rõ đã giải mã
//     std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;
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
#include <algorithm>
#include <omp.h>
#include<chrono>
//#include<math.h>
// Hàm giải mã Rail Fence
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
//     #pragma omp parallel for
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

// Tối ưu hóa giải mã Caesar với bảng tra cứu
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

// Tối ưu hóa tìm kiếm từ hợp lệ bằng cách chuyển toàn bộ văn bản thành chữ thường trước
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


// Hàm giải mã và cập nhật kết quả tốt nhất cho các số đường ray và độ lệch Caesar
void decryptAndUpdateBestResult(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary,
                                int numRails, int& bestValidWords, std::string& bestDecryptedText,
                                int& bestShift, int& bestRails) {
    std::string railDecryptedText = railFenceDecrypt(encryptedText, numRails);
    // #pragma omp critical
    // {
    //     std::cout << "Bản rõ sau khi giải mã Rail Fence (với " << numRails << " đường ray): " << railDecryptedText << std::endl;
    // }
    // Giải mã Caesar cho các shift từ 1 đến 25
    #pragma omp parallel for
    for (int shift = 1; shift < 26; ++shift) {
        std::string caesarDecryptedText = caesarDecrypt(railDecryptedText, shift);
        int validWords = findValidWords(caesarDecryptedText, dictionary);
        
        // Cập nhật kết quả tốt nhất nếu có số từ hợp lệ cao hơn
        #pragma omp critical
        {
            if (validWords > bestValidWords) {
                bestValidWords = validWords;
                bestDecryptedText = caesarDecryptedText;
                bestShift = shift;
                bestRails = numRails;
            }
        }
    }
}

// Giải mã toàn bộ quy trình (Rail Fence + Caesar) với OpenMP
std::string decryptProductCipher(const std::string& encryptedText, const std::unordered_set<std::string>& dictionary) {
    int bestValidWords = 0;
    std::string bestDecryptedText;
    int bestShift = 0;
    int bestRails = 0;

    #pragma omp parallel for
    for (int numRails = 2; numRails <= encryptedText.length(); ++numRails) {
        decryptAndUpdateBestResult(encryptedText, dictionary, numRails, bestValidWords, bestDecryptedText, bestShift, bestRails);
    }
    std::cout << "Khóa giải mã:\n";
    std::cout << "Số đường ray (Rails): " << bestRails << std::endl;
    std::cout << "Độ lệch Caesar (Shift): " << bestShift << std::endl;
    return bestDecryptedText;
}

int main() {
    // Đọc từ điển
         auto programStart = std::chrono::high_resolution_clock::now();
    std::unordered_set<std::string> dictionary = loadDictionary("Src/vocabulary.txt");

    // Bản mã (có thể thay đổi tùy theo bài toán)
    std::string encryptedText;
    
    // Yêu cầu người dùng nhập bản mã từ bàn phím
    std::cout << "Nhập bản mã: ";
    std::getline(std::cin, encryptedText);

    // Giải mã bản mã theo quy trình Rail Fence + Caesar Cipher
    std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

    // Hiển thị bản rõ đã giải mã
    std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;
    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
    return 0;
}




