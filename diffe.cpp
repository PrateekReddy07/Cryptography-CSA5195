#include <stdio.h>
#include <math.h>

// Function to calculate (base^exponent) % mod
int power(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;
    
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    
    return result;
}

// Function to perform Diffie-Hellman key exchange
int diffieHellman(int base, int private_key, int prime) {
    return power(base, private_key, prime);
}

int main() {
    int base, private_key_A, private_key_B, prime;

    printf("Enter the prime number (p): ");
    scanf("%d", &prime);

    printf("Enter the base (g): ");
    scanf("%d", &base);

    printf("Enter Alice's private key: ");
    scanf("%d", &private_key_A);

    printf("Enter Bob's private key: ");
    scanf("%d", &private_key_B);

    // Calculate public keys
    int public_key_A = diffieHellman(base, private_key_A, prime);
    int public_key_B = diffieHellman(base, private_key_B, prime);

    // Calculate shared secret
    int secret_A = diffieHellman(public_key_B, private_key_A, prime);
    int secret_B = diffieHellman(public_key_A, private_key_B, prime);

    printf("\nShared secret for Alice: %d\n", secret_A);
    printf("Shared secret for Bob: %d\n", secret_B);

    return 0;
}

