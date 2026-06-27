// Temple_An_Search_for_1_long_long.cpp
// Created by Alan Verdegraal -- June 29, 2022
//
// This follows the Staircase Search Path in looking for a 1
// in a Square Sq(n) to determine if the number n is a Composite number.
// It starts at the Kernel cell K11(n), moving right and up, in a
// staircase fashion. If it finds a 1 as the value in any cell, then
// Square Sq(n) is a composite number.

// If it does not find a 1 through the Staircase Search, then
// it prints a message suggesting that n may be Prime. This is 
// because the Staircase Search is based upon the Conjecture that
// for any Composite number there is a 1 on the main diagonal 
// or immediately adjacent to it. If so, other prime determination 
// methods are needed.
 
// This uses 64 bit number size with long long int
// Maximum value of any register is the limit 9223372036854775807
// Since the formula of the Staircase Search Path involves squaring n
// the maximum number able to be processed is the square root of the limit
// or 3032000000.

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

int main() {
   long long int n, j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_1 = false;

   cout << "Enter the value for n: ";
   cin >> n; 

   if (n % 2 == 0) {
      cout << "Number is even. Try an odd number." << endl;
      j = n;
   }

   j++;
   while (j < (n - 5)/2) {
      b4_mod_value = ((pow(n,2) - (2 * j * n) - (4 * n) + 7 + (j * 6))/4);
      cell_value = b4_mod_value % n;
      cout << j << " " << cell_value << endl; 
      //if (cell_value == 1) {
      //	 cout << endl;
      //   cout << "Number " << n << " is a Composite Number." << endl;
      //   found_1 = true;
      //   j = n - 2;
      //}
      j++;
   }
   //if (found_1 != true) {
   //	   cout << endl;
   //    cout << "Number " << n << " may be Prime." << endl;
   //}
}

