// #include <iostream>
// #include <fstream>
// #include <string>
// #include <unordered_map>
// #include <algorithm>

// // Hàm đọc từ file và đếm số lượng từ theo độ dài
// void printWordLengths(const std::string& filename) {
//     std::ifstream file(filename);
//     std::unordered_map<int, int> lengthCount;

//     if (!file.is_open()) {
//         std::cerr << "Không thể mở file!" << std::endl;
//         return;
//     }

//     // Đọc tất cả các từ từ file và đếm số lượng từ theo độ dài
//     std::string word;
//     while (file >> word) {
//         lengthCount[word.length()]++;
//     }

//     // Đóng file
//     file.close();

//     // In ra số lượng các từ theo độ dài giảm dần
//     std::cout << "Số lượng từ theo độ dài:\n";
//     for (const auto& entry : lengthCount) {
//         std::cout << "Độ dài " << entry.first << ": " << entry.second << " từ\n";
//     }
// }

// int main() {
//     std::string filename = "Src/dictionary.txt";  // Đổi đường dẫn file nếu cần
//     printWordLengths(filename);

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

// Hàm đọc từ file và tính toán tỷ lệ từ có độ dài từ 30 trở xuống
void printWordLengthStatistics(const std::string& filename) {
    std::ifstream file(filename);
    int totalWords = 0;
    int countUnder30 = 0;

    if (!file.is_open()) {
        std::cerr << "Không thể mở file!" << std::endl;
        return;
    }

    // Đọc tất cả các từ từ file và đếm số lượng từ theo độ dài
    std::string word;
    while (file >> word) {
        totalWords++;
        if (word.length() <= 25) {
            countUnder30++;
        }
    }

    // Đóng file
    file.close();

    // Tính tỷ lệ từ có độ dài <= 30
    double percentage = (static_cast<double>(countUnder30) / totalWords) * 100;

    // In kết quả
    std::cout << "Tổng số từ: " << totalWords << std::endl;
    std::cout << "Số lượng từ có độ dài <= 30: " << countUnder30 << std::endl;
    std::cout << "Tỷ lệ từ có độ dài <= 30: " << percentage << "%" << std::endl;
}

int main() {
    std::string filename = "Src/dictionary.txt";  // Đổi đường dẫn file nếu cần
    printWordLengthStatistics(filename);

    return 0;
}
