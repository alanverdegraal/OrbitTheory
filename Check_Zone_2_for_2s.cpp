// Check_Zone_2_for_2s.cpp
// Created by Alan Verdegraal   December 28, 2023
//
// This program checks Zone 2 for 2 to see if n+1
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
//	cout << n << ", " << c << ", " << r << ", cell_value is " << cell_value << endl;
	return cell_value;
}

int main() {
	long long int cell_value, midpoint;
	long long int n, i, c, r;
	
	cout << "Enter value for n: ";
	cin >> n;

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
		cout << "The cell value for n = " << n << " at location (" << c << "," << r << ") is " << cell_value << endl;
		if (cell_value == 2) {
			cout << "Cell value is 2; thus " << n+1 << " is a composite number.";
			i=n;
		}
	}
}

// End_code
