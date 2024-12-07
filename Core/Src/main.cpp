
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

 
    if (choice == 1) {
    const std::string inputFileName = "Data/Caesar_plaintext.txt"; 
    const std::string outputFileName = "Data/Caesar_ciphertext.txt"; 

    std::string plainText;
    std::string confirm;
    int key;
     cout<<"Hãy nhập bản rõ vào file Caesar_plaintext.txt"<<'\n';
     cout<<"Nhập OK để xác nhận: ";
     cin>>confirm;
    while(confirm!="OK"){
  
        cout<<"Vui lòng nhập OK để xác nhận: ";
        cin>>confirm;
   
    }
   
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Không thể mở file: Caesar_plaintext.txt" << std::endl;
        return 1;
    }

  
    plainText.assign((std::istreambuf_iterator<char>(inputFile)),
                     (std::istreambuf_iterator<char>()));
    inputFile.close();
    if (plainText.empty()) {
        std::cout << "File bản rõ rỗng. Không có gì để mã hóa.\n";
        return 1;
    }
    std::cout << "Bản rõ đã đọc thành công từ file: Caesar_plaintext.txt" << '\n';
   
    std::cout << "Nhập khóa Caesar: ";
    std::cin >> key;

    std::string encryptedText = caesarEncrypt1(plainText, key);

  
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Không thể tạo file: Caesar_ciphertext.txt" << std::endl;
        return 1; 
    }

    outputFile << encryptedText; 
    outputFile.close();

    std::cout << "Bản mã đã ghi thành công vào file: Caesar_ciphertext.txt" << std::endl;
   
}

if (choice == 2) {
    auto programStart = std::chrono::high_resolution_clock::now();

    std::string encryptedText;
    std::string confirm;
    cout<<"Hãy nhập bản mã vào file Caesar_ciphertext.txt"<<'\n';
    cout<<"Nhập OK để xác nhận: ";
    cin>>confirm;
    while(confirm!="OK"){
 
        cout<<"Vui lòng nhập OK để xác nhận: ";
        cin>>confirm;
  
    }
    
    std::ifstream inputFile("Data/Caesar_ciphertext.txt");
    if (!inputFile) {
        std::cerr << "Không thể mở file Caesar_ciphertext.txt để đọc bản mã!\n";
        return 1;
    }
    std::getline(inputFile, encryptedText); 
    inputFile.close();
    if (encryptedText.empty()) {
        std::cout << "File bản mã rỗng. Không có gì để giải mã.\n";
        return 1;
    }
    std::cout << "Bản mã đã đọc thành công từ file: Caesar_ciphertext.txt: " << '\n';

    
    std::unordered_set<std::string> dictionary = loadDictionary1("Data/dictionary.txt");

   
    bruteForceCaesarDecrypt(encryptedText, dictionary);

   
    std::ofstream outputFile("Data/Caesar_plaintext.txt");
    if (!outputFile) {
        std::cerr << "Không thể mở file Caesar_plaintext.txt để ghi bản rõ!\n";
        return 1;
    }
 
    outputFile<<bestDecryptedTextGlobal << '\n';
 
    outputFile.close();

    std::cout << "\nBản rõ đã ghi thành công vào file: Caesar_plaintext.txt" << std::endl;
    cout << "Khóa Caesar giải mã được:  " << bestKeyGlobal << '\n';
    cout << "Số từ hợp lệ của bản rõ sau khi giải mã: "<<globalMaxValidWords << '\n';
   
    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
}


if (choice == 3) {
    std::string plainText;
    int numRails;

    
    std::string confirm;
    cout<<"Hãy nhập bản rõ vào file Rail_Fence_plaintext.txt"<<'\n';
    cout<<"Nhập OK để xác nhận: ";
    cin>>confirm;
    while(confirm!="OK"){
  
        cout<<"Vui lòng nhập OK để xác nhận: ";
        cin>>confirm;
  
    }
    
    std::ifstream inputFile("Data/Rail_Fence_plaintext.txt");
    if (!inputFile) {
        std::cerr << "Không thể mở file bản rõ Rail_Fence_plaintext.txt" << '\n';
        return 1;
    }

    std::getline(inputFile, plainText, '\0'); 
    inputFile.close();

    if (plainText.empty()) {
        std::cout << "File bản rõ rỗng. Không có gì để mã hóa.\n";
        return 1;
    }
    std::cout << "Bản rõ đã đọc thành công từ file: Rail_Fence_plaintext.txt" << '\n';
    
    std::cout << "Nhập khóa RailFence: ";
    std::cin >> numRails;

   
    std::string encryptedText = railFenceEncrypt1(plainText, numRails);

    
    std::ofstream outputFile("Data/Rail_Fence_ciphertext.txt");
    if (!outputFile) {
        std::cerr << "Không thể mở file Rail_Fence_ciphertext.txt để ghi"<< '\n';
        return 1;
    }
    outputFile << encryptedText;
    outputFile.close();

    std::cout << "Bản mã đã ghi thành công vào file: Rail_Fence_plaintext.txt" << std::endl;
}


if (choice == 4) {
    auto programStart = std::chrono::high_resolution_clock::now();
    std::string encryptedText;

    std::string confirm;
    cout<<"Hãy nhập bản mã vào file Rail_Fence_ciphertext.txt"<<'\n';
    cout<<"Nhập OK để xác nhận: ";
    cin>>confirm;
    while(confirm!="OK"){
  
        cout<<"Vui lòng nhập OK để xác nhận: ";
        cin>>confirm;
   
    }
    
    std::ifstream inputFile("Data/Rail_Fence_ciphertext.txt");
    if (!inputFile) {
        std::cerr << "Không thể mở file bản mã Rail_Fence_ciphertext.txt"<< '\n';
        return 1;
    }

    std::getline(inputFile, encryptedText, '\0'); 
    inputFile.close();

    if (encryptedText.empty()) {
        std::cout << "File bản mã rỗng. Không có gì để giải mã.\n";
        return 1;
    }
    std::cout << "Bản mã đã đọc thành công từ file: Rail_Fence_ciphertext.txt: " << '\n';
    
    std::unordered_set<std::string> dictionary = loadDictionary2("Data/dictionary.txt");

   
    int maxRails = encryptedText.length();
    int maxValidWords = 0;
    std::vector<std::pair<int, std::string>> bestDecryptedTexts;

   
    findBestDecryption(encryptedText, dictionary, 2, maxRails, maxValidWords, bestDecryptedTexts);

    
    std::ofstream outputFile("Data/Rail_Fence_plaintext.txt");
    if (!outputFile) {
        std::cerr << "Không thể mở file Rail_Fence_plaintext.txt để ghi" << '\n';
        return 1;
    }

   
    for (const auto& result : bestDecryptedTexts) {
     
        outputFile<<result.second<<'\n';
      
    }
   

    outputFile.close();
    std::cout << "Bản rõ đã ghi thành công vào file: Rail_Fence_plaintext.txt" << std::endl;
    cout<<"Khóa Rail Fence thu được: "<<bestDecryptedTexts[0].first<<'\n';
    cout<<"Số từ hợp lệ trong bản rõ Rail Fence thu được: "<< maxValidWords<<'\n';
   

    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);
    
    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
}


if (choice == 5) {
    std::string plainText;
    int caesarKey, railKey;
    std::string confirm;

   
    std::cout << "Hãy nhập bản rõ vào file Caesar_Rail_Fence_plaintext.txt" << '\n';
    std::cout << "Nhập OK để xác nhận: ";
    std::cin >> confirm;
    while (confirm != "OK") {
        std::cout << "Vui lòng nhập OK để xác nhận: ";
        std::cin >> confirm;
    }

   
    std::ifstream inputFile("Data/Caesar_Rail_Fence_plaintext.txt");
    if (!inputFile) {
        std::cerr << "Không thể mở file Caesar_Rail_Fence_plaintext.txt để đọc bản rõ!\n";
        return 1;
    }
    std::getline(inputFile, plainText);
    inputFile.close();
    if (plainText.empty()) {
        std::cout << "File bản rõ rỗng. Không có gì để mã hóa.\n";
        return 1;
    }
    std::cout << "Bản rõ đã đọc thành công từ file: Caesar_Rail_Fence_plaintext.txt\n";

    
    std::cout << "Nhập khóa Caesar: ";
    std::cin >> caesarKey;
    std::cout << "Nhập khóa RailFence: ";
    std::cin >> railKey;

   
    std::string caesarEncrypted = caesarEncrypt(plainText, caesarKey);
  

    std::string railFenceEncrypted = railFenceEncrypt(caesarEncrypted, railKey);
  
    std::ofstream outputFile("Data/Caesar_Rail_Fence_ciphertext.txt");
    if (!outputFile) {
        std::cerr << "Không thể mở file Caesar_Rail_Fence_ciphertext.txt để ghi bản mã!\n";
        return 1;
    }
  
    outputFile <<  railFenceEncrypted << '\n';
    outputFile.close();

    std::cout << "Bản mã đã được ghi thành công vào file: Caesar_Rail_Fence_ciphertext.txt" << std::endl;
}


if (choice == 6) {
    auto programStart = std::chrono::high_resolution_clock::now();
    std::string encryptedText;
    std::string confirm;

    
    std::cout << "Hãy nhập bản mã vào file Caesar_Rail_Fence_ciphertext.txt" << '\n';
    std::cout << "Nhập OK để xác nhận: ";
    std::cin >> confirm;
    while (confirm != "OK") {
        std::cout << "Vui lòng nhập OK để xác nhận: ";
        std::cin >> confirm;
    }

    
    std::ifstream inputFile("Data/Caesar_Rail_Fence_ciphertext.txt");
    if (!inputFile) {
        std::cerr << "Không thể mở file Caesar_Rail_Fence_ciphertext.txt để đọc bản mã!\n";
        return 1;
    }
    std::getline(inputFile, encryptedText);
    inputFile.close();
    if (encryptedText.empty()) {
        std::cout << "File bản mã rỗng. Không có gì để giải mã.\n";
        return 1;
    }
    std::cout << "Bản mã đã đọc thành công từ file: Caesar_Rail_Fence_ciphertext.txt\n";

    
    std::unordered_set<std::string> dictionary = loadDictionary("Data/dictionary.txt");

    
    std::string decryptedText = decryptProductCipher(encryptedText, dictionary);

    
    std::ofstream outputFile("Data/Caesar_Rail_Fence_plaintext.txt");
    if (!outputFile) {
        std::cerr << "Không thể mở file Caesar_Rail_Fence_plaintext.txt để ghi bản rõ!\n";
        return 1;
    }
    outputFile <<  decryptedText << '\n';
   
    outputFile.close();

    std::cout << "Bản rõ đã được ghi thành công vào file: Caesar_Rail_Fence_plaintext.txt" << std::endl;
    cout << "Khóa Caesar thu được: " << bestShift << '\n';
    cout << "Khóa Rail Fence thu được: " << bestRails << '\n';
    cout << "Số từ hợp lệ trong bản rõ thu được: " << bestValidWords << '\n';
   
    auto programEnd = std::chrono::high_resolution_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);

    std::cout << "\nThời gian thực thi toàn bộ chương trình: " << programDuration.count() << " ms\n";
    }
 return 0;
}
