// Range_Check4primes_using_Zones_timed_precision.cpp
// Created by Alan Verdegraal -- May 9, 2026
#include <iostream>
#include <math.h>
#include <limits>
#include <chrono>
using namespace std;

bool check_Zone_1_for_n(long long int nn) {
	long long int k = 2, i = nn;
	long long int cell_value;
	bool found_composite_Z1 = false;
//	while ((k < nn/2) && (i >= k)) {
	while (i >= k) {
		if (k%2) {
    		if (nn%k == 0) {
    			i = nn/k - 1;
  	  		}
    		else {
    			i = trunc(nn/k);
			}
			cell_value = (k*i)+1;
//			cout << "(" << k << "," << i << ") " << cell_value << endl;
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
	long long int low_bound, high_bound;
	long long int total_primes = 0;
//	long long int n;
	
	cout << "===================================" << endl;
	cout << "Range_Check4primes_using_Zones_timed_precision.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for the lowest bound: ";
    cin >> low_bound; 
	cout << "===================================" << endl;	
	cout << "Enter the value for the highest bound: ";
    cin >> high_bound;     
	cout << "===================================" << endl;	
	
	if (2 >= low_bound) {
//		cout << "2" << " ";
		total_primes++;
		low_bound=3;
	}
	if (3 >= low_bound) {
//		cout << "3" << " ";
		total_primes++;
		low_bound=5;
	}
 	
    auto start = std::chrono::high_resolution_clock::now();  
	
	for (long long int n = low_bound; n < high_bound; n++) {
    
    	if (n%2 == 0) {
    		n++;
		}
    
    	found_comp_Z1 = check_Zone_1_for_n(n+1);
  		
		if (found_comp_Z1 == false) {
//			cout << n << " ";
			total_primes++;
		}
	}
    auto end = std::chrono::high_resolution_clock::now();
//    cout << endl;
    cout << "===================================" << endl;
	cout << "Total Number of Primes = " << total_primes << endl;
	cout << "===================================" << endl;
// 	auto duration = std::chrono::duration_cast < std::chrono::microseconds > (end - start);
// 	std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

// 	auto duration = std::chrono::duration_cast < std::chrono::nanoseconds > (end - start);
// 	std::cout << "Time taken: " << duration.count() << " nanoseconds" << std::endl;

    std::chrono::duration<double, std::milli> ms_double = end - start;
    std::cout << "Time taken: " << ms_double.count() << " ms" << std::endl;	
	cout << "===================================" << endl;
}

// End_code
