// Get_Cell_Value_for_Square-n_function.cpp
// Created by Alan Verdegraal -- December 28, 2023
//
// By entering a cell location (c,r) = (col,row),
// this function returns the value of the cell for
// a specific n.

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

int main() {
	long long int cell_value;
	long long int n, c, r;
	
	cout << "Enter value for n: ";
	cin >> n;
	cout << "Enter value for column: ";
	cin >> c;
	cout << "Enter value for row: ";
	cin >> r;
	
	cell_value = get_cell_value(n,c,r);
	
	cout << "The cell value for n = " << n << " at location (" << c << "," << r << ") is " << cell_value;
}

// End_code
