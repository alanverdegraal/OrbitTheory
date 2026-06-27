// Display_Orbit_Values_Only_for_N_First_5000.cpp
// Created by Alan Verdegraal -- July 25, 2022
//
// This program displays the arithmetic progressions modulo n for a 
// number n entered from the keyboard. It only displays the values
// of the Orbits that makes it easy to copy and paste into a
// spreadsheet package. These Orbits are based upon sequences generated 
// using increments from 1 to n. It calculates the "Orbit" On(d) for each 
// sequence, that is, the number of circuits around the circle with n points 
// before it reaches 1. 
//
// This particular version calculates only the first 5000 orbit values.
// There is a parameter at the start of main() called max_d which can be
// reset to limit the number of rows of Orbit values being calculated before
// stopping the loop.
//
// This version does not check whether the number is either a composite or
// prime. To determine primes, run the program Determine_If_Number_Is_Prime.cpp
// which doesn't display Orbit Values for n increasing the bounds for 
// determining primes.
//
// This uses 64 bit number size with long long int
// Maximum value of any register is 9223372036854775807
// Since the formula involves n * n-1 the maximum number able to be processed 
// around the square root of the limit or 3032000000. Actual testing has
// demonstrated it can process up to the prime number 4,294,967,291.

#include <iostream>
#include <limits>
using namespace std;

int main() {
   long long int t, k, i, n, d, total;
   long long int value_if_prime;
   long long max_d=200;

   cout << "Enter the value for n: ";
   cin >> n; 
   cout << endl;
   cout << "List of Orbits for Number " << n << endl;
   cout << "Orbit On(d) of Sequence" << endl;
   cout << "=========================" << endl;

   // n is the modulo number 
   // d is the increment that progresses from 1 to n for each sequence
   // firsttime is a flag to indicate the first time each loop is being performed
   //          used to print out the very first sequence number.
   // i is the increment, the same as d
   t = 0;  // t is the total of times around the circle (the Orbit for d)
   k = 0;  // k is the current value of the sequence
   total = 0; // total is the sum of the Orbits for all sequences


   for (d = 1; d <= n; d++) {  
      i = d;
      k = 1 + i;                      // starting value of the sequence

        while (k != 1) {  
           if (k > n) {
	           k -= n;       // k after the modulo operation: if k > n, then k = k - n
               t++;          // t being incremented when passing 1 on the circle, 
			                 //       increasing the Orbit for that sequence
           } 
           else {
               k += i;            // k being increased by the increment
           }
        }
        cout << t << endl;   // print the Orbit for the particular sequence
        total += t;               // total being incremented for each completed Orbit t
        t = 0;                // resetting the Orbit t for the next sequence
		if (d>max_d) {        // Maximum number of rows being calculated
		     d = n+1;
		}
    }
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;

}

// End Code
