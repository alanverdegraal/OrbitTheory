// Test_Zone_for_Key_Value_for_Forward_Transformation.cpp
// Created by Alan Verdegraal August 9, 2023
//
// This program tests a Zone for a Key Value
// needed for a Forward Transformation of the Square Sq(n).
//
// After entering n and the Zone number (zones start with
// Zone 1), it computes the sequence values skipping
// any values prior to the zone being listed, then tests
// those values for the Key Value for a Forward
// Transformation.
//
// If a Key Value is present, the n+1 is a composite number.
//
// n is the modulo number 
// d is the increment for each sequence
// zone indicates which values of the zones to print. 
// key_value is the key value for the zone. Typically the
// key_value is the same as the zone number. 
// key_value_found is true if a key value for the zone is found.
// cur_zone is the current zone. Zones start with 1.
// i is for the index on the current sequence
// k is the current value of the sequence
//
#include <iostream>
using namespace std;

int main() {
   int k, i, n, d, zone, cur_zone, key_value;
   bool key_value_found = true;

   cout << "Enter the value for n: ";
   cin >> n; 
   cout << "Enter the Zone number, zones start with 1: ";
   cin >> zone;

   cout << endl;
   cout << "Testing for Forward Transformation of Sq(n) to Sq(n+1)" << endl;
   cout << "Increment     Sequences" << endl;
   cout << "=================================================" << endl;

   key_value=zone;
   key_value_found=false;
   
   for (d = 1; d <= n; d++) { 
   		cur_zone=1;
   		i=1;
		k=1; 
		cout << "d=" << d << "     ";
   		while (i <= n) {
		   	k = k + d;          // starting value of the sequence
        	if (k > n) {
	        	k = k - n;      // k after the modulo operation: if k > n, then k = k - n
            	cur_zone++;     // zone being incremented when passing 1 on the circle, 
        	}	 
        	if ((k <= n) && (zone==cur_zone)) {          // printing out the next sequence value
                if (k == key_value)	{
                	key_value_found=true;
				}
            	cout << k;
            	cout << " ";
        	}
        	i++;
    	}
        cout << endl;
    }
    if (key_value_found==true) {
        cout << "Key Value " << key_value << " found in Zone-" << zone << endl;
        cout << "The number " << n+1 << " is Composite." << endl;
	}
	else {
		cout << "No Key Value " << key_value << " found in Zone-" << zone << endl;
	}
}

// End Code

