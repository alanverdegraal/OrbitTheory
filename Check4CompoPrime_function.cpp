// Check4CompoPrime_function.cpp
// Created by Alan Verdegraal January 7, 2023
//
// This is the code for a function to determine
// if a number n is a compo_prime.
// 
// The function is called with:
//     found_compoprime = check4compoprime(n);
// where found_compoprime (or other identifier)
// is true for a compo prime and false if it is 
// not a compo prime.
//
// To use in a call from other code, include all
// code for check4prime and check4compoprime and
// set n before calling check4compoprime.
//

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

bool check4prime(long long int n) {
   long long int j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_prime = false;
   if (n!=1) {
      found_prime = true;
      j++;
      while (j < n - 2) {
         b4_mod_value = (((n*n) - (2*j*n) + (j*j) + 3 + (j % 2))/4);
         cell_value = b4_mod_value % n;
         if (cell_value == 1) {
            found_prime = false;
            j = n - 2;
         }
         j++;
      }
   }
   return found_prime;
}

bool check4compoprime(long long int n) {
	bool found_prime = false;
	bool found_compoprime = false;
    
    found_prime = check4prime(n);
    if (found_prime == false) {
        if (n%6 == 0){
        	cout << n << " is divisible by 6." << endl;
        	found_compoprime = false;
        }
        else { // n is not divisible by 6.
		    if ((n+1)%6 == 0) {
				found_compoprime = true;
			}
			else {
			    if ((n-1)%6 == 0) {
				    found_compoprime = true;
			    }
			}
		}		
	}
	return found_compoprime;
}

int main() {
	int long long n;
	bool found_compoprime = false;
	
	cout << "Enter n: ";
	cin >> n;
	found_compoprime = check4compoprime(n);
	if (found_compoprime == true) {
		cout << n << " is a compo_prime.";
	}
	else {
		cout << n << " is NOT a compo_prime";
	}
}

// End function

