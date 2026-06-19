// Alt_Check4prime_function_Optimized.cpp
// Created by Alan Verdegraal -- November 17, 2025
//
// This creates a function called alt_check4composite that takes an integer
// as input and returns the boolean found_composite.
//
// This follows the Staircase Search Path but looks for factors and cofactors
// in a Square Sq(n) to determine if the number n is a Composite number.

// It starts at the main diagonal where j=3 and walks down that diagona
// to the Kernel. Then it descends the diagonal below the main diagonal.
// If it finds a factor or cofactor for n, it has found a composite number.
// If it doesn't find these, then the number is deemed a prime.

// This function has been optimized to exit as soon as it finds
// a composite number.

// This has been demonstrated to be accurate for all Composites and 
// Primes up through 1,000,000.
//
// This C++ program uses 64 bit number size with data type long long int.
// Maximum value of any register is the limit 9223372036854775807
// Since the formula of the Staircase Search Path involves squaring n
// the maximum number able to be processed is the square root of the limit
// or 3032000000.
//
// However, through testing, the maximum Prime that my Windows 10 64-bit 
// laptop can identify is 4294967291. Beyond that, the limits begin to 
// identify known Primes as Composites due to exceeding system limits.

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

bool alt_check4composite(long long int n) {
   long long int j = 0;
   bool found_composite = false;
   long long int sqrt_n_value = sqrt(n);
   long long int half_n = (n-1)/2 - 1;

   if (((n%2==0) && (n!=2)) || (n==1)) {
   	  found_composite = true;
//  	  cout << "n0 = " << n << " : " << "2" << endl;
   }
   if (found_composite != true) {
   		for (j=3;j<=sqrt_n_value;j++) {
       		if ((j*j) % n == 0) { 
        		found_composite = true;
         		cout << "n1 = " << n << " : " << j*j << endl;
         		j = sqrt_n_value + 1;
      		}
    	}	
    }
	if (found_composite != true) {		
      	for (j=sqrt_n_value + 1;j<=half_n;j++) {
			if ((j*j) % n == 0) {
				found_composite = true;
				cout << "n2 = " << n << " : " << j*j << endl;
				j = half_n + 1;
			}
		}
    }
    if (found_composite != true) {
        for (j=4;j<=sqrt_n_value;j++ ) {
        	if (n % (j*(j-1)) == 0) {
        		found_composite = true;
        		cout << "n3 = " << n << " : " << j*(j-1) << endl;
        		j = sqrt_n_value + 1;
			}
		}
	}
	if (found_composite != true) {
		for (j=sqrt_n_value;j<=half_n;j++) {
			if ((j*(j-1)) % n == 0) {
				found_composite = true;
				cout << "n4 = " << n << " : " << j*(j-1) << endl;
				j = half_n + 1;
			}
		}
	}	
    return found_composite;
}

int main() {
   bool found_composite = false;
   long long int nn;
   
   cout << "Enter the value for n: ";
   cin >> nn; 

   found_composite = alt_check4composite(nn);

   if (found_composite == true) {
   	   cout << endl;
       cout << "Number " << nn << " is Composite." << endl;
   }
   else {
       cout << endl;
	   cout << "Number " << nn << " is Prime." << endl;
   }
}

// End code

