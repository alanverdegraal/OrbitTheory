// Display_the_Mirror_Landau_Square_Powers_in_Range.cpp
// Created by Alan Verdegraal September 6, 2023
//
// Landau's Fourth Problem is based upon
// what square power of a number n and primes
// that follow it, i.e., where n^2 + 1 is prime.
// The mirror conjecture is whethere there are
// primes of the form n^2 - 1.
//
// This program prints out a list of mirror Landau's
// square powers and their primes.
//
// It also print out the value of (p+1)/2 to 
// determine the nature of the Latin Square LS(p). 
// If it is odd, then the Latin Square for p 
// is a Perfect Latin Square. If it is even, 
// then it is a near-Perfect Latin Square.
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

int main() {
    bool found_prime = false;
    long long int n, i;
	int long long starting_number, ending_number;
	
	cout << "Enter first number of range to square: ";
	cin >> starting_number;
	cout << "Enter last number of range to square: ";
	cin >> ending_number;
	
	cout << "Searching for Landau's squares and primes between " << starting_number;
	cout << " and " << ending_number << endl;
	cout << "================================================================" << endl;
	cout << "   n    n^2    n^2-1(prime)    (p+1)/2 " << endl;
	cout << "================================================================" << endl;

    for (i=starting_number; i<=ending_number; i++) {
		found_prime=check4prime((i*i)-1);
		if (found_prime==true) {
			cout << i << "  " << i*i << "  " << (i*i)-1 << "  " << (((i*i)-1)+1)/2 << endl;
		}
	}	
}

// End_code
