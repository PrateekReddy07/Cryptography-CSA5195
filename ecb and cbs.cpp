#include <stdio.h>
#include <string.h>

void encryptECB(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext) {
    size_t len = strlen((const char *)plaintext);

    for (size_t i = 0; i < len; i += 16) {
        for (size_t j = 0; j < 16 && i + j < len; ++j) {
            ciphertext[i + j] = plaintext[i + j] ^ key[j];
        }
    }
}

int main() {
    // 128-bit key (16 bytes)
    unsigned char key[] = "secretkey123456";

    // Message to be encrypted (multiple of block size for simplicity)
    unsigned char plaintext[] = "Hello, World!1234";

    // Buffer to store the ciphertext
    unsigned char ciphertext[128];

    // Encrypt using ECB mode
    encryptECB(plaintext, key, ciphertext);

    // Print the encrypted text
    printf("Encrypted Text: ");
    for (int i = 0; i < strlen((const char *)plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}

