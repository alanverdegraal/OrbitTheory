// List_first_cells_in_Zone_2_for_n.cpp
// Created by Alan Verdegraal -- January 28, 2026
// 
// This lists out the cell coordinates (row, col) (k,i) of
// the first cells for each row in Zone 2 for a particular n. 
// It also lists the value of that first cell calculated by k*i - n + 1. 
// The while loop runs down the k rows where k is less than n/2 + 1.

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
    
    while (k < n/2 + 1) {
    	if (n%k == 0) {
    		i = n/k;
  	  	}
    	else {
    		i = int(n/k) + 1;
		}
		cout << "(" << k << "," << i << ") " << (k*i)-n+1 << endl;
		k++;
	}	
}

// End_Code
