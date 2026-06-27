// Print_Seq_Values_for_a_Zone.cpp
// Created by Alan Verdegraal August 9, 2023
//
// This program prints out the sequence values for a 
// particular zone.
//
// After entering n and the Zone number (zones start with
// Zone 0), it computes the sequence values skipping
// any values prior to the zone being listed.
//
#include <iostream>
using namespace std;

int main() {
   int k, i, n, d, zone, cur_zone;

   cout << "Enter the value for n: ";
   cin >> n; 
   cout << "Enter the Zone number, zones start with 0: ";
   cin >> zone;

   cout << "Increment     Sequences" << endl;
   cout << "=================================================" << endl;

   // n is the modulo number 
   // d is the increment for each sequence
   // zone indicates which values of the zones to print. 
   // cur_zone is the current zone. Zones start with 0.
   // i is for the index on the current sequence
   // k is the current value of the sequence

   for (d = 1; d <= n; d++) { 
   		cur_zone=0;
   		i=1;
		k=1; 
		cout << "d=" << d << "     ";
   		while (i <= n) {
		   	k = k + d;                      // starting value of the sequence
        	if (k > n) {
	        	k = k - n;             // k after the modulo operation: if k > n, then k = k - n
            	cur_zone++;               // zone being incremented when passing 1 on the circle, 
        	}	 
        	if ((k <= n) && (zone==cur_zone)) {          // printing out the next sequence value
            	cout << k;
            	cout << " ";
        	}
        	i++;
    	}
        cout << endl;
    }
}

// End Code
