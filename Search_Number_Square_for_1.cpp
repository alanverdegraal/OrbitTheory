// Search_Number_Square_for_1.cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
   int n, j=0;
   int cell_value = 0;
   int mod_value = 0; 
   bool found_1 = false;

   cout << "Enter the value for n: ";
   cin >> n; 

   if (n % 2 == 0) {
      cout << "Number is even. Try an odd number." << endl;
      j = n;
   }

   j++;
   while (j < n - 2) {
      cell_value = ((pow(n,2) - (2 * j * n) + pow(j,2) + 3 + (j % 2))/4);
      mod_value = cell_value % n;
      //cout << j << " " << cell_value << endl; 
      if (mod_value == 1) {
         cout << "Number " << n << " is a Composite Number." << endl;
         found_1 = true;
         j = n - 2;
      }
      j++;
   }
}
