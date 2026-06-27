// Find_a_prime_btw_Perfect_Squares.cpp
// Created by Alan Verdegraal October 15, 2022
//
// This is checking Legendre's Conjecture that there
// exists a prime between two consecutive Perfect Squares.
// A Perfect Square is a square power of a Natural Number.

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
	long long int beginning_value, ending_value, beginning_square, ending_square, first_square, next_square;
    long long int i, j, n;
    
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
   
    cout << "Checking for Primes between and including " << beginning_square;
    cout << " and " << ending_square << endl;
    cout << "=========================" << endl;      
    
    for (j = beginning_value; j <= ending_value; j++) {
    	first_square=(j*j);
    	next_square=(j+1)*(j+1);
    	for (n=(j*j)+1;n<(j+1)*(j+1);n++) {
            found_prime=check4prime(n);
            if (found_prime==true) {
	    	   cout << "Found prime between " << first_square << " and " << next_square << " : " << n << endl;
	    	   n=(j+1)*(j+1);
               found_prime=false;
		    }
		}
    }
}

// End-Code
