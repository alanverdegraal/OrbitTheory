// Check_for_Compo_Prime_or_Prime.cpp
// Created by Alan Verdegraal January 7, 2023
//
// This will determine if a number n is either
// a prime or a compo-prime.
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

int main() {
	bool found_prime = false;
	long long int n;
    
    cout << "Enter a number: ";
    cin >> n;
    
    found_prime = check4prime(n);
    if (found_prime == true) {
    	cout << n << " is a Prime number." << endl;
	}
    else { // n is a composite number
        if (n%6 == 0){
        	cout << n << " is divisible by 6." << endl;
        }
        else { // n is not divisible by 6.
		    if ((n+1)%6 == 0) {
				cout << n << " is a low compo_prime.";
			}
			else {
			    if ((n-1)%6 == 0) {
				    cout << n << " is a high compo_prime.";
			    }
				else {
				    cout << n << " is a normal composite.";
				}
			}
		}		
	}
}

// End script
