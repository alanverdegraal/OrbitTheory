// Display_Orbit_Values_for_Left_Prime_Ray.cpp
// Created by Alan Verdegraal -- July 29, 2022
//
// This program displays the Orbit values for the Left Prime Ray
// starting from the lowest value of k = (n+1)/2 and running up to 
// k = n-1. It uses the arithmetic progressions modulo k for the 
// calculation of the Orbit On(k). It accumulates the sum of all these 
// Orbits On(d) into total. If n is prime, this sum should equal (n-1)(n+1)/2. 
// If n is a composite number then the sum of all the Orbits On(d) will be 
// less than (n-1)(n+1)/2. After checking, it will display a message 
// whether the number is prime or composite.
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
   long long int t, k, i, n, total;
   long long int value_if_prime;
   long long start_inc, start_n;
   long long cur_n;

   cout << "Enter the value for n: ";
   cin >> n; 
   cout << endl;
   if (n % 2 == 0) {
      cout << "An even number was entered. ";
	  cout << "Only odd numbers can be checked." << endl; 
   } 
   else {
       cout << "List of Left Prime Ray Orbits for Number " << n << endl;
       cout << "k    Increment_d     Ok(d)" << endl;
       cout << "=========================" << endl;

       // n is the odd number being checked. 
       // d is the increment that progresses from 1 to n for each sequence
       // firsttime is a flag to indicate the first time each loop is being performed
       //          used to print out the very first sequence number.
       // i is the increment, the same as d
       t = 0;  // t is the total of times around the circle (the Orbit for d)
       k = 0;  // k is the current value of the sequence
       total = 0; // total is the sum of the Orbits for all sequences

       start_inc = (n+1)/2 - 1; 
       start_n = (n+1)/2;
       i = start_inc;
       cur_n = start_n;
       while (cur_n <= n - 1) { 
           k = i + 1;
           while (k != 1) {  
               if (k > cur_n) {
	               k -= cur_n;   // k after the modulo operation: 
				                 //         if k > n, then k = k - n
                   t++;          // t being incremented when passing 1 on the circle, 
			                     //       increasing the Orbit for that sequence
               } 
               else {
                   k += i;       // k being increased by the increment
               }
           }   
           cout << cur_n << "    " << i << "    " << t << endl;   // print 
           total += t;           // total being incremented for each completed Orbit t
           t = 0;                // resetting the Orbit t for the next sequence
           cur_n++;
           i--;
       }
       cout << endl;
       cout << "--------------------------------" << endl;
       cout << endl;
       cout << "Total of all the Orbits On(d) is ";
       cout << total << endl;
       cout << endl;
     
       value_if_prime = (n+1)*(n-1)/8;    // formula for the total of 
	                                     // all Orbits On(d) if n is prime
       cout << "If n is Prime, then the total of all Left Prime Ray ";
	   cout << "Orbits On(d) should be ";
	   cout << value_if_prime << endl;
       cout << endl;

       if (total == value_if_prime) {  // Testing the total Orbits for n against the 
	                                   //       expected Orbits if n is prime
	       cout << "The number " << n << " is a Prime Number." << endl;
	   }
       else {
	       cout << "The number " << n << " is a Composite Number." << endl;
	   }
   }  
}

// End Code
