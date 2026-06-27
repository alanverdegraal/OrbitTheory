// Brocard_Orbit_Structure_Full_Analysis.cpp
// Created by Alan Verdegraal   August 21, 2023
//
// The Brocard Orbit Structure is a Square Sq(a,b) where
// a is the square product of an odd prime number and
// b is the square product of the next prime number.
//
// The program does a full analysis of the Brocard Square
// Orbit Structure and prints out all the details.
// Since Brocard Squares get very large very quickly,
// a program such as this is necessary to investigate
// these very large Orbit Table objects.
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

long long int get_orbit_value (long long int n, long long int d) {
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

long long int get_next_prime (long long int n) {
	bool found_prime=false;
	long long int next_prime;
	
	n++;
	found_prime=check4prime(n);
	while (found_prime == false) {
		n++;
		found_prime=check4prime(n);
	}
	next_prime=n;
	return next_prime;
}

int main() {
   	bool found_prime=false, valid_input=true;
   	long long int first_prime, next_prime;
   	long long int prime1_squared, prime2_squared, mean, d;
   	long long int n, i, k=0, orbit_value, total_orbits_equal_to_d=0;
   	long long int lrov, rrov;
   
   	cout << "Enter the value for the lowest prime: ";
   	cin >> first_prime; 

   	found_prime=check4prime(first_prime);
   	if (found_prime == false) {
	   cout << "Entered number is not a prime. Exiting" << endl;
	   valid_input=false;   
	   }
	
	if (valid_input == true) {
		next_prime=get_next_prime(first_prime);
		prime1_squared = first_prime * first_prime;
		prime2_squared = next_prime * next_prime;
		
		cout << endl;
		cout << "=====================================================================" << endl;
		cout << "Full Analysis of Brocard Orbit Structure for Square Sq(";
		cout << prime1_squared << "," << prime2_squared << ")" << endl;
		cout << "=====================================================================" << endl;
		cout << endl;
		
		cout << "First Prime is " << first_prime << endl;
		cout << "Second Prime is " << next_prime << endl;
		
		cout << "First Prime squared is " << prime1_squared << endl;
		prime2_squared = next_prime * next_prime;
		cout << "Second Prime squared is " << prime2_squared << endl;	

		mean=(prime1_squared + prime2_squared)/2;
		cout << "The mean is " << mean << endl;
		d=(prime2_squared - prime1_squared)/2;
		cout << "The middle row is d=" << d << endl;
		
		cout << "The Orbit Value of the Kernel is ";
		orbit_value=get_orbit_value(mean,d);
		cout << orbit_value << endl;
		cout << endl;		
		
		cout << "List of primes between both squared primes:" << endl;
		for (i=prime1_squared; i<prime2_squared; i++) {
			next_prime=get_next_prime(i);
			if (next_prime < prime2_squared) {
				cout << next_prime << " ";
			}
			i=next_prime;
		}
		cout << endl;
		cout << endl;
		
		cout << "List of numbers from " << prime1_squared << " to " << prime2_squared << "." << endl;
		for (i=prime1_squared; i<prime2_squared; i++) {
			cout << i << ",";
		}
		cout << prime2_squared << endl;	
		cout << endl;
		
		cout << "List of Orbit Values on the Middle Row." << endl;
		for (i=prime1_squared; i<prime2_squared; i++) {
			orbit_value=get_orbit_value(i,d);
			if (orbit_value==d) {
				total_orbits_equal_to_d++;
			}
			cout << orbit_value << ",";
		}
		orbit_value=get_orbit_value(prime2_squared,d);
		cout << orbit_value << endl;
		total_orbits_equal_to_d++;
		cout << endl;
		
		cout << "Number of Orbit Values equivalent to d=" << d << " is ";
		cout << total_orbits_equal_to_d - 2 << "." << endl;
		cout << endl;
		
		cout << "All N meeting Rule 1 and Rule 2." << endl;
		total_orbits_equal_to_d = 0;
		i=1;
		for (k=prime1_squared+1; k<prime2_squared; k++) {
			orbit_value=get_orbit_value(k,d);
			if (orbit_value==d) {
				total_orbits_equal_to_d++;
				cout << "N="<< k << ":  ";
				cout << "OV=" << orbit_value << "  ";
				cout << "LROV=";
				lrov=get_orbit_value(k,i);
				cout << lrov << "  ";
				cout << "RROV=";
				rrov=get_orbit_value(k,(2*d)-i);
				cout << rrov << "  ";
				cout << "Sum=" << lrov + rrov;
				if (lrov+rrov!=2*d) {
					cout << "  **Sum implies not prime**";
				}
				cout << endl;
			}
			i++;
		}
		cout << endl;
		cout << "Total Max Values=" << total_orbits_equal_to_d << endl;	
	}
}

// End_Code
