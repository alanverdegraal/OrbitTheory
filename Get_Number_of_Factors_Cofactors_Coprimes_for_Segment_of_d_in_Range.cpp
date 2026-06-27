// Get_Number_of_Factors_Cofactors_Coprimes_for_Segment_of_d_in_Range.cpp
// Created by Alan Verdegraal October 26, 2022.
//
// Using a specified range for d, this produces the 
// the Orbit values for Repetitive Sequence for Increment d.
// It then counts the number of factors, cofactors, and coprimes found. 

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
	long long int d, i, j, orbit_number;
	long long int total_coprimes, total_factors, total_cofactors;
	long long int start_value, end_value;
	
	cout << "Enter the starting value for d: ";
    cin >> start_value;
    cout << "Enter the ending value for d: ";
    cin >> end_value;
    
    for (j=start_value; j<=end_value; j++) {
    	total_factors = 0;
    	total_cofactors = 0;
    	total_coprimes = 0;
    	d = j;
    	for (i=d; i<2*d; i++) {
    		orbit_number=get_orbit_value(d,i);
    		if (orbit_number==1) {
				total_factors++;
			}
    		if (orbit_number==d) { 
				total_coprimes++;
			}	
			if ((orbit_number != d) && (orbit_number != 1)) {
				total_cofactors++;		
			}
		}
		cout << d << " " << total_factors << " " << total_cofactors << " " << total_coprimes << endl;
	}	
}

// End-Code

