// Count_Amalgams_and_Primes_in_the_Orbits_for_n.cpp
// Created by Alan Verdegraal February 4, 2023.
//
// This program counts the number of Primes and the
// number of Amalgam numbers (called compo-primes by
// Denis Eugene Roberts), in the Orbits On(d) of an
// entered number n, where On(d)=d.
// 
// It will scan down the Orbits checking each to see
// if it equals d (the row number), and if it does,
// it checks for primality and increments the counts
// accordingly.
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

bool check4compoprime(long long int n) {
	bool found_prime = false;
	bool found_compoprime = false;
    
    if (n%6 == 0){
//        cout << n << " is divisible by 6." << endl;
        found_compoprime = false;
    }
    else { // n is not divisible by 6.
		if (((n+1)%6 == 0) || ((n-1)%6 == 0)) {   
			found_prime = check4prime(n);
			if (found_prime == false) {
				found_compoprime = true;
			}
			else {
				found_compoprime = false;
			}
		}		
	}
	return found_compoprime;
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
	int long long n, i;
	bool found_compoprime = false, found_prime = false;
	int long long orbit_value;
	int long long total_primes=0, total_amalgams=0;
	
	cout << "Enter n: ";
	cin >> n;
	
	cout << "Counting Primes and Amalgams for n = " << n << endl;
	cout << "=============================================" << endl;
	
	for (i=2; i<n; i++) {
		orbit_value=get_orbit_value(i,n);
		if (orbit_value==i) {
			found_prime=check4prime(orbit_value);
			if (found_prime==true) {
				total_primes++;
//				cout << i << endl;
			}
			else {
				found_compoprime = check4compoprime(orbit_value);
				if (found_compoprime==true) {
					total_amalgams++;
				}
			}
		}
		found_prime=false;
		found_compoprime=false;
	}
	cout << "Total Primes: \t\t" << total_primes << endl;
	cout << "Total Amalgams: \t" << total_amalgams << endl;
}

// End Code
