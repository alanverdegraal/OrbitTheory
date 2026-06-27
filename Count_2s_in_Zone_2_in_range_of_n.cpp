// Count_2s_in_Zone_2_in_range_of_n.cpp
// Created by Alan Verdegraal   March 16, 2024
//
// This program checks Zone 2 for 2 to see if n+1
// is a composite number. It counts the number of
// 2s for each number as it traverses a range of
// values but does not include the starting value of n.
// It also includes the last n plus one more since it
// processes a particular n to determine if n+1 is prime
// or composite.
// 
// For more detailed output, remove the comment characters
// as needed.
//
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

long long int count_2s_in_zone_2(long long int n) {
	long long int cell_value, midpoint;
	long long int i, c, r;
	long long int count_of_2s = 0;
	
//	cout << endl;
//	cout << "Checking " << n << endl;

	if (n%2==0) {
		midpoint=n/2;
	}
	else {
		midpoint=((n+1)/2);
	}
	
    for (i=2; i<=midpoint; i++) {
    	if (n%i == 0) {
    		c=n/i; r=i;
//    		cout << "col=" << c << " row=" << r << " :: ";
    		cell_value = get_cell_value(n,c,r);	
//    		cout << cell_value << " ::: ";
		}
		else {
			c=int(n/i)+1; r=i;
//			cout << "col=" << c << " row=" << r << " :: ";
			cell_value = get_cell_value(n,c,r);
//			cout << cell_value << " ::: ";
		}
		if (cell_value == 2) {
	     	count_of_2s++;
//	     	cout << count_of_2s << endl;
		}
		else {
//			cout << count_of_2s << endl;
		}
	}	
//	cout << endl;
	return count_of_2s;
}

int main() {
	long long int n, i;
	long long int start_value, ending_value;
	long long int total_primes=0, total_composites=0;
	long long int total_2s = 0;
	
	cout << "Enter starting value for n: ";
	cin >> start_value;
	cout << "Enter ending value for last n: ";
	cin >> ending_value;
	
	for (i=start_value; i<=ending_value; i++) {
		n = i;
		total_2s=count_2s_in_zone_2(n);
		
//		cout << n << " : Total 2s is " << total_2s << " | ";
//		cout << n << " : Total 2s is " << total_2s << endl;
		cout << n << "  " << total_2s << endl;
	
		if (total_2s == 0) {
//			cout << n+1 << " is prime." << endl;
			total_primes++;
		}
		else {
//			cout << n+1 << " is composite." << endl;
			total_composites++;
		}
	}
	cout << endl;
//	cout << "Total primes found from " << start_value+1 << " through " << ending_value+1 << " is " << total_primes << endl;
//	cout << "Total composites found from " << start_value+1 << " through " << ending_value+1 << " is " << total_composites << endl;
}

// End_code
