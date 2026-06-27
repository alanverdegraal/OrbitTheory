// Find_Twin_Primes_using_Zones_in_Range.cpp
// Created by Alan Verdegraal -- January 28, 2026
//
// After entering the range, the program first determines the
// lowest value for 6m, thereafter incrementing by 6. For each
// 6m, it checks Zone 1 for n and Zone 2 for 2. If none are 
// found then both n-1 and n+1 are both members of a pair of 
// Twin Primes.
//
// Functions:
//
// find_lowest_six_m -- finds the lowest multiple of 6 greater
// than or equal to the passed variable lowb.
// 
// check_Zone_1_for_n -- Checks Zone 1 of n (the passed value) for n.
// If it finds an n, then the number n is composite. 
//
// check_Zone_2_for_2 -- Checks Zone 2 of n for a 2. If it finds a 
// 2, then the number n is composite.
//
// Execution begins at main().
//
// The long long int datatype allows very large integer numbers.

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

int find_lowest_six_m (long long int lowb) {
	long long int checklow;
	long long int lowsix_m;
	
	checklow = lowb;
	while (checklow < lowb + 6) {
		if (checklow%6 == 0) {
			lowsix_m = checklow;
			lowb = 0;
		}
		checklow++;
	}
	return lowsix_m;
}
   
bool check_Zone_1_for_n(long long int n) {
	long long int k = 2, i;
	long long int cell_value;
	bool found_composite_Z1 = false;
	while (k < n/2) {
    	if (n%k == 0) {
    		i = n/k - 1;
  	  	}
    	else {
    		i = int(n/k);
		}
		cell_value = (k*i)+1;
//		cout << "(" << k << "," << i << ") " << cell_value << endl;
		if (cell_value == n) {
			found_composite_Z1 = true;
			k = n;
		}
		k++;
	}
	return found_composite_Z1;
}
   
bool check_Zone_2_for_2(long long int n) {  
	long long int k = 2, i;
	long long int cell_value;
	bool found_composite_Z2 = false;
	while (k < n/2 + 1) {
    	if (n%k == 0) {
    		i = n/k;
  	  	}
    	else {
    		i = int(n/k) + 1;
		}
		cell_value = (k*i)-n+1;
//		cout << "(" << k << "," << i << ") " << cell_value << endl;
		if (cell_value == 2) {
			found_composite_Z2 = true;
			k = n;
		}
		k++;
	}
	return found_composite_Z2;
}  

int main() {
	long long int six_m;
	long long int low_bound, high_bound, lowest_six_m;
	long long int total_twin_primes = 0;
	bool found_atleast_one = false;
	bool found_comp_Z1, found_comp_Z2;
	cout << "Enter the value for lowest bound: ";
    cin >> low_bound; 
	cout << "Enter the value for highest bound: ";
    cin >> high_bound; 
    
    lowest_six_m = find_lowest_six_m (low_bound);
    
//    cout << lowest_six_m << endl;
    
    six_m = lowest_six_m;
    
    while (six_m <= high_bound) {
    	found_comp_Z1 = check_Zone_1_for_n(six_m);
    	if (found_comp_Z1 == false) {
    		found_comp_Z2 = check_Zone_2_for_2(six_m);
   		}
    	if ((found_comp_Z1 == false) && (found_comp_Z2 == false)) {
    		cout << six_m - 1 << ", " << six_m + 1 << " are Twin Primes." << endl;
    		found_atleast_one = true;
    		total_twin_primes++;
		}
		six_m = six_m + 6;
	}
	if (found_atleast_one == false) {
		cout << "No Twin Primes Found." << endl;
	}
	else {
		cout << "Total Number of Twin Primes found:  " << total_twin_primes << endl;
	}
 	
}

// End_code
