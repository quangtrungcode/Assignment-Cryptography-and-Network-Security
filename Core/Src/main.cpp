
#include"Caesar_Encrypt.h"
#include"Caesar_Decrypt.h"
#include"Rail_Fence_Encrypt.h"
#include"Rail_Fence_Decrypt.h"
#include"Caesar_Rail_Fence_Encrypt.h"
#include"Caesar_Rail_Fence_Decrypt.h"

int main() {
    int choice;

    std::cout << "Choose the encryption or decryption method:\n";
    std::cout << "1. Caesar Encryption\n";
    std::cout << "2. Caesar Decryption\n";
    std::cout << "3. Rail Fence Encryption\n";
    std::cout << "4. Rail Fence Decryption\n";
    std::cout << "5. Caesar Rail Fence Encryption\n";
    std::cout << "6. Caesar Rail Fence Decryption\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice==1) {
         
       
        std::string plainText;
        int key;

        
        std::cout << "Nhập bản rõ: ";
        std::cin.ignore(); 
        std::getline(std::cin, plainText);

        
        std::cout << "Nhập khóa (số nguyên): ";
        std::cin >> key;

        
        std::string encryptedText = caesarEncrypt1(plainText, key);
        std::cout << "Bản mã sau khi mã hóa Caesar: " << encryptedText << std::endl;
    }
if(choice==2){
    auto programStart = std::chrono::high_resolution_clock::now();

    std::string encryptedText;
    std::cout << "Nhập bản mã Caesar: ";
    std::cin.ignore();
    std::getline(std::cin, encryptedText);

    
    std::unordered_set<std::string> dictionary = loadDictionary1("Src/dictionary.txt");

    
    bruteForceCaesarDecrypt(encryptedText, dictionary);

    
    std::cout << "\nBản rõ có khả năng đúng nhất với khóa " << bestKeyGlobal << ": " << bestDecryptedTextGlobal << std::endl;

    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";

}
if(choice==3){
   std::string plainText;
    int numRails;

   
    std::cout << "Nhập bản rõ: ";
    std::cin.ignore();
    std::getline(std::cin, plainText);

    std::cout << "Nhập số dòng (rails): ";
    std::cin >> numRails;

    
    std::string encryptedText = railFenceEncrypt1(plainText, numRails);
    std::cout << "Bản mã sau khi mã hóa Rail Fence: " << encryptedText << std::endl;

}
if(choice==4){
        auto programStart = std::chrono::high_resolution_clock::now();
    std::string encryptedText;
    std::cout << "Nhập bản mã Rail Fence: ";
    std::cin.ignore();
    std::getline(std::cin, encryptedText);

    std::unordered_set<std::string> dictionary = loadDictionary2("Src/dictionary.txt");

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
}
if(choice==5){
        std::string plainText;
    int caesarKey, railKey;

   
    std::cout << "Nhập bản rõ: ";
    std::cin.ignore();
    std::getline(std::cin, plainText);

    std::cout << "Nhập khóa Caesar (số nguyên): ";
    std::cin >> caesarKey;

    std::cout << "Nhập số dòng Rail Fence: ";
    std::cin >> railKey;

    
    std::string caesarEncrypted = caesarEncrypt(plainText, caesarKey);
    std::cout << "Bản mã sau khi mã hóa Caesar: " << caesarEncrypted << std::endl;

   
    std::string railFenceEncrypted = railFenceEncrypt(caesarEncrypted, railKey);
    std::cout << "Bản mã cuối cùng sau khi mã hóa Rail Fence: " << railFenceEncrypted << std::endl;
}
if(choice==6){
             auto programStart = std::chrono::high_resolution_clock::now();
    std::string encryptedText;
    
    
    std::cout << "Nhập bản mã: ";
    std::cin.ignore();
    std::getline(std::cin, encryptedText);
    std::unordered_set<std::string> dictionary = loadDictionary("Src/dictionary.txt");
    
    std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

   
    std::cout << "Bản rõ sau khi giải mã: " << decryptedText << std::endl;
    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
}
    return 0;
}
