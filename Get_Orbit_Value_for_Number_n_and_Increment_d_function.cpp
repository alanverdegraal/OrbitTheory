// Get_Orbit_Value_for_Number_n_and_Increment_d_function.cpp
// Created by Alan Verdegraal -- August 9, 2022
//
// This defines a function called get_orbit_value taking as inputs
// the number n and increment d. It returns the value of the
// Orbit On(d).
//
// This program generates the sequence specific to the nubmer n and
// the increment d calculating the value of the Orbit On(d) for that
// sequence. The "Orbit" On(m) is the number of circuits around the circle 
// with n points before it returns to 1. 
//
// This uses 64 bit number size with long long int
// Maximum value of any register is 9223372036854775807
// Since the formula involves n * n-1 the maximum number able to be processed 
// around the square root of the limit or 3032000000. Actual testing has
// demonstrated it can process up to the prime number 4,294,967,291.

#include <iostream>
#include <limits>
using namespace std;

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

int main() {
   long long int orbit_value;
   long long int d, n;

   cout << "Enter the value for n: ";
   cin >> n; 
   cout << "Enter the value for d: ";
   cin >> d;
      
   orbit_value = get_orbit_value(n,d);

   cout << "The Orbit Value for pair (n,d) is: " << orbit_value << endl;

}

// End Code

