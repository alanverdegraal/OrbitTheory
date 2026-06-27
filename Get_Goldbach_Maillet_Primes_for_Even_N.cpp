// Get_Goldbach_Maillet_Primes_for_Even_N.cpp
// Created by Alan Verdegraal January 27, 2023
//
// For an even number, and in particular multiples
// of 6, this program goes down the Vertical set of
// Orbits, identifying where the Orbit value On(d) = d.
// That Orbit is either a prime number or an amalgam
// number. The program then checks if that Orbit value
// is on a Right and/or left Prime Rays, then lists
// out those prime numbers.
// 
// Right Prime Rays crossing the Even Vertical are
// from prime numbers less than n. Left Prime Rays
// crossing the Even Vertical are from prime numbers
// between n and 2n.
//
// The program also counts the primes from 1 to n
// and from n to 2n, to compare the the counts of
// primes with Prime Rays that cross the Even 
// Vertical. This demonstrates that all primes from
// 1 to n and from n to 2n cross the Even Verticals
// at prime or amalgam values of the Orbits of n.
// 
// There is another possibility where the Orbit value
// for a particular increment d, is not equal to d,
// however, it is a multiple of the prime initiating
// the Right Prime Ray. These are identified and
// labeled "Multiple." There are no such situations
// for Left Prime Rays.
//
// Goldbach_number is a prime number p1 that 
// satisfies the Goldbach equation p1 + p2 = n.
// Maillet_number is a prime number p1 that
// satisfies the equation p2 - p1 = n, where
// p1 is the Orbit Value for n.
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
	int long long n;
	bool found_compoprime = false;
	bool found_prime = false;
	bool found_g_prime = false;
	bool found_m_prime = false;
	bool found_k_prime = false;
	bool prt_new_line = false;
	int long long orbit_value, goldbach_value, maillet_value;
	int long long goldbach_total=0, maillet_total=0;
	int long long total_left_side_primes=0, total_right_side_primes=0;
	int long long k;
	
	cout << "Enter Even n > 4: ";
	cin >> n;
	
	if (n%2 == 1) {  
		cout << "Number entered is not even." << endl;
		cout << "Please enter an even number." << endl;
		terminate();
	}
	else {
		cout << "Identifying Prime Combos for " << n << endl;
		cout << "============================================" << endl;
	}
	
	for ( k=1; k<=n; k++ ) {
		orbit_value = get_orbit_value(k,n);
		goldbach_value=n-k;
		maillet_value=n+k;
		found_g_prime=check4prime(goldbach_value);
		found_m_prime=check4prime(maillet_value);
		found_k_prime=check4prime(k);

		if (orbit_value == k) {
			if (found_k_prime == true) {
				cout << "Prime-" << k << "\t\t";
			}
			else {
				if (k == 1) {
					cout << "Initial-" << k << "\t\t";
				}
				else {
					cout << "Amalgams-" << k << "\t\t";
				}
			}
			if (found_g_prime == true) {
				cout << goldbach_value;
				goldbach_total++;
			}
			cout << "|";
			if (found_m_prime == true) {
				cout << maillet_value;
				maillet_total++;
			}
			cout << endl;
		}
		else {
			if (k > n/2) {
				if ((orbit_value+1)*(goldbach_value)==n) {
                   	if (found_g_prime == true) {
                   		cout << "Multiple-" << k << "-" << orbit_value << "      ";
						cout << goldbach_value << " | ";
						goldbach_total++;
						prt_new_line=true;
					}
					if (found_m_prime == true) {
						cout << maillet_value;
						maillet_total++;
						prt_new_line=true;
					}
					if (prt_new_line==true) {
						cout << endl;
						prt_new_line=false;						
					}
				}
			}
		}
	}
	total_left_side_primes=count_primes_in_range(1,n);
	total_right_side_primes=count_primes_in_range(n,2*n);
	cout << "============================================" << endl;
	cout << "Total of Goldbach Primes: " << goldbach_total << endl;
	cout << "Total of Maillet Primes:  " << maillet_total << endl;
	cout << "Total Left Side Primes:   " << total_left_side_primes << endl;
	cout << "Total Right Side Primes:  " << total_right_side_primes << endl;
}

// End_Code
