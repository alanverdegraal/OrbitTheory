// Range_Search_4_Primes_Using_Alt_Staircase_Search.cpp
// Created by Alan Verdegraal November 17, 2025
//        Modified February 5, 2026 – adding timing.
// Copyright 2025 Alan Verdegraal
//
// This program uses the Staircase Range to identify Primes.
// However, it uses the method that maps the pattern of 1s 
// for a Composite number from Square Sq(n) to the standard 
// Multiplication table Pr(n) where k (row number) is
// multiplied by i (column number) to obtain the cell value.
//
// The Staircase Range is the two diagonals including the main
// diagonal and the diagonal below it. The main diagonal holds
// all the square powers since k = i. The diagonal below the
// main diagonal holds cells with values k(k-1).
//
// The Alt Staircase Conjecture states that if n is a factor
// of any cell values in this Staircase Range, then n is a
// composite number. If n is not a factor in this Range, then
// n is a Prime number. 
// 
// The program descends the main diagonal and if it does not
// find a cell value that has n as a factor, it then descends
// the diagonal below the main diagonal. When it does find n
// as a factor, the n is a Composite, ending the search and
// proceeding to the next number. The range examines each number 
// n one-by-one, skipping even numbers.
//
// This Alt Staircase Search is at least 10 times faster than
// the original Staircase Search, which uses an algebraic 
// formula to determine the modular value of each cell in the 
// range. The original search actually ascends the staircase
// walking up both the main diagonal and the adjacent diagonal
// at the same time looking for a 1. 
//
// The speed increase of the Alt Search versus the original search 
// occurs in the simple multiplication of k*i versus the complex 
// algebraic formula in deriving the cell value to be checked. 
// The original search looks for a 1 in the Staircase Range. 
// The mapping to the multiplication table works because 1s from 
// the initial Square Sq(n) map to cells in the multiplication 
// table where n is a factor of the cell value.
//
// To print out primes, uncomment the print line.
//

#include <iostream>
#include <limits>
#include <math.h>
#include <ctime>
using namespace std;

bool alt_check4composite(long long int n) {
   long long int j = 0;
   bool found_composite = false;
   long long int sqrt_n_value = sqrt(n);
   long long int half_n = (n-1)/2 - 1;

   if (((n%2==0) && (n!=2)) || (n==1)) {
   	  found_composite = true;
//  	  cout << "n0 = " << n << " : " << "2" << endl;
   }
   if (found_composite != true) {
   		for (j=3;j<=sqrt_n_value;j++) {
       		if ((j*j) % n == 0) { 
        		found_composite = true;
//         		cout << "n1 = " << n << " : " << j*j << endl;
         		j = sqrt_n_value + 1;
      		}
    	}	
    }
	if (found_composite != true) {		
      	for (j=sqrt_n_value + 1;j<=half_n;j++) {
			if ((j*j) % n == 0) {
				found_composite = true;
//				cout << "n2 = " << n << " : " << j*j << endl;
				j = half_n + 1;
			}
		}
    }
    if (found_composite != true) {
        for (j=4;j<=sqrt_n_value;j++ ) {
        	if (n % (j*(j-1)) == 0) {
        		found_composite = true;
//        		cout << "n3 = " << n << " : " << j*(j-1) << endl;
        		j = sqrt_n_value + 1;
			}
		}
	}
	if (found_composite != true) {
		for (j=sqrt_n_value;j<=half_n;j++) {
			if ((j*(j-1)) % n == 0) {
				found_composite = true;
//				cout << "n4 = " << n << " : " << j*(j-1) << endl;
				j = half_n + 1;
			}
		}
	}	
    return found_composite;
}

int main() {
   long long int t, k, i, j, n, nn, beginning_value, ending_value, total, num_primes, last_prime;
   long long int value_if_prime;
   long long start_inc, start_n;
   long long cur_n;
   bool composite_found;
   
   time_t timestamp;

   cout << "===================================" << endl;
   cout << "Range_Search_4_Primes_Using_Alt_Staircase_Search.cpp" << endl;
   cout << "===================================" << endl;
   cout << "This program counts prime numbers within a specified range of numbers." << endl;
   cout << "===================================" << endl;
   cout << endl;
   cout << "Enter the initial value of the range: ";
   cin >> beginning_value;
   if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
   cout << "Enter the final value of the range: ";
   cin >> ending_value; 
   if (ending_value - beginning_value <= 2) {ending_value = beginning_value + 3;} 
                                // range must be > 2
   cout << endl;
   
   cout << "Count of Primes between and including " << beginning_value;
   cout << " and " << ending_value << endl;
   cout << "===================================" << endl;	
   time(&timestamp);	
   cout << "Start date and time: " << ctime(&timestamp);
   
   num_primes=0;

   for (j = beginning_value; j <= ending_value; j++) { 
      nn = j;                // Initializing the next number in the range
      
      composite_found = alt_check4composite(nn);      

    	if (composite_found != true) {
// Uncomment out the following line to print out primes.    		
//	   		cout << nn << " is Prime." << endl;
			last_prime = nn;
	   		num_primes = num_primes + 1;
    	}
    }  
    cout << endl;
    cout << "=========================" << endl;
    cout << "Total Primes in Range is " << num_primes << endl;
    cout << "Last Prime is " << last_prime << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End Code
