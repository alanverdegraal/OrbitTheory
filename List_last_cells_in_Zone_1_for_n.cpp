// List_last_cells_in_Zone_1_for_n.cpp
// Created by Alan Verdegraal -- January 27, 2026
// 
// This lists out the cell coordinates (row, col) (k,i) of
// the last cell for each row in Zone 1 for a particular n. 
// It also lists the value of that last cell calculated by k*i + 1. 
// The while loop runs down the k rows where k is less than n/2.

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

long long int k = 2;
long long int i;
long long n;
   
int main() {
	cout << "Enter the value for n: ";
    cin >> n; 
    
    while (k < n/2) {
    	if (n%k == 0) {
    		i = n/k - 1;
  	  	}
    	else {
    		i = int(n/k);
		}
		cout << "(" << k << "," << i << ") " << (k*i)+1 << endl;
		k++;
	}	
}

// End_Code
