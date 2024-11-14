#ifndef RAIL_FENCE_DECRYPT_H
#define RAIL_FENCE_DECRYPT_H
#include <thread>
#include <mutex>
#include"Caesar_Encrypt.h"
std::string railFenceDecrypt(const std::string& encryptedText, int numRails);
#endif