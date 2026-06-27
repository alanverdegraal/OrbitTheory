// Fill_an_Array_with_Orbit_Values_for_a_Range.cpp
// Created by Alan Verdegraal June 18, 2023
//
// This creates an array and fills it with 
// Orbit values for consecutive numbers in a range.
//
// The first row will have a 0 for Arr[0][0] followed
// by the list of numbers. The first column will have
// numbers incrementing by 1 from 0 to the maximum
// value of the range.
//
// In C++, arrays are indexed from 0 to n for each of
// the dimensions. Thus, the bounds of the array will
// be number of rows = max(range)+1, and the number of
// columns will be ending value - starting value + 2.
// (Two is added because the first column are just row
// numbers for Increment d, plus 1 must be added to the
// difference to span the entire range.
//
// The program then prints out the array. It is intended
// to be included in other programs that would process
// the Orbit entries in the array.
//

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

long long int get_orbit_value (long long int n, long long int d) {
      long long int k, t=0;
      long long int orbit_value;

      k = 1 + d;                      // starting value of the sequence

      while (k != 1) {  
         if (k > n) {
            k -= n;       // k after the modulo operation: if k > n, then k = k - n
            t++;          // t being incremented when passing 1 on the circle, 
			                 //       increasing the Orbit for that sequence
         } 
         else {
            k += d;            // k being increased by the increment
         }
      }
      orbit_value = t;
      return orbit_value;
    }

int main() {
	long long int beginning_value, ending_value;
	long long int i, j, k, l, m;
	long long int orbit_value, found_prime;
	long long int num_of_columns, num_of_rows;

	cout << "Enter the range of numbers to fill the array." << endl;	
	cout << "Enter the value of the first number in the range: ";
    cin >> beginning_value;
    cout << "Enter the value of the last number in the range: ";
    cin >> ending_value; 
    cout << endl;
    
    num_of_columns=ending_value - beginning_value + 2;
    num_of_rows=ending_value+1;
	    
    long long int arr[num_of_rows][num_of_columns];

// Initialize array
	for (l=0; l < num_of_rows; l++) {
		for (k=0; k <= num_of_columns; k++) {
			arr[l][k]=0;
		}
	}    

//   Initialize first row with values of n
	for (l=0; l < num_of_rows; l++) {    
		m=0;  
		for (k=1; k < num_of_columns; k++) {
     		arr[0][k]=beginning_value+m;
     		m++;
		}
	}

//	Initialized first column with values incrementing by 1
	for (l=0; l < num_of_rows; l++) {
		arr[l][0]=l;
	}
	for (j=1; j < num_of_rows; j++) {
		l=1;
		for (i=beginning_value; i<=ending_value; i++) {
			if (j>i) {
				arr[j][l]=0;
			}
			else {
				orbit_value=get_orbit_value(i,j);
				arr[j][l]=orbit_value;
			}
			l++;
		}
	}

// Print entire array
	for (l=0; l < num_of_rows; l++) {  
		for (k=0; k < num_of_columns; k++) {  
    		cout << arr[l][k] << " ";
   	 	}
    	cout << endl;
	}    
}

// End_Code
