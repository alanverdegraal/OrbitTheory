// List_Prime_Gaps_within_Range.cpp
// Created by Alan Verdegraal June 17, 2023
// 
// A prime gap is the difference between two
// consecutive primes.
//
// After taking starting_value and ending_value
// of a range, it will check each number 
// for a prime and then counts the number of cells
// in the gap before the next prime is reached.
// It prints out both primes and the size of the
// gap.
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

int main() {
	bool found_first_prime = false;
	bool found_second_prime=false;
	long long int gap=0;
	long long int beginning_value, ending_value;
    long long int i, j;
    
    cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 

    for (i = beginning_value; i < ending_value; i++) { 
		found_first_prime=check4prime(i);
		if (found_first_prime==true) {
			gap=0;
			for (j=i+1; j < ending_value; j++) {
				gap++;
			 	found_second_prime=check4prime(j);
				if ((found_second_prime==true) && (j <= ending_value)) {
				    cout << i << " " << j << " " << gap << endl;
				    i=j;
				    gap=0;
				}
			}
		}	
 	}
}

// End script  
 