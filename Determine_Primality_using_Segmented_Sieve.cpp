// Determine_Primality_using_Segmented_Sieve.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <limits>
#include <ctime>
using namespace std;

// Standard Sieve to find primes up to sqrt(n)
void simpleSieve(long long int limit, vector<int>& prime) {
    vector<bool> mark(limit + 1, true);
    for (long long int p = 2; p * p <= limit; p++) {
        if (mark[p]) {
            for (long long int i = p * p; i <= limit; i += p)
                mark[i] = false;
        }
    }
    for (long long int p = 2; p <= limit; p++) {
        if (mark[p]) {
            prime.push_back(p);
//           cout << p << " ";
        }
    }
}

// Segmented Sieve to find primes up to n
void segmentedSieve(long long int n) {
    long long int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    prime.reserve(limit);
    
    cout << "Primes up to " << n << ":" << endl;
    simpleSieve(limit, prime);

    long long int low = limit;
    long long int high = 2 * limit;

    while (low < n) {
        if (high > n) high = n;

        // Mark numbers in current range [low, high-1]
        vector<bool> mark(limit + 1, true);

        for (long long int i = 0; i < prime.size(); i++) {
            // Find the smallest multiple of prime[i] in [low..high-1]
            long long int start = floor(low / prime[i]) * prime[i];
            if (start < low) start += prime[i];

            for (long long int j = start; j < high; j += prime[i])
                mark[j - low] = false;
        }

        // Numbers which are not marked are prime
        for (long long int i = low; i < high; i++) {
            if (mark[i - low])
               cout << i << " ";
        }

        // Move to next segment
        low = low + limit;
        high = high + limit;
    }
    cout << endl;
    
// Print results
	cout << endl;
    cout << "===================================" << endl;
    if (!prime[n] == true) {
    	cout << "The number " << n << " is Prime." << endl;
	}
    else {
    	cout << "The number " << n << " is Composite." << endl;
    }	    
}

int main() {
	long long int limit;
    long long int total_primes = 0;
    
    time_t timestamp;
    
    cout << "===================================" << endl;
	cout << "Determine_Primality_using_Segmented_Sieve.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for highest bound: ";
    cin >> limit; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
	cout << "===================================" << endl;	
    
    segmentedSieve(limit);
    
	cout << "===================================" << endl;
	cout << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

