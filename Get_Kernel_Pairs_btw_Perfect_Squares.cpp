// Get_Kernel_Pairs_btw_Perfect_Squares.cpp
// Created by Alan Verdegraal October 23, 2022
//
// This gets the Pairs of numbers equivalent to the
// Kernel Pairs on the upper right and lower right cells
// of the Kernel, along with the value on n for each pair.
// It then checks n to see if it is prime and prints out 
// "prime" if it is.
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
	long long int beginning_value, ending_value, beginning_square, ending_square, first_square, next_square;
	long long int orbit_value, orbit_value_2;
	long long int K21, K22, d;
    long long int i, j, n, k;
    bool prime_found=false;
    
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
        cout << "Checking for Kernel Pairs between " << first_square;
    	cout << " and " << next_square << endl;
    	cout << "=========================" << endl;
   		for (k = first_square; k < next_square; k++) {
   			K21 = j;
   			K22 = K21 + 1;
   			d = j;
			orbit_value=get_orbit_value(d,k);
			if (orbit_value == K21) {
				orbit_value_2=get_orbit_value(d+1,k);
				if (orbit_value_2==K22) {
                  	cout << k << " : " << K21 << " " << K22 << " : ";
                  	prime_found=check4prime(k);
                  	if (prime_found==true) {
                  		cout << "prime" << endl;
                  		prime_found=false;
					}
					else {
					    cout << endl;
					}
				}
			}
		}
	}
}

// End-Code

