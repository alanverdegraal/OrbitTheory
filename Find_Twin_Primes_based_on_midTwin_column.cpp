// Find_Twin_Primes_based_on_midTwin_column.cpp
// Created by Alan Verdegraal -- January 12, 2023
//
// This checks the Orbit values on a midTwin column
// and if any Orbit value is equal to the row value of d,
// then it checks the Orbit value +2 to see if that
// row equals the row value of d. If so, then it checks
// if those values added to the midTwin are prime. If
// so, then a new pair of Twin Primes is found. 
//
// This finds Twin Primes from the midTwin to 2*midTwin.
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
	long long int orbit_value, total_twins=0;
    long long int i, j, n;
    long long int total_prime_checks=0, total_orbit_calcs=0;
	bool found_candidate_i=false, found_candidate_j=false;
    bool found_prime_for_i=false, found_prime_for_j=false;
    
    cout << "Enter the number of the midTwin:  ";
    cin >> n;
    cout << endl;
    
    for (i=3; i<n-1; i++) {
    	if (i%2==1) { 
	    	orbit_value=get_orbit_value(i,n);
	    	total_orbit_calcs++;
    		if (orbit_value==i) {
    			found_candidate_i = true;
    			j = i+2;
    			orbit_value=get_orbit_value(j,n);
    			total_orbit_calcs++;
    			if (orbit_value==j) {
    				found_candidate_j = true;
    				found_prime_for_i = check4prime(n+i);
    				total_prime_checks++;
    				found_prime_for_j = check4prime(n+j);
    				total_prime_checks++;
    				if ((found_prime_for_i==true)&&(found_prime_for_j==true)) {
    					cout << n+i << "   " << n+j << endl;
    					total_twins++;
					}
				}
				i=j;	
			}
			found_candidate_i = false;
			found_candidate_j = false;
			found_prime_for_i = false;
			found_prime_for_j = false;
		}
	}
	cout << "Total Twin Primes: " << total_twins << endl;
	cout << "Total Prime Checks: " << total_prime_checks << endl;
	cout << "Total Orbit Checks: " << total_orbit_calcs << endl;
}

// End_Code
