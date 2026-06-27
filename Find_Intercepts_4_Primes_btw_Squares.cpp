// Find_Intercepts_4_Primes_btw_Squares.cpp
// Created by Alan Verdegraal October 17, 2022
//
// This is checking Legendre's Conjecture that there
// exists a prime between two consecutive Perfect Squares.
// A Perfect Square is a square power of a Natural Number.
// For each prime between Perfect Squares, this program
// finds the two intercepts on each of the Rays from the
// two Perfect Squares. Then sums these values.
//
// The output is Prime, Intercept1, Intercept2, Sum
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
	long long int beginning_value, ending_value, beginning_square, ending_square, first_square, next_square;
	long long int diff, midpoint, prime, intercept1, intercept2;
    long long int j, k, d;
    
    cout << "Enter the initial value of the range to square: ";
    cin >> beginning_value;
    if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
    cout << "Enter the final value of the range to square: ";
    cin >> ending_value; 
    if (ending_value - beginning_value < 1) {ending_value = beginning_value = 1;} 
                                // range must be > 1
    cout << endl;
    beginning_square = beginning_value * beginning_value;
    ending_square = ending_value * ending_value;
   
    for (j = beginning_value; j <= ending_value; j++) {
       	first_square=j*j;
    	next_square=(j+1)*(j+1);
		cout << "Primes between " << first_square;
    	cout << " and " << next_square << endl;
    	cout << "=========================" << endl;      

 		diff=next_square - first_square;
 		midpoint=(diff - 1)/2;
 		k=first_square + 1;
    	for (k = first_square+1; k < first_square+midpoint; k++) {
            found_prime=check4prime(k);
            if (found_prime==true) {
				prime=k;
				d=prime-first_square;
				intercept1=get_orbit_value(d,prime);
	    	   	intercept2=get_orbit_value(diff-d,prime);
				cout << prime << " " << intercept1 << " " << intercept2 << " " << intercept1 + intercept2 << endl;
                found_prime=false;
		    }
		}	
		for (k = first_square + midpoint + 1; k < next_square; k++) {
		            found_prime=check4prime(k);
            if (found_prime==true) {
				prime=k;
				d=prime-first_square;
				intercept1=get_orbit_value(d,prime);
	    	   	intercept2=get_orbit_value(diff-d,prime);
				cout << prime << " " << intercept2 << " " << intercept1 << " " << intercept1 + intercept2 << endl;
                found_prime=false;
		    }
		}
    }
}

// End-Code

