// Staircase_Search_for_1.cpp
// Created by Alan Verdegraal -- June 29, 2022
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

   j++;
   while (j < n - 2) {
      b4_mod_value = (((n*n) - (2*j*n) + (j*j) + 3 + (j % 2))/4);
     
      cell_value = b4_mod_value % n;
      if (cell_value == 1) {
         cout << endl;
         cout << "Number " << n << " is a Composite Number." << endl;
         found_1 = true;
         j = n - 2;
      }
      j++;
   }
   if (found_1 != true) {
       cout << endl;
       cout << "Number " << n << " is Prime." << endl;
   }
}
// End code
