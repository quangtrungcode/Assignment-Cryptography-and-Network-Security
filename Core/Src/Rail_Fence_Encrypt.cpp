#include"Rail_Fence_Encrypt.h"
std::string railFenceEncrypt1(const std::string& plainText, int numRails) {
    if (numRails == 1) return plainText;  

    std::vector<std::string> rails(numRails);
    int rail = 0;
    bool directionDown = true;

   
    for (char c : plainText) {
        rails[rail] += c;

        if (rail == 0) {
            directionDown = true;  
        } else if (rail == numRails - 1) {
            directionDown = false; 
        }

       
        rail += directionDown ? 1 : -1;
    }

    
    std::string encryptedText;
    for (const auto& row : rails) {
        encryptedText += row;
    }

    return encryptedText;
}


