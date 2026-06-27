// List_Primes_with_Fixed_Span.cpp
// Created by Alan Verdegraal January 3, 2023
// This creates a list of two primes that are
// separated by the entered span. By specifying
// a range, it will check every prime within
// that range.

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
	bool found_prime = false;
	bool found_second_prime=false;
	long long int total_pairs=0;
	long long int beginning_value, ending_value;
    long long int i, k;
    long long int span;
    
    cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 
    cout << "Enter the Span between Primes: ";
    cin >> span;
    
    if (span%2==1) { 
	    cout << "Please enter an even number for the Span." << endl;
	    system( "pause" );
	    exit;
	    beginning_value = ending_value + 999999;
	}
    
    cout << " " << endl;
    cout << "List of Primes with Fixed Span = " << span << endl;
	cout << "===========================================" << endl;

    for (i = beginning_value; i < ending_value; i++) { 
        if (i%2==0) {
        	i++;
		}
//		cout << i << "   ";
		found_prime=check4prime(i);
//		cout << found_prime << endl;
		if (found_prime==true) {
			k = i + span;
			found_second_prime=check4prime(k);
			if ((found_second_prime==true) && (k <= ending_value)) {
				cout << i << " " << k << endl;
				total_pairs++;
			}
		}
		found_prime = false;
		found_second_prime = false;
 	}
 	
 	cout << "===========================================" << endl;
 	cout << "Total Pairs = " << total_pairs << endl;
 	cout << "===========================================" << endl;
}

// End script
