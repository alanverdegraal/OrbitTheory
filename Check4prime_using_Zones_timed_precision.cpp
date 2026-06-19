// Check4prime_using_Zones_timed_precision.cpp
// Created by Alan Verdegraal June 7, 2026
// Copyright (c) 2026 Alan Verdegraal
//
//	This may be bad. It needs further testing.
//
// After entering a number n, this program examines the
// Zones of n+1 looking for the value of n+1 along the 
// right boundary cells of Zone 1. If it finds n+1, 
// then n is Composite. If it does not find n+1 in Zone 1, 
// then n is a Prime. This is based upon the RGV Method for
// identifying prime numbers.
// 
// This version simplifies the i coordinate to trunc((nn-1)/k).
//
// Includes skipping checks on every other row 
// since n+1 must be an even number if n is prime, and every
// other row of Zone 1 has only odd numbers.
//
// Includes nanosecond timing
// using the C++ access to the high_resolution_clock.
// There are also options for milliseconds and microseconds
// that have been commented out. 
//
// Includes the unsigned long long int for one extra bit for 
// integer representations.
//
// This current version can identify 9007199254740997 as a prime in 1/2 sec,
// using an HP Laptop 17t-cn000, having an 11th Gen Intel(R) Core(TM) 
// i7-1165G7 processor running a 64-bit operating system, with an 
// x64-based processor @ 2.80GHz with 64.0 GB installed RAM.
//
#include <iostream>
#include <math.h>
#include <limits>
#include <chrono>
using namespace std;

bool check_Zone_1_for_n(unsigned long long int nn) {
	unsigned long long int k = 2, i = nn;
	unsigned long long int cell_value;
	bool found_composite_Z1 = false;
	while ((k < nn/2) && (i >= k)) {
		if (k%2) {
    		i = trunc((nn-1)/k);
			cell_value = (k*i)+1;
			if (cell_value == nn) {
				found_composite_Z1 = true;
				k = nn;
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
	cout << "Check4prime_using_Zones_timed_precision.cpp" << endl;
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
