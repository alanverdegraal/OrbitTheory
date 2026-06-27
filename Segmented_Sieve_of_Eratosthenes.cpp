// Segmented_Sieve_of_Eratosthenes.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Standard Sieve to find primes up to sqrt(n)
void simpleSieve(int limit, vector<int>& prime) {
    vector<bool> mark(limit + 1, true);
    for (int p = 2; p * p <= limit; p++) {
        if (mark[p]) {
            for (int i = p * p; i <= limit; i += p)
                mark[i] = false;
        }
    }
    for (int p = 2; p <= limit; p++) {
        if (mark[p]) {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

// Segmented Sieve to find primes up to n
void segmentedSieve(int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    prime.reserve(limit);
    
    cout << "Primes up to " << n << ":" << endl;
    simpleSieve(limit, prime);

    int low = limit;
    int high = 2 * limit;

    while (low < n) {
        if (high > n) high = n;

        // Mark numbers in current range [low, high-1]
        vector<bool> mark(limit + 1, true);

        for (int i = 0; i < prime.size(); i++) {
            // Find the smallest multiple of prime[i] in [low..high-1]
            int start = floor(low / prime[i]) * prime[i];
            if (start < low) start += prime[i];

            for (int j = start; j < high; j += prime[i])
                mark[j - low] = false;
        }

        // Numbers which are not marked are prime
        for (int i = low; i < high; i++) {
            if (mark[i - low])
                cout << i << " ";
        }

        // Move to next segment
        low = low + limit;
        high = high + limit;
    }
    cout << endl;
}

int main() {
    int n = 100; // Example limit
    segmentedSieve(n);
    return 0;
}

