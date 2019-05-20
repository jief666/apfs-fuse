#pragma once

#include <inttypes.h>
#include <stdlib.h> // size_t

//#include "APFSTmp_Aes.h"

bool APFSLibCrypto_Rfc3394_KeyUnwrap(uint8_t *plain, const uint8_t *crypto, unsigned int size, const uint8_t *key, int aes_mode, uint64_t *iv);
void APFSLibCrypto_SHA256(const uint8_t* vek, int vek_len, const uint8_t* uuid, int uuid_len, uint8_t* sha_result);
void APFSLibCrypto_HMAC_SHA256(const uint8_t *key, size_t key_len, const uint8_t *data, size_t data_len, uint8_t *mac);
void APFSLibCrypto_PBKDF2_HMAC_SHA256(const uint8_t* pw, size_t pw_len, const uint8_t* salt, size_t salt_len, int iterations, uint8_t* derived_key, size_t dk_len);


void APFSLibCrypto_aes_xtx_setkey(const uint8_t* key1, int key1_len, const uint8_t* key2, int key2_len);
void APFSLibCrypto_aes_xtx_setkey(const uint8_t* key1, int key1_len, const uint8_t* key2, int key2_len, void **ctx);

void APFSLibCrypto_aes_xtx_decrypt(const uint8_t* encrypted_text, int len, uint8_t* plain_text, uint64_t uno);
void APFSLibCrypto_aes_xtx_decrypt(const uint8_t* encrypted_text, int len, uint8_t* plain_text, uint64_t uno, void* ctx);

uint32_t APFSLibCrypto_calculate_crc32c(uint32_t crc32c, const unsigned char *buffer, unsigned int length);
