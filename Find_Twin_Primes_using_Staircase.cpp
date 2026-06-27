// Find_Twin_Primes_using_Staircase.cpp
// Created by Alan Verdegraal January 13, 2023
// 
// This tests every number n from n to 2n
// for Primality and accummulates/counts Twin
// Primes.
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
   return found_prime;
}

int main() {
	long long int total_twins=0;
    long long int i, n;
    bool found_prime=false, first_prime=false;
    long long int first_prime_value=0;
    long long int total_prime_checks=0;
    
    cout << "Enter the number of the midTwin:  ";
    cin >> n;
    cout << endl;
    
    for (i=n; i < 2*n; i++) {
    	if (i%2==1) {
    		found_prime=check4prime(i);
    		total_prime_checks++;
    		if (found_prime==true) {
    			first_prime=true;
    			first_prime_value=i;
    			i++;
    			i++;
    			found_prime=check4prime(i);
    			total_prime_checks++;
    			if (found_prime==true) {
    				if (first_prime==true) {
    					cout << first_prime_value << "    " << i << endl;
    					total_twins++;
					}
				}
			}
			first_prime_value=0;
			found_prime=false;
		}
	}
	cout << "Total Twin Primes: " << total_twins << endl;
	cout << "Total Prime Checks: " << total_prime_checks << endl;
}

// End code
