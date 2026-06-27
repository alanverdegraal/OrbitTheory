// Get_Prime_Diff_Pairs_for_even_N_in Range.cpp
// Created by Alan Verdegraal October 3, 2022
//
// This will print out and count the Prime_Diff_Pairs
// for an even number through a given Range of N.
//
#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

bool check4prime(long long int n) {
   long long int j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_prime = false;
   if (n!=1) {
      found_prime = true;
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

int main() {
	bool found_prime = false;
	bool found_second_prime=false;
	long long int even_number;
	long long int orbit_value;
	long long int total_pairs=0;
	long long int beginning_value, ending_value;
    long long int j, d;
    
    cout << "Enter an Even number: ";
    cin >> even_number;
		cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 
    if (ending_value - beginning_value < 0) {ending_value = beginning_value;} 
                                // range must be > 0
    cout << endl;
   
    cout << "For an Even number, count of Prime Diff Pairs between and including " << beginning_value;
    cout << " and " << ending_value << endl;
    cout << "=========================" << endl;      
    
    for (j = beginning_value; j <= ending_value; j++) { 
        if (j%2==0) {
        	j++;
		}

		found_prime=check4prime(j);
		if (found_prime==true)  {
		found_second_prime=check4prime(j-even_number);
            if (found_second_prime==true){
                total_pairs++;
		        found_second_prime=false;
		        cout << even_number << " { " << j << " , " << j-even_number << " }" << endl;
	        }
            found_prime=false;
        }
    }    
}

// End_code
	