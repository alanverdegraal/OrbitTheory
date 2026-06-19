// Get_Orbit_List_function_long_long.cpp
// Created by Alan Verdegraal -- August 16, 2022
//
// This defines a function called get_orbit_list taking as input
// the number n. It returns a string with the values for Orbit On(d)
// for number n.
//
// This program generates the sequence specific to the number n 
// calculating the value of the Orbit On(d) for that number n. 
// The "Orbit" On(m) is the number of circuits around the circle 
// with n points before it returns to 1. 
//
// This uses 64 bit number size with long long int
// Maximum value of any register is 9223372036854775807
// Since the formula involves n * n-1 the maximum number able to be processed 
// around the square root of the limit or 3032000000. Actual testing has
// demonstrated it can process up to the prime number 4,294,967,291.

#include <iostream>
#include <limits>
#include <string>   
#include <sstream>   
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

string get_orbit_list(long long int n) {
   long long int orbit_value;
   long long int d;
   long long int i=1;
   stringstream ss;
   string orbit_list;

   
   while (i<=n) {
   	  d=i;
      orbit_value = get_orbit_value(n,d);
      ss << orbit_value << " ";
      i++;
   }
   orbit_list = ss.str();
   return orbit_list;
}

int main() {

   long long int n;
   string orbit_list;
   
   cout << "Enter the value for n: ";
   cin >> n; 

   orbit_list = get_orbit_list(n);

   cout << orbit_list << endl;

}

// End_code
