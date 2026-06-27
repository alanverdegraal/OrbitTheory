// Display_Orbit_Values_Only_for_N.cpp
// Created by Alan Verdegraal -- July 25, 2022
//
// This program displays the arithmetic progressions modulo n for a 
// number n entered from the keyboard. It only displays the values
// of the Orbits that makes it easy to copy and paste into a
// spreadsheet package. These Orbits are based upon sequences generated 
// using increments from 1 to n. It calculates the "Orbit" On(d) for each 
// sequence, that is, the number of circuits around the circle with n points 
// before it reaches 1. It accumulates the sum of all these Orbits On(d) into 
// total. If n is prime, this sum should equal n(n-1)/2 + 1. If n is a composite 
// number then the sum of all the Orbits On(d) will be less than n(n-1)/2 + 1.
// After checking, it will display a message whether the number is
// prime or composite.
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
        t = 0;                    // resetting the Orbit t for the next sequence
    }
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Total of all the Orbits On(d) is ";
    cout << total << endl;

    value_if_prime = n*(n-1)/2 + 1;    // formula for the total of 
	                                // all Orbits On(d) if n is prime
    cout << "If n is Prime, then the total of all Orbits On(d) should be ";
	cout << value_if_prime << endl;
    cout << endl;

    if (total == value_if_prime) {        // Testing the total Orbits for n against the 
	                                      //       expected Orbits if n is prime
	    cout << "The number " << n << " is a Prime Number." << endl;
	}
    else {
	    cout << "The number " << n << " is a Composite Number." << endl;
	}
}

// End Code
