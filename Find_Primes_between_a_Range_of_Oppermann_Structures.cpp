// Find_Primes_between_a_Range_of_Oppermann_Structures.cpp
// Created by Alan Verdegraal May 25, 2023
//
// Oppermann's Conjecture is that there exists at least one 
// prime between x(x-1) and x^2. Given an initial range for x,
// this program searches and lists any primes between the
// Oppermann's Structures.

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
	int long long i, k;
	int long long initial_seed, final_seed, seed, starting_value, ending_value;
	bool found_prime = false;
	bool first_prime = true;

	cout << "Check for Primes within a Range of Oppermann Structures" << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
	
	cout << "Enter initial seed value: ";
	cin >> initial_seed;
	cout << "Enter final seed value: ";
	cin >> final_seed;
	cout << endl;
	
	for (k = initial_seed; k <= final_seed; k++) {
		starting_value = (k - 1) * (k - 1);
		ending_value = k * (k - 1);
		
		cout << "seed = " << k << ", lower_bound = " << starting_value ;
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
		first_prime=true;
	}	
}

// End_Code
