// Mining_for_Prime_Diamonds.cpp
// Created by Alan Verdegraal -- July 31, 2022
//
// Prime diamonds are prime numbers whose bottom right
// edge points to another prime number, i.e., the bottom
// right edge is part of the Left Prime Ray for another prime.
// Possible candidates are of of the form p2=2*(p1-1)+1.
// The program uses the Orbit method to determine if n within
// the range is a prime, then checks the value of p2 using
// the staircase search to determine if p2 is a prime.

#include <iostream>
#include <limits>
using namespace std;

int main() {
   long long int t, k, i, j, n, m, beginning_value, ending_value, total;
   long long int value_if_prime;
   bool prime_found=false;
   long long int count_of_diamonds=0;
   
   cout << "This program will list Prime Diamonds in a specified range of numbers." << endl;
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
         prime_found=true;
      }
      total = 0;         // Reseting total for the next number m to check.
      
      if (prime_found == true) {
         long long int a, b = 0;
         long long int cell_value = 0;
         long long int b4_mod_value = 0; 
         bool found_1 = false;

         // Check to see if n is a Prime Diamond pointing to a using Staircase search for a
         a=2*(n-1)+1;

         if (a % 2 == 0) {
            b = a;
         }

         b++;
         while (b < a - 2) {
            b4_mod_value = (((a*a) - (2 * b * a) + (b*b) + 3 + (b % 2))/4);
            cell_value = b4_mod_value % a;
            //cout << a << " " << cell_value << endl; 
            if (cell_value == 1) {
               found_1 = true;
               b = a - 2;
            }
            b++;
         }
         if (found_1 != true) {
            cout << "Prime " << n << " is a Prime Diamond and points to Prime " << a << "." << endl;
            count_of_diamonds++;
         }   
         prime_found=false;
      }   	  
   }
   cout << endl;
   cout << "The number of Prime Diamonds found in the Range is " << count_of_diamonds << "." << endl;
}

// End code
