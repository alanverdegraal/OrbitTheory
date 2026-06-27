// Display_First_Cell_Values_in_Sector_4_Primality.cpp
// Created by Alan Verdegraal   February 1, 2024
//
// This program displays the first cell value on each
// row for Zone m that lay in primality sector.
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
//	cout << b4_mod_value << endl;
	remainder = b4_mod_value%n;
	cell_value = remainder + 1;
	return cell_value;
}


long long int get_first_value(long long int n, long long int m) {
	long long int cell_value, success = 0;
	long long int i, c, r;
	
    for (i=m; i<(n/2)+1; i++) {
   		if (((m-1)*n)%i == 0) {
   			c=((m-1)*n)/i; r=i;
   			cell_value = get_cell_value(n,c,r);	
		}
		else {
			c=int(((m-1)*n)/i)+1; r=i;
			cell_value = get_cell_value(n,c,r);
		}
		if ((c>=m) && (c<=n/2) && (r<=c)) {
//			cout << "c is " << c << " and m is " << m << endl;
			cout << "The cell value for n = " << n << " in zone " << m << " at location (" << c << "," << r << ") is " << cell_value << endl;
		}
	}
	return success;
}

int main() {
	long long int n, m, success;
	
	cout << "Enter value for n: ";
	cin >> n;
	
	for (m=2; m<=n/2; m++) {
//			cout << "m is " << m << endl; 
			success = get_first_value(n, m);
	}
}
	
// End_code
