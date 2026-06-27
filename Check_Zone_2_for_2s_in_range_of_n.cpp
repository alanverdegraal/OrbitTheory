// Check_Zone_2_for_2s_in_range_of_n.cpp
// Created by Alan Verdegraal   March 4, 2024
//
// This program checks Zone 2 for 2 to see if n+1
// is a composite number. It runs through a range of
// values but does not include the starting value of n.
// It also includes the last n plus one more since it
// processes a particular n to determine if n+1 is prime
// or composite.
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

bool check_4_2_in_zone_2(long long int n) {
	long long int cell_value, midpoint;
	long long int i, c, r;
	bool found_2 = false;

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
			c=int(n/i)+1; r=i;
			cell_value = get_cell_value(n,c,r);
		}
		if (cell_value == 2) {
	     	found_2=true;
	     	i=n;
		}
	}	
	return found_2;
}

int main() {
	long long int n, i;
	long long int start_value, ending_value;
	long long int total_primes=0, total_composites=0;
	bool found_2 = false;
	
	cout << "Enter starting value for n: ";
	cin >> start_value;
	cout << "Enter ending value for last n: ";
	cin >> ending_value;
	
	for (i=start_value; i<=ending_value; i++) {
		n = i;
		found_2=check_4_2_in_zone_2(i);
	
		if (found_2 == false) {
			cout << n+1 << " is prime." << endl;
			total_primes++;
		}
		else {
			cout << n+1 << " is composite." << endl;
			total_composites++;
		}
	}
	cout << endl;
	cout << "Total primes found from " << start_value+1 << " through " << ending_value+1 << " is " << total_primes << endl;
	cout << "Total composites found from " << start_value+1 << " through " << ending_value+1 << " is " << total_composites << endl;
}

// End_code
