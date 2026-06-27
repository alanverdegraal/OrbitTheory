// Display_Orbit_Only_2_long_long.cpp
// Created by Alan Verdegraal -- June 22, 2022
//
// This program does not displays the arithmetic progressions modulo n for a 
// number n entered from the keyboard. These are the sequences generated 
// using increments from 1 to n. It calculates the "Orbit" On(m) for each sequence,
// that is, the number of circuits around the circle with n points before
// it reaches 1. It accumulates the sum of all these Orbits On(m) into total. 
// If n is prime, this sum should equal n(n-1)/2 + 1. If n is a composite number
// then the sum of all the Orbits On(m) will be less than n(n-1)/2 + 1.
// After checking, it will display a message whether the number is
// prime or composite. This was created to make it simple to copy the
// Orbits On(m) from the screen to a column in a spreadsheet.

// This uses 64 bit number size with long long int
// Maximum value of any register is 9223372036854775807
// Since the formula involves n * n-1
// the maximum number able to be processed is the square root of the limit
// or 3032000000.

#include <iostream>
#include <limits>
using namespace std;

int main() {
   long long int t, k, i, n, m, total;
   long long int value_if_prime;
   bool firsttime = true;

   cout << "Enter the value for n: ";
   cin >> n; 

   cout << "Orbit On(m) of Sequence" << endl;
   cout << "=======================" << endl;

   // n is the modulo number 
   // m is the increment that progresses from 1 to n for each sequence
   // firsttime is a flag to indicate the first time each loop is being performed
   //          used to print out the very first sequence number.
   // i is the increment, the same as m
   t = 0;  // t is the total of times around the circle (the Orbit for m)
   k = 0;  // k is the current value of the sequence
   total = 0; // total is the sum of the Orbits for all sequences


   for (m = 1; m <= n; m++) {  
      firsttime = true; // first time loop is entered
      i = m;
      k = 1 + i;                      // starting value of the sequence

        while (k != 1) {  
           if (k > n) {
	           k -= n;             // k after the modulo operation: if k > n, then k = k - n
               t++;               // t being incremented when passing 1 on the circle, 
			                      //       increasing the Orbit for that sequence
           } 
           else {
               k += i;            // k being increased by the increment
           }
        }
        cout << t << endl;   // printing out the Orbit for the particular sequence
        total += t;               // total being incremented for each completed Orbit t
        t = 0;                    // resetting the Orbit t for the next sequence
    }
    cout << "Total of all the Orbits On(m) is ";
    cout << total << endl;

    value_if_prime = n*(n-1)/2 + 1;    // formula for the total of all Orbits On(m) 
	                                       //        if n is prime
    cout << "If n is Prime, then the total of all Orbits On(m) should be " << value_if_prime << endl;
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
