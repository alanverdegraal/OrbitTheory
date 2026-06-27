// Determine_If_Number_Is_Prime.cpp
// Created by Alan Verdegraal -- June 12, 2020

// This program does not displays the arithmetic progressions for a number n 
// entered from the keyboard. These are the sequences generated using
// increments from 1 to n. It calculates the "Orbit" On(m) for each sequence,
// that is the number of circuits around the circle with n points before
// it reaches 1. It accumulates the sum of all these Orbits On(m) into total. 
// If n is prime, this sum should equal n(n-1)/2 + 1. If n is a composite 
// number then the sum of all the Orbits On(m) will be less than n(n-1)/2 + 1.
// After checking, it will display a message whether the number is
// prime or composite

#include <iostream>
using namespace std;

int main() {
    int t, k, i, n, m, total;

    cout << "Enter the value for n: ";
    cin >> n; 
    cout << endl;
    
    // n is the modulo number 
    // m is the counter that progresses from 1 to n for each sequence.
    t = 0;  // t is the total of times around the circle (the Orbit for m)
    k = 0;  // k is the current value of the sequence.
    // i is the increment, the same as m
    total = 0; // total is the sum of the Orbits for all sequences 

    for (m = 1; m <= n; m++) {
        i = m;
        k = i + 1;          // starting value of the sequence
        while (k != 1) {    // if k = 1 then the sequence has completed
            if (k > n) {
	            k -= n;    // k after the modulo operation: if k > n, then k = k - n
                t++;       // t being incremented when passing 1 on the circle, 
				           //             increasing the Orbit for that sequence
            } 
            else {
                k += i;    // k being increased by the increment
            }
       }

       total += t;        // total being incremented for each completed Orbit t
       t = 0;             // resetting the Orbit t for the next sequence
    }
    cout << "Total of all the Orbits On(m) )is " << total << endl;

    int value_if_prime = n*(n-1)/2 + 1;      // formula for the total of all Orbits if n is prime
    cout << "If n is Prime, then the total of all Orbits On(m) should be " << value_if_prime << endl;
    cout << endl;
    
    if (total == value_if_prime) {          // Testing the total Orbits for n against the 
	                                        //            expected Orbits if n is prime
	    cout << "The number " << n << " is a Prime Number." << endl;
	}
    else {
	    cout << "The number " << n << " is a Composite Number." << endl;
	}
}

// End code
