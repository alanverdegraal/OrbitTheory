// Get_Prime_Pairs_that_Sum_to_Even_N.cpp
// Created by Alan Verdegraal September 15, 2022
//
// This program takes an even number and derives all
// pairs of Primes that add up to that number.
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
	bool found_second_prime=false;
	long long int orbit_value;
	long long int total_pairs=0;
    long long int i, n;
    
    cout << "Enter an even number:  ";
    cin >> n;
    cout << endl;
    
    for (i=1; i<=n/2; i++) {
       orbit_value=get_orbit_value(i,n);
	   found_prime=check4prime(orbit_value);
	   if (found_prime==true) {
          found_second_prime=check4prime(n-i);
          if (found_second_prime==true){
             cout << n << " {" << n-i << "," << i << "}" << endl;
             total_pairs++;
		     found_second_prime=false;
	      }
          found_prime=false;
       } 
   }    
   cout << endl;
   cout << "Total Prime Pairs:  " << total_pairs << endl;
}

// End_Code

