// Primes_in_a_Range_long_long.cpp
// Created by Alan Verdegraal -- Created June 13, 2022
//
// This program accepts a range of numbers to determine the
// prime numbers found within that range.
//
// This program does not displays the arithmetic progressions for a number n 
// within the range. These are the sequences generated using
// increments from 1 to n. It calculates the "Orbit" On(m) for each sequence,
// that is, the number of circuits around the circle with n points before
// it reaches 1. It is based upon a Theorem that if a number is prime,
// the Orbit On(m) of each sequence where the increment < n is equivalent to the 
// increment. 
//
// As it goes along, it accumulates the sum of all these Orbits On(m)=t into
// total. If n is Prime, this sum should equal n(n-1)/2 + 1. If n is a composite 
// number then the sum of all the Orbits On(m) will be less than n(n-1)/2 + 1.
// If the Orbit On(m) of any sequence is not equal to the increment, then
// that number is a composite and calculations skip to the next number
// in the range. When it finds a Prime number, then it prints that out
// and continues processing the next number in the range.

// This uses 64 bit number size with long long int
// Maximum value of any register is 9223372036854775807
// Since the formula involves n * n-1 the maximum number able to be processed 
// is the square root of the limit or about 3032000000.

#include <iostream>
#include <limits>
using namespace std;

int main() {
   long long int t, k, i, j, n, m, beginning_value, ending_value, total;
   long long int value_if_prime;
   
   cout << "This program will list out prime numbers in a specified range of numbers." << endl;
   cout << endl;
   cout << "Enter the initial value of the range: ";
   cin >> beginning_value;
   if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
   cout << "Enter the final value of the range: ";
   cin >> ending_value; 
   if (ending_value - beginning_value <= 2) {ending_value = beginning_value + 3;} 
                                // range must be > 2
   cout << endl;
   
   // j is the incrementing value for the range
   // n is the modulo number 
   // m is the increment that progresses from 1 to n for each sequence
   // i is the increment, the same as m
   t = 0;  // t is the total of times around the circle (the Orbit for m)
   k = 0;  // k is the current value of the sequence
   total = 0; // total is the sum of the Orbits for all sequences 

   for (j = beginning_value; j <= ending_value; j++) { 
      n = j;                // Initializing the next number in the range
      for (m = 1; m <= n; m++) {
         i = m;
         k = 1 + i;         // starting value of the sequence

         while (k != 1) {
            if (k > n) {
	            k -= n;       // k after the modulo operation: if k > n, then k = k - n
                t++;          // t being incremented when passing 1 on the circle, 
				              //       increasing the Orbit for that sequence
            } 
            else {
                k = k + i;    // k being increased by the increment
            }
         }
         
         if (t != m) {          // testing if the Orbit is equal to the increment, 
		                        //           if not, number is composite
             // n is a composite number, skip rest of sequences
             m = n + 1;         // setting the loop value of m so it exits 
			                    //       the for loop for this number
         }
         total += t;     // total being incremented for each completed Orbit t
         t = 0;          // resetting the Orbit t for the next sequence
      }
      value_if_prime = n*(n-1)/2 + 1;   // formula for the total of all Orbits On(m) 
	                                        //         if n is prime

      if (total == value_if_prime) {   // Testing the total Orbits On(m) for n against 
	                                   //          the expected Orbits
         cout << "The number " << n << " is a Prime Number." << endl;  // print out prime number
      }
      total = 0;         // Reseting total for the next number m to check.
   }
}

// End code
