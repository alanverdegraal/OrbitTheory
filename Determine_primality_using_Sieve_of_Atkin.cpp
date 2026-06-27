// Determine_primality_using_Sieve_of_Atkin.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;

void sieveOfAtkin(long long int limit) {

    // Initialize the sieve array with false
    std::vector<bool> isPrime(limit + 1, false);

    /* Mark isPrime[n] is true if one of the following is true:
       a) n = (4*x^2)+(y^2) has odd number of solutions, n % 12 = 1 or 5
       b) n = (3*x^2)+(y^2) has odd number of solutions, n % 12 = 7
       c) n = (3*x^2)-(y^2) has odd number of solutions, x > y and n % 12 = 11 */
    for (long long int x = 1; x * x <= limit; x++) {
        for (long long int y = 1; y * y <= limit; y++) {
            
            // Condition 1
            long long int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                isPrime[n] = !isPrime[n];

            // Condition 2
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                isPrime[n] = !isPrime[n];

            // Condition 3
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                isPrime[n] = !isPrime[n];
        }
    }

    // Mark all multiples of squares as non-prime
    for (long long int r = 5; r * r <= limit; r++) {
        if (isPrime[r]) {
            for (long long int i = r * r; i <= limit; i += r * r)
                isPrime[i] = false;
        }
    }
 
// Print results
    if (isPrime[limit] == true) {
    	cout << "The number " << limit << " is Prime." << endl;
	}
    else {
    	cout << "The number " << limit << " is Composite." << endl;
    }	
}

int main() {
    long long int limit;
    
    time_t timestamp;
    
    cout << "===================================" << endl;
	cout << "Determine_primality_using_Sieve_of_Atkin.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value n: ";
    cin >> limit; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
	cout << "===================================" << endl;	
	cout << endl;	
	cout << "===================================" << endl;	
	  
    sieveOfAtkin(limit);
    
    cout << "===================================" << endl;
	cout << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End_code