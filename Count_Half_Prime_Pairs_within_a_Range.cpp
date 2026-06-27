// Count_Half_Prime_Pairs_within_a_Range.cpp
// Created by Alan Verdegraal September 16, 2022
//
// This generates a count of Prime Pairs (two primes
// that sum to an even number) for all even numbers
// within a specified range. It displays the Prime Pairs
// as it proceeds, which is helpful for very large numbers
// that can take days to run, so one can see that the 
// program is actually working.
//
// Since the first half Prime Pairs are reversed mirrored
// in the second half, to cut down on processing time
// we only need to count the Prime Pairs in the first half
// where i <= n/2. The count at the end is then multiplied
// by 2 in order to determine the total count of Prime Pairs.
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
	long long int orbit_value;
	long long int total_pairs=0;
	long long int beginning_value, ending_value;
    long long int i, j, n;
    
    cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 
    if (ending_value - beginning_value < 0) {ending_value = beginning_value;} 
                                // range must be > 0
    cout << endl;
   
    cout << "Count of Prime Pairs for Even numbers between and including " << beginning_value;
    cout << " and " << ending_value << endl;
    cout << "=========================" << endl;      
    
    for (j = beginning_value; j <= ending_value; j++) { 
        n=j;
        if (n%2==1) {
        	n++;
        	j++;
		}
        for (i=3; i<=n/2; i++) {
            if (i%2==1) {
                orbit_value=get_orbit_value(i,n);
	            found_prime=check4prime(orbit_value);
	            if (((found_prime==true) && (orbit_value==i)) || ((orbit_value==1) && (n/2==n-i) && (i%2==1))) {
                   found_second_prime=check4prime(n-i);
                   if (found_second_prime==true){
                      total_pairs++;
		              found_second_prime=false;
		              cout << n << " { " << i << " , " << n-i << " }" << endl;
	               }
                   found_prime=false;
                }    
            } 
        }        
        cout << "Total Prime Pairs for " << n << ":  " << total_pairs * 2 << endl;
        total_pairs=0;
    }
}

// End_Code


