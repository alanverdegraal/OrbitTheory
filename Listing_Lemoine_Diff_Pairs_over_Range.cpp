// Listing_Lemoine_Diff_Pairs_over_Range.cpp
// Created by Alan Verdegraal  June 3, 2023
//
// This program seeks to discover whether an odd number
// is the difference of a biprime less a prime number.
//
// A Lemoine Diff Pair is a set of two numbers where
// one is a biprime and the other is a prime, such that
// when prime number is subtracted from a biprime, it
// results in the specified odd number.
//
// After entering a range of numbers, this program
// first skips any even number, then identifies
// all Lemonine Diff Pairs consisting of a prime subtracting
// from a biprime that gives the odd n.
// 
// For the n, it runs down the Orbit Values checking
// each first to see if it is a 1 (factor), where it
// then checks the increment d or the non-1 Orbit
// Value to see if it is a prime number.
//
// If so, the program adds the prime number to
// the odd n, and checks that result to see if it is
// a biprime (a number that is the product of only
// two primes), printing the numbers out, and continuing
// its search through the Orbit Values for n.
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
			cout << n << " ";
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
						cout << " {" << proposed_biprime << "," << first_prime << "} ";
					}
				}
			}
			cout << endl;
		}
	}
}

// End-Code
