// Range_Search_for_Primes_Using_Right_Prime_Ray.cpp
// Created by Alan Verdegraal -- July 30, 2022
//
// This program uses the Right Prime Ray test to list prime numbers 
// within a range of values. It prints out a count at the end
// that can be used to verify that the correct number of primes
// has been found for the range.
//
// For each n, the process starts from the lowest value of k = n+1 
// and runs up to k = 2n-1. It uses the arithmetic progressions modulo k 
// for the calculation of the Orbit On(k). It accumulates the sum of all these 
// Orbits On(d) into total. If n is prime, this sum should equal n(n-1)/2. 
// If n is a composite number then the sum of all the Orbits On(d) will be 
// less than n(n-1)/2. After checking, it will display a message 
// whether the number is prime or composite.
// 
// If will check if the value of On(d) is the same as the increment d
// that must be equivalent if the number is prime. If it is not equivalent
// then the number is composite and the loop is exited.
//
// This uses 64 bit number size with long long int
// Maximum value of any register is 9223372036854775807
// Since the formula involves n * n-1 the maximum number able to be processed 
// around the square root of the limit or 3032000000. Actual testing has
// demonstrated it can process up to the prime number 4,294,967,291.
// However, for large numbers, it will take time since it computes all the
// terms of the sequences to determine On(d), which will be equal to n.

#include <iostream>
#include <limits>
using namespace std;

int main() {
   long long int t, k, i, j, n, beginning_value, ending_value, total, num_primes;
   long long int value_if_prime;
   long long start_inc, start_n;
   long long cur_n;
   bool composite_found;

   cout << "This program will list out prime numbers ";
   cout << "in a specified range of numbers." << endl;
   cout << endl;
   cout << "Enter the initial value of the range: ";
   cin >> beginning_value;
   if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
   cout << "Enter the final value of the range: ";
   cin >> ending_value; 
   if (ending_value - beginning_value <= 2) {ending_value = beginning_value + 3;} 
                                // range must be > 2
   cout << endl;
   
   cout << "List of Primes between and including " << beginning_value;
   cout << " and " << ending_value << endl;
   cout << "=========================" << endl;   

   num_primes=0;

   for (j = beginning_value; j <= ending_value; j++) { 
      n = j;                // Initializing the next number in the range
      if (n == 2) {
          cout << "The number " << n << " is a Prime Number." << endl;
	      num_primes++;     	 
	  }
      else if (n % 2 != 0) {
         // n is the odd number being checked. 
         // d is the increment that progresses from 1 to n for each sequence
         // firsttime indicates the first time each loop is being performed
         //          used to print out the very first sequence number.
         // i is the increment, the same as d
         t = 0;  // t is the total of times around the circle (the Orbit for d)
         k = 0;  // k is the current value of the sequence
         total = 0; // total is the sum of the Orbits for all sequences

         start_inc = 1; 
         start_n = n+1;
         i = start_inc;
         cur_n = start_n;
         composite_found = false;
         while ((cur_n <= 2*n - 1) && (composite_found == false)) { 
            k = i + 1;
            while (k != 1) {  
               if (k > cur_n) {
	               k -= cur_n;   // k after the modulo operation: 
				                 //         if k > n, then k = k - n
                   t++;       // t being incremented when passing 1 on the circle, 
			                  //   increasing the Orbit for that sequence
               } 
               else {
                   k += i;      // k being increased by the increment
               }
           }   
           if (t != i) {        // Test to see if On(d) = d required for a Prime
		      composite_found = true;
		   }
           total += t;          // total being incremented for each completed Orbit t
           t = 0;               // resetting the Orbit t for the next sequence
           cur_n++;
           i++;
        }
        value_if_prime = n*(n-1)/2;    // formula for the total of 
	                                     // all Orbits On(d) if n is prime
        if (total == value_if_prime) {  // Testing the total Orbits for n against the 
	                                   //       expected Orbits if n is prime
	       cout << "The number " << n << " is a Prime Number." << endl;
	       num_primes++;
  	    }
    }  
  }
  cout << endl;
  cout << "=========================" << endl;
  cout << "Total Primes in Range is " << num_primes << endl;
}

// End Code
