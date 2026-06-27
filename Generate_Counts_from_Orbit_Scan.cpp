// Generate_Counts_from_Orbit_Scan.cpp
// Created by Alan Verdegraal -- January 13, 2023
//
// This checks the Orbit values of an entered value of n
// to count the number of primes, non-primes, compo-primes,
// and multiples of 6 (which should be 0), where the 
// Orbit value is the same as the Increment d row value.
//
#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

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
	long long int orbit_value;
    long long int i,n;
    long long int total_rel_primes=0, total_orbit_calcs=0;
    long long int count_of_primes=0, count_of_nonprimes=0, count_multiple_of_6=0, count_of_compoprimes=0;
    bool found_prime=false;
    
    cout << "Enter the number of the midTwin:  ";
    cin >> n;
    cout << endl;
    
    for (i=3; i<n-1; i++) {
    	if (i%2==1) { 
	    	orbit_value=get_orbit_value(i,n);
	    	total_orbit_calcs++;
    		if (orbit_value==i) {
    			total_rel_primes++;
				found_prime=check4prime(i);
				if (found_prime==true) {
					count_of_primes++;
				}
				else {
					count_of_nonprimes++;
        			if (i%6 == 0){
        				count_multiple_of_6++;
			        }
        			else { // n is not divisible by 6.
		    			if ((i+1)%6 == 0) {
						count_of_compoprimes++;
						}
						else {
						    if ((i-1)%6 == 0) {
				    			count_of_compoprimes++;
				    		}
						}	
					}	
			    }
				found_prime=false;
    		}
		}
	}
	cout << "Total Orbit Checks: " << total_orbit_calcs << endl;
	cout << "Total for i = d: " << total_rel_primes << endl;
	cout << "Count of Non Primes: " << count_of_nonprimes << endl;
	cout << "Count of Multiples of 6:" << count_multiple_of_6 << endl;
	cout << "Count of Primes: " << count_of_primes << endl;
	cout << "Count of Compo-Primes: " << count_of_compoprimes << endl;
}

// End-Code
