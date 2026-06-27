//Miller-Rabin_Primality_Test.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Safely calculates (a * b) % mod to prevent overflow
long long mulmod(long long a, long long b, long long mod) {
    long long res = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res;
}

// Calculates (base^exp) % mod using binary exponentiation
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mulmod(res, base, mod);
        base = mulmod(base, base, mod);
        exp /= 2;
    }
    return res;
}

// Miller-Rabin Primality Test
bool isPrime(long long n, int iterations = 5) {
    // Basic checks
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    // Find d such that n - 1 = d * 2^r
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Witness loop
    for (int i = 0; i < iterations; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = power(a, d, n);

        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int j = 0; j < r - 1; j++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false; // Definitely composite
    }
    return true; // Probably prime
}

int main() {
	cout << "===================================" << endl;
	cout << "Miller-Rabin_Primality_Test.cpp" << endl;
	cout << "===================================" << endl;	
    srand(time(0));
    long long num;
    cout << "Enter a number to check: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is probably prime." << endl;
    else
        cout << num << " is composite." << endl;

    return 0;
}
