// Check4prime_using_Zones_function_timed_precision.cpp
// Created by Alan Verdegraal February 1, 2026
// Copyright (c) 2026 Alan Verdegraal
//
// After entering a number n, this program examines the
// Zones of n+1 looking for the value of n+1 along the 
// right boundary cells of Zone 1. If it finds n+1, 
// then n is Composite. If it does not find n+1 in Zone 1, 
// then n is a Prime. This is based upon the RGV Method for
// identifying prime numbers.

//
// May 1, 2026 -- Added skipping checks on every other row 
// since n+1 must be an even number if n is prime, and every
// other row of Zone 1 has only odd numbers.
//
// Updated: May 9, 2026 -- Adding nanosecond timing
// using the C++ access to the high_resolution_clock.
// There are also options for milliseconds and microseconds
// that have been commented out. 
//
// Updated: May 20, 2026 -- Changing the long long int datatype to 
// unsigned long long int for one extra bit for integer representations.
//
// This current version can identify 9007199254740997 as a prime in 1 sec,
// using an HP Laptop 17t-cn000, having an 11th Gen Intel(R) Core(TM) 
// i7-1165G7 processor running a 64-bit operating system, with an 
// x64-based processor @ 2.80GHz with 64.0 GB installed RAM.
//
#include <iostream>
#include <math.h>
#include <limits>
#include <chrono>
using namespace std;

bool check_Zone_1_for_n(unsigned long long int n) {
	unsigned long long int k = 2, i = n;
	unsigned long long int cell_value;
	bool found_composite_Z1 = false;
	while ((k < n/2) && (i >= k)) {
		if (k%2) {
    		if (n%k == 0) {
    			i = n/k - 1;
  	  		}
    		else {
    			i = trunc(n/k);
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
	bool found_comp_Z1;
	unsigned long long int n;
	
	cout << "===================================" << endl;
	cout << "Check4prime_using_Zones_function_timed_precision.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for n: ";
    cin >> n; 
	cout << "===================================" << endl;	
    auto start = std::chrono::high_resolution_clock::now();   
			    
    found_comp_Z1 = check_Zone_1_for_n(n+1);

    auto end = std::chrono::high_resolution_clock::now();
  		
	if (found_comp_Z1 == false) {   
		cout << n << " is a Prime Number." << endl;
	}
	else {
		cout << n << " is a Composite Number." << endl;
	}
	
	cout << "===================================" << endl;
// 	auto duration = std::chrono::duration_cast < std::chrono::microseconds > (end - start);
// 	std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

 	auto duration = std::chrono::duration_cast < std::chrono::nanoseconds > (end - start);
 	std::cout << "Time taken: " << duration.count() << " nanoseconds" << std::endl;

//    std::chrono::duration<double, std::milli> ms_double = end - start;
//    std::cout << "Time taken: " << ms_double.count() << " milliseconds" << std::endl;	
	cout << "===================================" << endl;
}

// End_code
