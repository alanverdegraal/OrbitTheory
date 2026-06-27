// count_right_boundary_cells_for_n-1.cpp
// created by Alan Verdegraal January 31, 2026
//
// This program counts the right boundary cells of
// Zone 1 used in determining if n-1 is Prime or
// Composite.
//

#include <iostream>
#include <math.h>
#include <limits>
#include <ctime>
#include <iomanip>
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
	long long int cell_count = 0;
	bool found_composite_Z1 = false;
//	float percent_cells;
	while ((k < n/2) && (i > k)) {
		cell_count++;
    	if (n%k == 0) {
    		i = n/k - 1;
  	  	}
    	else {
    		i = int(n/k);
		}
		cell_value = (k*i)+1;
//		cout << "(" << k << "," << i << ") " << cell_value << endl;
		if (cell_value == n) {
			found_composite_Z1 = true;
			k = n;
		}
		k++;
	}
//	cout << n << "  Cell Count = " << cell_count;
	if (found_composite_Z1 == false) {
		cout << n << "," << cell_count;
//		cout << fixed;
//		cout.precision(2);
//		percent_cells = cell_count/n * 100;
//		cout << "," << percent_cells << "%";
	} 
	return found_composite_Z1;
}
   
bool check_Zone_2_for_2(long long int n) {  
	long long int k = 2, i = n;
	long long int cell_value;
	bool found_composite_Z2 = false;
	while ((k < n/2 + 1) && (i > k)) {
    	if (n%k == 0) {
    		i = n/k;
  	  	}
    	else {
    		i = int(n/k) + 1;
		}
		cell_value = (k*i)-n+1;
//		cout << "(" << k << "," << i << ") " << cell_value << endl;
		if (cell_value == 2) {
			found_composite_Z2 = true;
			k = n;
		}
		k++;
	}
	return found_composite_Z2;
}  

int main() {
	long long int six_m;
	long long int low_bound, high_bound, lowest_six_m;
	long long int total_twin_primes = 0;
	long long int total_primes = 0;
	bool found_atleast_one = false;
	bool found_comp_Z1, found_comp_Z2;
	long long int last_prime_found, last_twin_prime_1, last_twin_prime_2;
	
	time_t timestamp;
	
	cout << "===================================" << endl;
	cout << "Find_Primes_using_Zones_in_Range.cpp" << endl;
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
    	found_comp_Z1 = check_Zone_1_for_n(six_m);
//   	found_comp_Z2 = check_Zone_2_for_2(six_m);
   		
		if (found_comp_Z1 == false) {   
			total_primes++;
			last_prime_found = six_m - 1;
//			cout << "n-1 is Prime." << endl;
			cout << "," << six_m-1 << ",Prime" << endl;
		}
		else {
//			cout << "n-1 is Composite." << endl;
//			cout << "," << six_m-1 << ",Composite" << endl;
		}
//		if (found_comp_Z2 == false) {
//			total_primes++;
//			last_prime_found = six_m + 1;
//		}
//
//    	if ((found_comp_Z1 == false) && (found_comp_Z2 == false)) {
//    		cout << six_m - 1 << ", " << six_m + 1 << " are Twin Primes." << endl;
//			last_twin_prime_1 = six_m - 1;
//			last_twin_prime_2 = six_m + 1;
//    		found_atleast_one = true;
//    		total_twin_primes
//		}
		six_m = six_m + 6;
	}
	
//	cout << "===================================" << endl;
//	cout << endl;
//	cout << "Lower Bound:  " << low_bound << endl;
//	cout << "Upper Bound:  " << high_bound << endl;
//	cout << "Total Primes found:  " << total_primes << endl;
//	cout << "Last Prime Found:  " << last_prime_found << endl;
//	cout << "Last Twin Prime Found:  (" << last_twin_prime_1 << "," << last_twin_prime_2 << ")" << endl;
//	if (found_atleast_one == false) {
//		cout << "No Twin Primes Found." << endl;
//	}
//	else {
//		cout << "Total Number of Twin Primes found:  " << total_twin_primes << endl;
//	}
	cout << endl;
	time(&timestamp);
	cout << "===================================" << endl;
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End_code



