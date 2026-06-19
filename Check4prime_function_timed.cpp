// Check4prime_function_timed.cpp
// Created by Alan Verdegraal -- August 9, 2022
// Modified by Alan Verdegraal -- February 1, 2026
//      Added timing.
//
// This creates a function called check4prime that takes an integer
// as input and returns the boolean found_prime.
//
// This follows the Staircase Search Path in looking for a 1
// in a Square Sq(n) to determine if the number n is a Composite number.
// It starts at the Kernel cell K11(n), moving right and up, in a
// staircase fashion. If it finds a 1 as the value in any cell, then
// Square Sq(n) is a composite number.
//
// If it does not find a 1 through the Staircase Search, then
// it prints a message indicating that n is a Prime. This is 
// based upon the Staircase Conjecture that for any Composite number 
// there is a 1 on the main diagonal of the Latin Square LS(n) 
// or immediately adjacent to it. This has been demonstrated to be
// accurate for all Composites and Primes up through 1,000,000.
//
// This C++ program uses 64 bit number size with data type long long int.
// Maximum value of any register is the limit 9223372036854775807
// Since the formula of the Staircase Search Path involves squaring n
// the maximum number able to be processed is the square root of the limit
// or 3032000000.
//
// However, through testing, the maximum Prime that my Windows 10 64-bit 
// laptop can identify is 4294967291. Beyond that, the limits begin to 
// identify known Primes as Composites due to exceeding system limits.

#include <iostream>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;


bool check4prime(long long int n) {
   long long int j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_prime = true;

   if (((n%2==0) && (n!=2)) || (n==1)) {
   	  found_prime=false;
   }
   else {
	   	j++;
   		while (j < n - 2) {
      		b4_mod_value = (((n*n) - (2*j*n) + (j*j) + 3 + (j % 2))/4);
      		cell_value = b4_mod_value % n;
      		if (cell_value == 1) {
         		found_prime = false;
         		j = n - 2;
      		}
      		j++;
      }
   }
   return found_prime;
}

int main() {
   bool found_prime = false;
   long long int nn;

   time_t timestamp;
	
   cout << "===================================" << endl;
   cout << "Check4prime_function_timed.cpp" << endl;
   cout << "===================================" << endl;	   
   cout << "Enter the value for n: ";
   cin >> nn; 
   cout << "===================================" << endl;	
   time(&timestamp);	
   cout << "Start date and time: " << ctime(&timestamp);
   cout << "===================================" << endl;	

   found_prime = check4prime(nn);

   if (found_prime == true) {
   	   cout << endl;
       cout << "Number " << nn << " is Prime." << endl;
   }
   else {
       cout << endl;
	   cout << "Number " << nn << " is Composite." << endl;
   }
   time(&timestamp);
   cout << endl;
   cout << "===================================" << endl;
   cout << "End date and time: " << ctime(&timestamp);
   cout << "===================================" << endl;
}

// End code

