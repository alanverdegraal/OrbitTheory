// Display_Orbit_Values_Only_for_N_in_Base_6.cpp
// Created by Alan Verdegraal -- January 24, 2023
//
// This program displays the Orbit values for n
// in base-6.

#include <iostream>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Function to convert a given decimal number
// to a base 'base' and
string fromDeci(string& res, int base, int inputNum)
{
    int index = 0; // Initialize index of result
 
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0) {
        res.push_back(reVal(inputNum % base));
        index++;
        inputNum /= base;
    }
 
    // Reverse the result
    reverse(res.begin(), res.end());
 
    return res;
}
 

int main() {
   long long int t, k, i, n, d, total;
   long long int value_if_prime;
   int inputNum, base=6;

   cout << "Enter the value for n: ";
   cin >> n; 
   cout << endl;
   cout << "List of Orbits for Number in Base-6 for n = " << n << endl;
   cout << "Orbit On(d) of Sequence" << endl;
   cout << "=========================" << endl;

   // n is the modulo number 
   // d is the increment that progresses from 1 to n for each sequence
   // firsttime is a flag to indicate the first time each loop is being performed
   //          used to print out the very first sequence number.
   // i is the increment, the same as d
   t = 0;  // t is the total of times around the circle (the Orbit for d)
   k = 0;  // k is the current value of the sequence
   total = 0; // total is the sum of the Orbits for all sequences


   for (d = 1; d <= n; d++) {  
      i = d;
      k = 1 + i;                      // starting value of the sequence

        while (k != 1) {  
           if (k > n) {
	           k -= n;       // k after the modulo operation: if k > n, then k = k - n
               t++;          // t being incremented when passing 1 on the circle, 
			                 //       increasing the Orbit for that sequence
           } 
           else {
               k += i;            // k being increased by the increment
           }
        }
        inputNum = t;
        string res;
        string t_in_base_6;
		t_in_base_6 = fromDeci(res, base, inputNum);       
        cout << t_in_base_6 << endl;   // print the Orbit for the particular sequence

        t = 0;                    // resetting the Orbit t for the next sequence
    }
    cout << endl;

}

// End Code
