// Perf_Test_Full_Temple_Search_for_1_long_long.cpp
// Full_Temple_Search_for_1_long_long.cpp
// Created by Alan Verdegraal -- July 9, 2022
//
// This follows the Temple Search Path in looking for a 1
// in a Square Sq(n) to determine if the number n is a Composite number.
// It starts at the first diagonal to the upper left of theKernel cell K11(n).
// It then calculates the cell values in that row goint to the left, 
// then moves to the next diagonal cell in the upper left, and processes 
// that row to the left. If it finds a 1 as the value in any cell, then
// Square Sq(n) is a composite number and it stops searching.

// If it does not find a 1 through the Temple Search, then
// it prints a message indicating that n is Prime. 
 
// This uses 64 bit number size with long long int
// Maximum value of any register is the limit 9223372036854775807
// Since the formula of the Staircase Search Path involves squaring n
// the maximum number able to be processed is the square root of the limit
// or 3032000000.

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

int main( int argc, char *argv[] ) {
   long long int n, i = 0;
   long long int j = 1;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_1 = false;
   bool found_even = false;

   n = stoll( argv[1] );

   if (n % 2 == 0) {
      cout << endl;
      cout << "Number " << n << " is an even Composite." << endl;
      found_even = true;
   }

   while ((i <= ((n - 1)/2)-4) && (found_even == false)) {  
   	  j=1;
      while (j <= ((n-(2*i+5))/2)-1) {
         b4_mod_value = ((n*n)-(2*j*n)-(4*(i+1)*n)+(4*(i+1)+2)*j+(i*i*4)+(8*i)+7)/4;
         cell_value = b4_mod_value % n;
         if (cell_value == 1) {
           cout << endl;
           cout << "Number " << n << " is a Composite Number." << endl;
           found_1 = true;
           j = n - 2;
           i = n - 2;
         }
         j++;
      } 
	  i++; 	
   }
   if ((found_1 == false) && (found_even == false)) { 
   	   cout << endl;
       cout << "Number " << n << " is Prime." << endl;
   }
}

// End code
