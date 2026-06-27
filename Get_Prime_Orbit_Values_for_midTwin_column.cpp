// Get_Prime_Orbit_Values_for_midTwin_column.cpp
// Created by Alan Verdegraal -- August 9, 2022
//
// This gets the Orbit values for where the midTwin column
// intersects with Left Prime Rays. The midTwin is the number
// n that is between a pair of Twin Primes.
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
	bool found_prime = false;
	long long int orbit_value;
    long long int i, n;
    
    cout << "Enter the number of the midTwin:  ";
    cin >> n;
    cout << endl;
    
    for (i=n+1; i<=2*n; i++) {
	   found_prime=check4prime(i);
	   if (found_prime==true) {
          orbit_value=get_orbit_value(i-n,n);
          if (orbit_value==i-n){
             cout << i-n << endl;
		  }
	   } 
	} 
}

// End_Code
