// Count_of_Factors_Cofactors_Coprimes_for_Repetitive_Segment_of_d.cpp
// Created by Alan Verdegraal October 26, 2022.
//
// This produces the Repetitive Sequence for Increment d
// based upon inputting the value for d, then counts the
// number of factors, cofactors, and coprimes found. Finally
// it computes the % of each with respect to d.

#include <iostream>
#include <iomanip>
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
	float total_coprimes=0, total_factors=0, total_cofactors=0;
	float percent_coprimes=100.1, percent_factors=100.1, percent_cofactors=100.1;
	
	cout << "Enter the value for d: ";
    cin >> d;
    
    cout << endl;
    cout << "d=" << d << " : ";
    
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

	percent_factors = (total_factors / d) * 100.0;
	percent_cofactors = (total_cofactors / d) * 100.0;
	percent_coprimes = (total_coprimes / d) * 100.0;
	cout << " F: " << total_factors << "   F%: ";
	cout << setprecision(3) << percent_factors << "  ";
	cout << "CF: " << total_cofactors << "  CF%: ";
	cout << setprecision(3) << percent_cofactors << "  ";
	cout << "CP: " << total_coprimes << "  CP%: ";
	cout << setprecision(3) << percent_coprimes << "  " << endl;
	
}

// End-Code
