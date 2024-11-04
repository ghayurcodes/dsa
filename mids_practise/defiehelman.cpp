#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate (base^exp) % mod using modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result=1;
    for(int i=0;i<exp;i++){
        result*=base;
    }
    return result%mod;
}

int main() {
    // Prime number (public key part)
    long long p = 23; // Example prime number
    // Primitive root modulo p (public key part)
    long long g = 5;  // Example primitive root of 23

    // Private keys chosen by Alice and Bob (secret)
    long long a = 6; // Alice's private key
    long long b = 15; // Bob's private key

    // Public keys generated and shared
    long long A = power(g, a, p); // Alice's public key
    long long B = power(g, b, p); // Bob's public key

    // Each computes the shared secret
    long long shared_secret_A = power(B, a, p); // Alice calculates (B^a) % p
    long long shared_secret_B = power(A, b, p); // Bob calculates (A^b) % p

    // The shared secrets should match
    cout << "Alice's calculated shared secret: " << shared_secret_A << endl;
    cout << "Bob's calculated shared secret: " << shared_secret_B << endl;

    if (shared_secret_A == shared_secret_B) {
        cout << "Shared secret established successfully: " << shared_secret_A << endl;
    } else {
        cout << "Error: Shared secrets do not match." << endl;
    }

    return 0;
}
