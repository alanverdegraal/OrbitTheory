// Count_Number_Types_below_n.cpp
// Created by Alan Verdegraal July 28, 2023
//
// This program counts the number of Primes,
// even BiPrimes, odd BiPrimes, and non-Prime/non-BiPrimes
// beneath a number n.
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

bool check4biprime(long long int n) {
	bool found_prime = false;
	bool found_biprime = false;
	long long int temp, i, remainder;
	long long int orbit_value;
	
	for (i=2; i<n/2+1; i++) {
		orbit_value=get_orbit_value(i,n);
		if (orbit_value==1) {
			found_prime=check4prime(i);
			if (found_prime==true) {
				remainder=n%i;
				if (remainder==0) {
					temp=n/i;
					found_prime=check4prime(temp);
					if (found_prime==true) {
						found_biprime=true;
						i=n;
					}
				}
			}
		}  
	}
	return found_biprime;	
}

int main() {
	bool found_prime = false;
    bool found_biprime = false;
    long long int n, i;
    long long int count_of_primes=0, count_of_even_biprimes=0, count_of_odd_biprimes=0;
	long long int count_of_even_non_bi_primes=0, count_of_odd_non_bi_primes=0;
    long long int total_numbers=0;
    
	cout << "Enter value for n: ";
	cin >> n;
	
	for (i=1;i<n;i++) {
		found_prime=check4prime(i);
		if (found_prime==true) {
			count_of_primes++;
		}
		else {
			found_biprime=check4biprime(i);
			if (found_biprime==true) {
				if (i%2==0) {
					count_of_even_biprimes++;
				}
				else {
					count_of_odd_biprimes++;
				}
			}
		 	else {
		 		if (i%2==0) {
				 	count_of_even_non_bi_primes++;
				}
				else {
					count_of_odd_non_bi_primes++;
				}
			}
		}
	}
	total_numbers = count_of_primes + count_of_even_biprimes + count_of_odd_biprimes + count_of_even_non_bi_primes + count_of_odd_non_bi_primes;
	cout << "Number of Primes less than " << n << ":  " << count_of_primes << endl;
	cout << "Number of even BiPrimes less than " << n << ":  " << count_of_even_biprimes << endl;
	cout << "Number of odd BiPrimes less than " << n << ":  " << count_of_odd_biprimes << endl;
	cout << "Number of even non-Prime non-BiPrimes remaining:  " << count_of_even_non_bi_primes << endl;
	cout << "Number of odd non-Prime non-BiPrimes remaining:  " << count_of_odd_non_bi_primes << endl;
	cout << "Total numbers less than " << n << ":  "<< total_numbers << endl;
}

// End_Code
