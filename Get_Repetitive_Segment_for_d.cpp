// Get_Repetitive_Segment_for_d.cpp
// Created by Alan Verdegraal October 21, 2022.
//
// This produces the Repetitive Sequence for Increment d
// based upon inputting the value for d.

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

long long int get_orbit_value (long long int d, long long int n) {
    long long int k, t=0;
    long long int orbit_value;
    k = 1 + d;                      // starting value of the sequence
    while (k != 1) {  
       if (k > n) {
          k -= n;       // k after the modulo operation: if k > n, then k = k - n
          t++;          // t being incremented when passing 1 on the circle, 
			                 //       increasing the Orbit for that sequence
       } 
       else {
          k += d;            // k being increased by the increment
       }
    }
    orbit_value = t;
    return orbit_value;
}

int main() {
	long long int d, i, orbit_number;
	
	cout << "Enter the value for d: ";
    cin >> d;
    
    cout << endl;
    cout << "d=" << d << "  {";
    
    for (i=d; i<2*d; i++) {
    	orbit_number=get_orbit_value(d,i);
    	cout << orbit_number << ", ";
	}
	
	orbit_number=get_orbit_value(d,2*d);
	cout << orbit_number << "}" << endl;
	
}

// End-Code
