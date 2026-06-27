// List_All_Non_SG_and_Non_HM_Prime_Pairs.cpp
// Created by Alan Verdegraal July 13, 2023
//
// Sophie Germain Primes with their associated 
// Safe Primes meet the criterion that P2=2P1+1.
// Both of these are Low Metacore Primes.
// High Metacore Prime Pairs meet the condition
// that P2=2P1-1. 
//
// This program looks for any prime that is not
// a Sophie Germain Prime having a Safe Prime, 
// as well as any prime that is not a High 
// Metacore Prime with its associated Prime.
//

#include <iostream>
#include <math.h>
#include <limits>
#include <iomanip>
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
	bool found_second_prime = false;
	bool found_third_prime = false;
	long long int beginning_value, ending_value;
    long long int i, j, k;
 
    cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 
    cout << endl;

    for (i = beginning_value; i < ending_value; i++) { 
		found_first_prime=check4prime(i);
		if (found_first_prime==true) {
			j=2*i+1;
			found_second_prime=check4prime(j);
			k=2*i-1;
			found_third_prime=check4prime(k);
			if ((found_second_prime==false) && (found_third_prime==false)) {
				cout << i << endl;
			}	
		}
	}
}

// End Code
