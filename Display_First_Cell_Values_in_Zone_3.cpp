// Display_First_Cell_Values_in_Zone_3.cpp
// Created by Alan Verdegraal   December 28, 2023
//
// This program displays the first cell value on each
// row for Zone 3.
//
#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

long long int get_cell_value(long long int n, long long int c, long long int r) {
	long long int b4_mod_value, remainder, cell_value, j;
	b4_mod_value=0;
	for (j=1; j<=r; j++) {
		b4_mod_value = b4_mod_value + c;
	}
	cout << b4_mod_value << endl;
	remainder = b4_mod_value%n;
	cell_value = remainder + 1;
	return cell_value;
}

int main() {
	long long int cell_value;
	long long int n, i, c, r;
	
	cout << "Enter value for n: ";
	cin >> n;

    for (i=3; i<n; i++) {
    	if ((2*n)%i == 0) {
    		c=(2*n)/i; r=i;
    		cell_value = get_cell_value(n,c,r);	
		}
		else {
			c=int((2*n)/i)+1; r=i;
			cell_value = get_cell_value(n,c,r);
		}
		cout << "The cell value for n = " << n << " at location (" << c << "," << r << ") is " << cell_value << endl;
	}
}

// End_code
