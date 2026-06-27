// Determine_primality_using_Erostostenes.cpp
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;

void sieveOfEratosthenes(long long int n) {
	long long int number_of_primes = 0;
    // Create a boolean vector and initialize all entries as true
    // std::vector<bool> is space-optimized to use 1 bit per boolean
    std::vector<bool> is_prime(n + 1, true);
    
    // 0 and 1 are not prime numbers
    is_prime[0] = is_prime[1] = false;

    for (long long int p = 2; p * p <= n; p++) {
        // If is_prime[p] is not changed, then it is a prime
        if (is_prime[p]) {
            // Update all multiples of p starting from p*p
            for (long long int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    // Print results
    if (is_prime[n] == true) {
    	cout << "The number " << n << " is Prime." << endl;
	}
    else {
    	cout << "The number " << n << " is Composite." << endl;
    }	
}

int main() {
    long long int n;
    
    time_t timestamp;
    
    cout << "===================================" << endl;
	cout << "Determine_primality_using_Erostostenes.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for n: ";
    cin >> n; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
	cout << endl;
	cout << "===================================" << endl;	
		
	sieveOfEratosthenes(n);
    
    cout << "===================================" << endl;
	cout << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End_code

