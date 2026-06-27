// Sieve_of_Sundaram.cpp
//
// Sieve of Sundaram: Finds all primes up to 'n'
// Time Complexity: O(N log N)
// Space Complexity: O(N)
//
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;

sieveOfSundaram(long long int n) {
	long long number_of_primes = 0;
    // The sieve works on numbers up to (n-1)/2
    long long int nNew = (n - 1) / 2;

    // marked[i] will be true if 2*i + 1 is NOT prime
    vector<bool> marked(nNew + 1, false);

    // Main sieving logic
    for (long long int i = 1; i <= nNew; i++) {
        for (long long int j = i; (i + j + 2 * i * j) <= nNew; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }

    // 2 is the only even prime
    if (n >= 2) {
//        cout << 2 << " ";
        number_of_primes++;
    }

    // Print primes generated from the unmarked indices
    for (long long int k = 1; k <= nNew; k++) {
        if (!marked[k]) {
//            cout << 2 * k + 1 << " ";
            number_of_primes++;
        }
    }
    return number_of_primes;
}

int main() {
    long long int limit;
    long long int total_primes = 0;
    
    time_t timestamp;
    
    cout << "===================================" << endl;
	cout << "Sieve_of_Sundaram.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for highest bound: ";
    cin >> limit; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
	
    cout << "Primes up to " << limit << ": " << endl;
    
    total_primes = sieveOfSundaram(limit);
    
    cout << "===================================" << endl;
	cout << endl;
	cout << "Upper Bound:  " << limit << endl;
	cout << "Total Primes found:  " << total_primes << endl;
//	cout << "Last Prime Found:  " << last_prime_found << endl;
	cout << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End_code
