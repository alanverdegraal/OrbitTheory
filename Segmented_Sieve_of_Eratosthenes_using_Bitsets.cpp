// Segmented_Sieve_of_Eratosthenes_using_Bitsets.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

const int SEGMENT_SIZE = 32768; // Fits well in most L1 caches

void segmentedSieveBitset(int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> primes;
    
    // 1. Simple Sieve for primes up to sqrt(n)
    vector<bool> is_prime(limit + 1, true);
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) primes.push_back(p);
    }

    // 2. Segmented Sieve using Bitset (Odd numbers only)
    // bit 'i' represents the number (low + 2*i + 1)
    int low = 0;
    while (low <= n) {
        int high = min(low + SEGMENT_SIZE * 2, n);
        bitset<SEGMENT_SIZE> segment;
        segment.set(); // Set all bits to 1 (prime)

        for (int p : primes) {
            // Find first odd multiple of p >= low
            int start = (low + p - 1) / p * p;
            if (start % 2 == 0) start += p;
            if (start < p * p) start = p * p; // Start marking from p^2

            for (int j = start; j <= high; j += 2 * p) {
                if (j > low) segment.reset((j - low - 1) / 2);
            }
        }

        for (int i = 0; i < SEGMENT_SIZE && (low + 2 * i + 1) <= high; i++) {
            int num = low + 2 * i + 1;
            if (num > 1 && segment.test(i)) {
                // Number is prime (except 1)
                cout << num << " "; // Uncomment to print
            }
        }
        low += SEGMENT_SIZE * 2;
    }
}

int main() {
    int n = 1000; // Example limit
    segmentedSieveBitset(n);
    return 0;
}
