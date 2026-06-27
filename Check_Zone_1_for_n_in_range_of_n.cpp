// Check_Zone_1_for_n_in_range_of_n.cpp
// Created by Alan Verdegraal   March 5, 2024
//
// This program checks Zone 1 for n to see if n-1
// is a composite number.
//
#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

long long int get_cell_value(long long int n, long long int c, long long int r) {
	long long int b4_mod_value, remainder, cell_value;
	b4_mod_value = c * r;
	remainder = b4_mod_value%n;
	cell_value = remainder + 1;
	return cell_value;
}

bool check_4_n_in_zone_1(long long int n) {
	long long int cell_value, midpoint;
	long long int i, c, r;
	bool found_n = false;

	if (n%2==0) {
		midpoint=n/2;
	}
	else {
		midpoint=((n+1)/2);
	}
	
    for (i=2; i<=midpoint; i++) {
    	if (n%i == 0) {
    		c=n/i; r=i;
    		cell_value = get_cell_value(n,c,r);	
		}
		else {
			c=int(n/i); r=i;
			cell_value = get_cell_value(n,c,r);
		}
		if (cell_value == n) {
	     	found_n=true;
	     	i = midpoint+1;
		}	
	}
	return found_n;
}

int main() {
	long long int n, i;
	long long int start_value, ending_value;
	long long int total_primes=0, total_composites=0;
	bool found_2 = false;
	
	cout << "Enter largest value for n: ";
	cin >> start_value;
	cout << "Enter smallest value for last n: ";
	cin >> ending_value;
	
	for (i=start_value; i>=ending_value; i--) {
		n = i;
		found_2=check_4_n_in_zone_1(i);
	
		if (found_2 == false) {
			cout << n-1 << " is prime." << endl;
			total_primes++;
		}
		else {
			cout << n-1 << " is composite." << endl;
			total_composites++;
		}
	}
	cout << endl;
	cout << "Total primes found from " << start_value-1 << " through " << ending_value-1 << " is " << total_primes << endl;
	cout << "Total composites found from " << start_value-1 << " through " << ending_value-1 << " is " << total_composites << endl;
}


// End_code
