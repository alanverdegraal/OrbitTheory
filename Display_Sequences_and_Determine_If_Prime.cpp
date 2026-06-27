// Display_Sequences_and_Determine_If_Prime.cpp
// Created by Alan Verdegraal -- June 13, 2022
//
// This program displays the arithmetic progressions modulo n for a 
// number n entered from the keyboard. These are the sequences generated 
// using increments from 1 to n. It calculates the "Orbit" On(m) for each sequence,
// that is, the number of circuits around the circle with n points before
// it reaches 1. It accumulates the sum of all these Orbits On(m) into total. 
// If n is prime, this sum should equal n(n-1)/2 + 1. If n is a composite number
// then the sum of all the Orbits On(m) will be less than n(n-1)/2 + 1.
// After checking, it will display a message whether the number is
// prime or composite

#include <iostream>
using namespace std;

int main() {
   int t, k, i, n, m, total;
   bool firsttime = true;

   cout << "Enter the value for n: ";
   cin >> n; 

   cout << "Increment  ...  Sequences  ...  Orbit On(m) of Sequence" << endl;
   cout << "=================================================" << endl;

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
           if (firsttime) {          // firsttime just prints out the first sequence value
               firsttime = false;
               if (k <= n + 1) {
                   cout << "m =  ";
                   cout << m;
                   cout << "     ";
                   if (k <= n) {
		               cout << k;
                       cout << " ";
		           }
               }
           }
           if (k > n) {
	           k -= n;             // k after the modulo operation: if k > n, then k = k - n
               t++;               // t being incremented when passing 1 on the circle, 
			                      //       increasing the Orbit for that sequence
           } 
           else {
               k += i;            // k being increased by the increment
           }
           if (k <= n) {          // printing out the next sequence value
               cout << k;
               cout << " ";
           }
        }
        cout << ";     ";
        cout << "On(m) = " << t << endl;   // printing out the Orbit for the particular sequence
        total += t;               // total being incremented for each completed Orbit t
        t = 0;                    // resetting the Orbit t for the next sequence
    }
    cout << "Total of all the Orbits On(m) is ";
    cout << total << endl;

    int value_if_prime = n*(n-1)/2 + 1;    // formula for the total of all Orbits On(m) 
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
