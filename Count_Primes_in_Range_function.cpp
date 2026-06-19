// Count_Primes_in_Range_function.cpp
// Created by Alan Verdegraal January 27, 2023
//
// This function returns the count of primes
// between and including two numbers.

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

long long int count_primes_in_range (long long int n1, long long int n2) {
	long long int total_primes=0, k;
	bool found_prime = false;
	for (k=n1; k<=n2; k++) {
		found_prime=check4prime(k);
		if (found_prime==true) {
			total_primes++;
		}
	}
	return total_primes;
}

int main() {
	long long int beginning_value, ending_value;
	long long int total_primes = 0;
	
	cout << "Enter Starting Value: ";
	cin >> beginning_value;
	cout << "Enter Ending Value: ";
	cin >> ending_value;
	
	total_primes = count_primes_in_range (beginning_value,ending_value);
	cout << "Total Primes in Range from " << beginning_value << " to " << ending_value << " is " << total_primes;
}

// End Code
