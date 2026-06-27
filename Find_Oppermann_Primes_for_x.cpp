// Find_Oppermann_Primes_for_x.cpp
// Created by Alan Verdegraal May 25, 2023
//
// Oppermann's Conjecture is that there exists at least one 
// prime between x(x-1) and x^2. Given an initial value x
// this program searches and lists any primes between these
// two bounds.

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
	int long long i;
	int long long seed, starting_value, ending_value;
	bool found_prime = false;
	bool first_prime = true;
	
	cout << "Check for Primes within an Oppermann Structure" << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
	
	cout << "Enter seed value: ";
	cin >> seed;
	
	starting_value = seed * (seed - 1);
	ending_value = seed * seed;
	
	cout << endl;
	cout << "seed = " << seed << ", lower_bound = " << starting_value ;
	cout << ", upper_bound = " << ending_value << ", primes = { " ;
		
	for (i=starting_value+1; i<ending_value; i++) {
		found_prime=check4prime(i);
		if (found_prime==true) {
			if (first_prime==true) {
				cout << i ;
				first_prime=false;
			}
			else {
				cout << ", " << i ;
			}
		}
	}
	
	cout << " }" << endl;
	
}

// End_code
