// Get_Eulers_Totient_Value_for_Range_of_n.cpp
// Created by Alan Verdegraal  June 13, 2023
//
// Euler's Totient Function f(n) is the sum of the
// numbers k < n where k is relatively prime to
// n. For n = 1, f(1)=1, thus 1 is considered
// relatively prime to all n.
//
// This program uses the Orbits On(d) to determine
// which numbers less than n are relatively prime
// where n = d. It uses the function get_orbit_value(d,n).
// 
// After entering a range for n, it computes the 
// Totient_Value for each n and prints out n and the value.
//

#include <iostream>
#include <limits>
using namespace std;

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
   long long int orbit_value, totient_total=0;
   long long int starting_value, ending_value;
   long long int i, d, n;
   
   cout << "Enter starting value of range: ";
   cin >> starting_value;
   cout << "Enter ending value of range: ";
   cin >> ending_value;
   cout << endl;

   for (i=starting_value; i<=ending_value; i++) {
   	   	n = i;
   	   	for (d=1; d<=n; d++) {
       		orbit_value=get_orbit_value(d,n);
       		if (orbit_value==d) {
       	   		totient_total++;
	   		}
   		}
        cout << n << "  " << totient_total << endl;
        totient_total=0;
	}
}

// End_code
