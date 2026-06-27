// Find_BiPrimes_for_n_in_a_Range.cpp
// Created by Alan Verdegraal  June 2, 2023
//
// After entering a range of values,
// this program finds the two prime factors for a number n
// if n is a biprime.
//
// A biprime is a composite number that is the product
// of two primes.
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

int main() {
    bool found_prime = false;
    bool found_biprime = false;
    long long int starting_value, ending_value;
    long long int n, temp, i, remainder;
    long long int orbit_value;
   
    cout << "Enter the starting_value for n: ";
    cin >> starting_value;
    cout << "Enter the ending_value for n: ";
    cin >> ending_value; 
    cout << endl;

	for (n=starting_value; n<=ending_value; n++) {
		for (i=2; i<=n/2+1; i++) {
			orbit_value=get_orbit_value(i,n);
			if (orbit_value==1) {
				found_prime=check4prime(i);
				if (found_prime==true) {
					remainder=n%i;
					if (remainder==0) {
						temp=n/i;
						found_prime=check4prime(temp);
						if (found_prime==true) {
							cout << "n = " << n << "     { " << i << ", " << temp << " }" << endl;
							found_biprime=true;
							i=n;
						}
					}	
				}
			}	  
		}
		found_biprime=false;
	}
}

// End Code
