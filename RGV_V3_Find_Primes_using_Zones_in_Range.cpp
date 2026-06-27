// RGV_V3_Find_Primes_using_Zones_in_Range.cpp
// Created by Alan Verdegraal -- April 24, 2026
// Copyright (c) 2026 by Alan Verdegraal
//
// This is a method of identifying and counting Primes known
// as the Robert-Göçgen-Verdegraal Method of Prime Identification.
// It is based upon the Orbit Theory of Natural Numbers developed
// by Alan Verdegraal in his 3 published books demonstrating that
// every number n knows the primality of both n-1 and n+1 without
// needing to examine those adjacent numbers. These books include
// The Orbit Theory of Natural Numbers -- Volume I and II, and 
// Landau's Fourth Problem -- On Primes of the Form n^2 (all available
// on Amazon.com). Denis Robert of Canada in his book Base 6 
// (available on Amazon) was instrumental in showing that only multiples 
// of 6 need to be considered since all Prime Numbers, except 2 and 3,
// are of the form 6n+1 or 6n-1. Ahmet Furkan Göçgen of Turkey has
// been key in developing the underlying mathematical proofs of this
// portion of Orbit Theory and came up with the idea that Twin Primes 
// can be found using the method by examining the single number 
// between them.
//
// The novelty of this method is that it does not examine Prime
// numbers themselves but only looks at the multiples of 6. It does
// not use factorization to determine primality because each
// multiple of 6 within its own structure knows whether 6n+1 and
// 6n-1 are Prime or Composite. Orbit Theory states that when examining
// the Square Sq(n) created by the Construction Rule (see either Volume
// I or Landau's Fourth Problem), if n is found as a cell value within 
// Zone 1 then n-1 is a Composite number, otherwise n-1 is a Prime number. 
// If a 2 is found in Zone 2 then n+1 is a Composite number, 
// otherwise n+1 is a Prime number.
//
// Zones are defined within Square Sq(n) where the sequence of cell values
// are increasing along a particular row. When the next cell value is 
// less than the previous cell value, then a new Zone starts. The first
// row and column of Square Sq(n) are denoted as Zone 0 and are excluded
// from the identification process. Zones have symmetry around the main
// diagonal, which means the process need only to examine cell values
// in the upper part of the Zones above the main diagonal. If n is 
// is found in Zone 1, it is in a cell that is the greatest value on
// that row for Zone 1. If a 2 is found in Zone 2, it is in a cell that
// has the least value for that row in Zone 2. Thus, not every cell in
// these two Zones must be examined, only those cells along the boundary
// between Zone 1 and Zone 2.
// 
// Process:
//
// After entering the range, the program first determines the
// lowest value for 6m, thereafter incrementing by 6. Thus, it excludes
// Primes 2 and 3, since they are less than 6. For each 6m, it checks 
// Zone 1 for n and Zone 2 for 2. If it does not find an n in Zone 1,
// then 6m-1 is Prime. If no 2 is found in Zone 2, then 6m+1 is Prime.
// If none are found in either Zone 1 and Zone 2, then both n-1 and n+1 
// are members of a pair of Twin Primes. It counts the total primes found
// as well as the number of pairs of Twin Primes.
//
// Functions:
//
// find_lowest_six_m -- finds the lowest multiple of 6 greater
// than or equal to the passed variable lowb.
// 
// check_Zone_1_for_n -- Checks Zone 1 of n (the passed value) for n.
// If it finds an n, then the number n is composite. If an n is not
// found, then the boolean variable found_composite_Z1 remains false.
//
// check_Zone_2_for_2 -- Checks Zone 2 of n for a 2. If it finds a 
// 2, then the number n is composite. If an n is not found, then the
// boolean variable found_composite_Z2 remains false.
//
// Execution begins at main() first accepting the low and high bounds
// for the range, determines the starting 6m, running the Zone checks
// on 6m, incrementing Prime counters, then reporting on the results.
// Note: if the high bound in the range is a multiple of 6, and 6m+1
// has no 2s, then 6m+1 is prime and will be include in the count of
// total Primes even though 6m+1 is outside of the entered range.
//
// This C++ program uses 64 bit number size with data type long long int.
// Maximum value of any register is the limit 9223372036854775807
// Since the algorithms involve the multiplication of k (rows) times
// i (columns), the maximum number able to be processed is the square 
// root of the register limit or 3032000000.
//
// To print out primes, uncomment the two print statements for
// 6m - 1 and 6m + 1.
//
// Optionally, to print out Twin Prime pairs, uncomment the print
// statement for Twin Primes.
//
// Note: This Zone-based program does not report 2 and 3 as primes since
// it only reports on primes that are of the form 6m-1 or 6m+1.
//

#include <iostream>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;

int find_lowest_six_m (long long int lowb) {
	long long int checklow;
	long long int lowsix_m;
	
	checklow = lowb;
	while (checklow < lowb + 6) {
		if (checklow%6 == 0) {
			lowsix_m = checklow;
			lowb = 0;
		}
		checklow++;
	}
	return lowsix_m;
}
   
bool check_Zone_1_for_n(long long int n) {
	long long int k = 2, i = n;
	long long int cell_value;
	bool found_composite_Z1 = false;
	long long int sqrt_n = trunc(sqrt(n));
//	while ((k < n/2) && (i > k) && (i > sqrt_n)) {
	while ((k < n/2) && (i > sqrt_n)) {	
        if (k%2) {
    	    if (n%k == 0) {
    	    	i = n/k - 1;
  	  		}
    		else {
    			i = int(n/k);
			}
			cell_value = (k*i)+1;
//			cout << "(" << k << "," << i << ") " << cell_value << endl;
			if (cell_value == n) {
				found_composite_Z1 = true;
				k = n;
			}
		}
		k++;
	}	
	return found_composite_Z1;
}
   
int main() {
	long long int six_m;
	long long int low_bound, high_bound, lowest_six_m;
	long long int total_twin_primes = 0;
	long long int total_primes = 0;
	bool found_atleast_one = false;
	bool found_comp_6m_minus_1, found_comp_6m_plus_1;
	long long int last_prime_found=0, last_twin_prime_1=0, last_twin_prime_2=0;
	
	time_t timestamp;
	
	cout << "===================================" << endl;
	cout << "RGV_V3_Find_Primes_using_Zones_in_Range.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for lowest bound: ";
    cin >> low_bound; 
	cout << "Enter the value for highest bound: ";
    cin >> high_bound; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
		    
    lowest_six_m = find_lowest_six_m (low_bound);
    
//    cout << lowest_six_m << endl;
    
    six_m = lowest_six_m;
    
    while (six_m <= high_bound) {
    	found_comp_6m_minus_1 = check_Zone_1_for_n(six_m);
		if (found_comp_6m_minus_1 == false) {   
			total_primes++;
			last_prime_found = six_m - 1;
// Uncomment the following line to print out primes.
//			cout << six_m - 1 << " is a Prime." << endl;
		}
    	found_comp_6m_plus_1 = check_Zone_1_for_n(six_m + 2);
		if (found_comp_6m_plus_1 == false) {
			total_primes++;
			last_prime_found = six_m + 1;
// Uncomment the following line to print out primes.
//			cout << six_m + 1 << " is a Prime." << endl;
		}

    	if ((found_comp_6m_minus_1 == false) && (found_comp_6m_plus_1 == false)) {
// Uncomment the following line to print out Twin Primes.
//    		cout << six_m - 1 << ", " << six_m + 1 << " are Twin Primes." << endl;
			last_twin_prime_1 = six_m - 1;
			last_twin_prime_2 = six_m + 1;
    		found_atleast_one = true;
    		total_twin_primes++;
		}
		six_m = six_m + 6;
	}
	
	cout << "===================================" << endl;
	cout << endl;
	cout << "Lower Bound:  " << low_bound << endl;
	cout << "Upper Bound:  " << high_bound << endl;
	cout << "Total Primes found:  " << total_primes << endl;
	cout << "Last Prime Found:  " << last_prime_found << endl;
	cout << "Last Twin Prime Found:  (" << last_twin_prime_1 << "," << last_twin_prime_2 << ")" << endl;
	if (found_atleast_one == false) {
		cout << "No Twin Primes Found." << endl;
	}
	else {
		cout << "Total Number of Twin Primes found:  " << total_twin_primes << endl;
	}
	cout << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End_code
