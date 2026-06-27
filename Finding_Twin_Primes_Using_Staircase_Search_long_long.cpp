// Finding_Twin_Primes_Using_Staircase_Search_long_long.cpp
// Created by Alan Verdegraal -- August 9, 2022
//
// This program looks for Twin Primes in a specified range.
// This accepts user input for a range of integer values.
// It follows the Staircase Search Path in looking for a 1
// in a Square Sq(n) to determine if the number n is a Composite number.
//
// If it does not find a 1 through the Staircase Search, then
// it will check the number p + 2 to see if that is prime using
// the Staircase Search for a 1 for a Composite number. If it does
// not find a 1, meaning that p + 2 is also a prime, it has found
// a Twin Prime pair and will print those out.
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
   long long int count_of_twins = 0;
   long long int a, b = 0;
   long long int cell_value_2 = 0;
   long long int b4_mod_value_2 = 0; 
   int total_primes = 0;
   bool found_1 = false;
   bool ignore_composite_output = false;
   string answer;

   cout << "This program lists out Twin Primes";
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
	  else {
	     found_1 = true;
	  } 
      if (found_1 != true) {
//         cout << "Number " << n << " is Prime." << endl;
         // Check to see if n is the first member of a Twin Prime pointing to a using Staircase search
         a=n+2;
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
            cout << "Prime " << n << " " << (n+1)/2 << " and Prime " << a << " " << (a+1)/2 << " are Twin Primes." << endl;
            count_of_twins++;
         }   
      }   	  
      n++;
      found_1 = false;
   } 
   cout << endl;
   cout << "The number of Twin Primes found in the Range is " << count_of_twins << "." << endl;
}

// End code
