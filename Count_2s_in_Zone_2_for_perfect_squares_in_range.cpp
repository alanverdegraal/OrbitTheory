// Count_2s_in_Zone_2_for_perfect_squares_in_range.cpp
// Created by Alan Verdegraal   March 16, 2024
//
// This program checks Zone 2 for 2s. It runs through
// a range of values for i and first calculates the square
// power of i, which becomes the value of n for counting 2s.
// It prints i, n, and #2s.
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

long long int count_2s_in_zone_2(long long int n) {
	long long int cell_value, midpoint;
	long long int i, c, r;
	long long int count_of_2s = 0;
	
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
	     	count_of_2s++;
		}
	}	
	return count_of_2s;
}

int main() {
	long long int n, i;
	long long int start_value, ending_value;
	long long int total_primes=0, total_composites=0;
	long long int total_2s = 0;
	
	cout << "Enter starting value for n: ";
	cin >> start_value;
	cout << "Enter ending value for last n: ";
	cin >> ending_value;
	
	for (i=start_value; i<=ending_value; i++) {
		n = i*i;
		
		total_2s=count_2s_in_zone_2(n);
		
		cout << i << "  "<< n << "  " << total_2s << endl;
	}
}

// End_code
