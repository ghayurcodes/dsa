#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular inverse of e under mod φ(n) using Extended Euclidean Algorithm
int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;

    while (newr != 0) {
        int quotient = r / newr;
        int temp = t;
        t = newt;
        newt = temp - quotient * newt;
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }

    if (r > 1) {
        return -1; // e is not invertible
    }
    if (t < 0) {
        t += phi;
    }
    return t;
}

// Function to perform modular exponentiation (base^exp % mod)
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod; // base = base^2 % mod
    }
    return result;
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Step 1: Choose two random prime numbers p and q
    int p = 61, q = 53; // For simplicity, using small prime numbers
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 2: Choose e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    int e;
    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    // Step 3: Compute d, the modular multiplicative inverse of e modulo φ(n)
    int d = modInverse(e, phi);

    // Public key: (e, n)
    // Private key: (d, n)
    cout << "Public Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";

    // Input message (plaintext) to encrypt
    int plaintext;
    cout << "Enter plaintext (as integer): ";
    cin >> plaintext;

    // Step 4: Encrypt the plaintext
    int ciphertext = modExp(plaintext, e, n);
    cout << "Ciphertext: " << ciphertext << "\n";

    // Step 5: Decrypt the ciphertext
    int decryptedMessage = modExp(ciphertext, d, n);
    cout << "Decrypted Message: " << decryptedMessage << "\n";

    // Verify if decryption matches the original plaintext
    if (decryptedMessage == plaintext) {
        cout << "Success! The decrypted message matches the original plaintext.\n";
    } else {
        cout << "Failure! The decrypted message does not match the original plaintext.\n";
    }

    return 0;
}
