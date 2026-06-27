// List_factors_for_a_Specified_Gap.cpp
// Created by Alan Verdegraal June 17, 2023
//
// Grimm's Conjecture states that in any set of
// consecutive composite numbers between to consecutive
// primes, there are distinct prime factors for every
// composite number.
//
// This program checks the gap containing consecutive
// composite numbers, listing out the prime factors
// for each number. 
//
// It then validates if there is a distinct set
// of prime factors for this set of consecutive primes.
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

long long int get_orbit_value (long long int n, long long int d) {
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
	long long int beginning_value, ending_value;
	long long int i, j;
	long long int orbit_value, found_prime;

	cout << "First enter the primes that enclose the set of consecutive composites." << endl;	
	cout << "Enter the value of the first prime: ";
    cin >> beginning_value;
    cout << "Enter the value of the last prime: ";
    cin >> ending_value; 
    
	for (i=beginning_value+1; i<ending_value; i++) {
		for (j=2; j<i/2 + 1; j++) {
			orbit_value=get_orbit_value(i,j);
			if (orbit_value==1) {
				found_prime=check4prime(j);
				if (found_prime==true) {
					cout << i << " " << j << endl; 
				}
			}
		}
	}
}

// End_Code
