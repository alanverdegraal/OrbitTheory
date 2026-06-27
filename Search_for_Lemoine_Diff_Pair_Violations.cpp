// Search_for_Lemoine_Diff_Pair_Violations.cpp
// Created by Alan Verdegraal June 3, 2023
//
// After entering a range of numbers, this program
// first skips any even number, then searches for
// any odd numbers that do not have any Lemoine Diff Pairs.
//
// This provides evidence for the conjecture that 
// any odd number is the difference between a prime
// number subtracted from a biprime.
//
// All Lemonine Diff Pairs consist of a prime and a biprime
// that when the prime is subtracted from the biprime
// gives the odd number.
// 
// For each n, it first checks to see if n is a prime
// number. If so, the process can skip checking any
// orbit values since 2n will always be a biprime.
// Thus, 2n - n = n meets the criteria for an odd
// n being the difference between a biprime and a prime.

// Otherwise, the process runs down the Orbit Values for n
// checking each first to see if it is a 1 (factor), where it
// then checks the increment d or the non-1 Orbit
// Value to see if it is a prime number.
//
// If so, the program adds the prime number to
// the odd n, and checks that result to see if it is
// a biprime (a number that is the product of only
// two primes). If it is, then the program proceeds
// to the next odd number to check.
//
// The program has a counter to indicate progress for
// searching large ranges. If no Lemoine Diff Pairs are
// found for an odd n, then it will display that message.
// If no such messages are displayed, then no violations
// have been found.
//
// There are three functions that are defined and used:
// check4prime, get_orbit_value, and check4biprime.
//

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

bool check4prime(long long int n) {
   long long int j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_prime = true;

   if (((n%2==0) && (n!=2)) || (n==1)) {
   	  found_prime=false;
   }
   else {
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

long long int get_orbit_value (long long int d, long long int n) {
      long long int k, t=0;
      long long int orbit_value;

      k = 1 + d;                      // starting value of the sequence

      while (k != 1) {  
         if (k > n) {
            k -= n;       // k after the modulo operation: if k > n, then k = k - n
            t++;          // t being incremented when passing 1 on the circle, 
			                 //       increasing the Orbit for that sequence
         } 
         else {
            k += d;            // k being increased by the increment
         }
      }
      orbit_value = t;
      return orbit_value;
    }

bool check4biprime(long long int n) {
	bool found_prime = false;
	bool found_biprime = false;
	long long int temp, i, remainder;
	long long int orbit_value;
	
	for (i=2; i<n/2+1; i++) {
		orbit_value=get_orbit_value(i,n);
		if (orbit_value==1) {
			found_prime=check4prime(i);
			if (found_prime==true) {
				remainder=n%i;
				if (remainder==0) {
					temp=n/i;
					found_prime=check4prime(temp);
					if (found_prime==true) {
						found_biprime=true;
						i=n;
					}
				}
			}
		}  
	}
	return found_biprime;	
}

int main() {
    bool found_prime = false;
    bool found_biprime = false;
    bool found_Lemoine_Diff_Pair = false;
    long long int starting_value, ending_value;
    long long int n, i, first_prime, proposed_biprime;
    long long int orbit_value;
   
    cout << "Enter the starting_value for n: ";
    cin >> starting_value;
    cout << "Enter the ending_value for n: ";
    cin >> ending_value; 
    cout << endl;

	for (n=starting_value; n<=ending_value; n++) {
		if (n%2==1) {
			found_prime=check4prime(n);
			if (found_prime==false) {
				// If n is prime skip because 2n will always be a biprime
				// and 2n - n = n will be a prime.
				for (i=2; i<=n; i++) {
					orbit_value=get_orbit_value(i,n);
					if (orbit_value==1) {
						found_prime=check4prime(i);
						if (found_prime==true) {
							first_prime=i;
						}
					}
					else {
						found_prime=check4prime(orbit_value);
						if ((found_prime==true)&&(orbit_value==i)) {
							first_prime=orbit_value;
						}
					}
					if ((found_prime==true)&&(first_prime==i)) {
						proposed_biprime=n+first_prime;
						found_biprime=check4biprime(proposed_biprime);
						if (found_biprime==true) {
							found_Lemoine_Diff_Pair=true;
							i = n+1;
						}
					}
				}
			}
			else {
				found_Lemoine_Diff_Pair==true;
			}
			if (found_Lemoine_Diff_Pair==false) {
				cout << "**** No Lemoine Diff Pairs found for " << n << endl;
			}
			else {
				found_Lemoine_Diff_Pair==false;
			}
		}
		if (n%1000==0) {
			cout << "Current Number is " << n << endl;
		}
	}
}

// End-Code
