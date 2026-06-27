// Mining_for_Diamonds_Using_Staircase_Search_long_long.cpp
// Created by Alan Verdegraal -- August 4, 2022
//
// This accepts user input for a range of integer values.
// It follows the Staircase Search Path in looking for a 1
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
// This program also prints out the value for (p+1)/2 after each prime.
// If (p+1)/2 is even, then the prime has a near-Perfect Latin Square.
// If (p+1)/2 is odd, then the prime has a Perfect Latin Square.
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
using namespace std;

int main() {
   long long int n, j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   long long int beginning_value, ending_value;
   long long int count_of_diamonds = 0;
   long long int a, b = 0;
   long long int cell_value_2 = 0;
   long long int b4_mod_value_2 = 0; 
   int total_primes = 0;
   bool found_1 = false;
   bool ignore_composite_output = false;
   string answer;

   cout << "This program lists out Prime Diamonds";
   cout << " in a specified range of numbers." << endl;
   cout << endl;
   cout << "Enter the initial value of the range: ";
   cin >> beginning_value;
   cout << "Enter the final value of the range: ";
   cin >> ending_value; 

   n = beginning_value;
   while (n <= ending_value ) { 
      j = 1;
      if (n != 2) {
	     if ( n != 3) {
            if ( n % 2 == 0 ) {
            	found_1 = true;
			}
            else {
			    while (j < n - 2) {
                   b4_mod_value = (((n*n) - (2*j*n) + (j*j) + 3 + (j % 2))/4);
                   cell_value = b4_mod_value % n;
                   //cout << j << " " << cell_value << endl; 
                   if (cell_value == 1) {
                      found_1 = true;
                      j = n - 2;
                   }    
                   j++;
                } 
            } 
         }
      } 
      if (found_1 != true) {
//         cout << "Number " << n << " is Prime." << endl;
         // Check to see if n is a Prime Diamond pointing to a using Staircase search for a
         a=2*(n-1)+1;
//         cout << "a is " << a << endl;
         b=0;
         if (n != 2) {
		    if (n != 3) { 
//               cout << "Here I am" << endl;
	           b++;
               while (b < a - 2) {
                  b4_mod_value_2 = (((a*a) - (2*b*a) + (b*b) + 3 + (b % 2))/4);
                  cell_value_2 = b4_mod_value_2 % a;
//                  cout << a << " " << cell_value_2 << endl; 
                  if (cell_value_2 == 1) {
                     found_1 = true;
                     b = a - 2;
                  }
                  b++;
               } 
            }
		 }
         if (found_1 != true) {
            cout << "Prime " << n << " " << (n+1)/2 << " is a Prime Diamond and points to Prime " << a << " " << (a+1)/2 << "." << endl;
            count_of_diamonds++;
         }   
      }   	  
      n++;
      found_1 = false;
   } 
   cout << endl;
   cout << "The number of Prime Diamonds found in the Range is " << count_of_diamonds << "." << endl;
}

// End code
