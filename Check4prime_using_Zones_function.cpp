// Check4prime_using_Zones_function.cpp
// Created by Alan Verdegraal February 1, 2026
//
// After entering a number n, this program examines the
// Zones of n+1 looking for the value of n+1 in Zone 1.
// If it finds n+1, then n is Composite. If it doesn't
// find n+1 in Zone 1, then n is a Prime.
//
#include <iostream>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;

bool check_Zone_1_for_nn(long long int nn) {
	long long int k = 2, i = nn;
	long long int cell_value;
	bool found_composite_Z1 = false;
	while ((k < nn/2) && (i > k)) {
    	if (nn%k == 0) {
    		i = nn/k - 1;
  	  	}
    	else {
    		i = int(nn/k);
		}
		cell_value = (k*i)+1;
//		cout << "(" << k << "," << i << ") " << cell_value << endl;
		if (cell_value == nn) {
			found_composite_Z1 = true;
			k = nn;
		}
		k++;
	}
	return found_composite_Z1;
}
   
int main() {
	bool found_comp_Z1;
	long long int n;
	
	time_t timestamp;
	
	cout << "===================================" << endl;
	cout << "Determine_Primality_of_n_using_Zone_Conjecture.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for n: ";
    cin >> n; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
	cout << "===================================" << endl;	
			    
    found_comp_Z1 = check_Zone_1_for_nn(n+1);
  		
	if (found_comp_Z1 == false) {   
		cout << n << " is a Prime Number." << endl;
	}
	else {
		cout << n << " is a Composite Number." << endl;
	}
	
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End_code
