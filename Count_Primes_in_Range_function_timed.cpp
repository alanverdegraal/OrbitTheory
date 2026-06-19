// Count_Primes_in_Range_function_timed.cpp
// Created by Alan Verdegraal January 27, 2023
//      Modified February 3, 2026 adding timing
//
// This function returns the count of primes
// between and including two numbers.
//
// A function is created called check4prime that takes an integer
// as input and returns the boolean found_prime.
//
// This function follows the Staircase Search Path in looking for a 1
// in a Square Sq(n) to determine if the number n is a composite number.
// It starts at the Kernel cell K11(n), moving right and up, in a
// staircase fashion. If it finds a 1 as the value in any cell, then
// Square Sq(n) is a composite number.
//
// If it does not find a 1 through the Staircase Search, then
// it prints a message indicating that n is a prime. This is 
// based upon the Staircase Conjecture that for any composite number 
// there is a 1 on the main diagonal of the Latin Square LS(n) 
// or immediately adjacent to it. This has been demonstrated to be
// accurate for all Composites and Primes up through 1,000,000.
//
// This C++ program uses 64-bit number size with data type long long int.
// Maximum value of any register is the limit 9223372036854775807.
// Since the formula of the Staircase Search Path involves squaring n
// the maximum number able to be processed is the square root of the limit
// or 3032000000.
//
// However, through testing, the maximum Prime that a Windows 10 64-bit 
// laptop can identify is 4294967291. Beyond that, the limits begin to 
// identify known Primes as Composites due to exceeding system limits.
// 
// To print out primes, uncomment the print line.
//

#include <iostream>
#include <math.h>
#include <limits>
#include <ctime>
using namespace std;

bool check4prime(long long int n) {
   long long int j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_prime = true;
   if (((n%2==0) && (n!=2)) || (n==1)) {
   	  found_prime=false;
   }
   else {
	   	j++;
   		while (j < n - 2) {
      		b4_mod_value = (((n*n) - (2*j*n) + (j*j) + 3 + (j % 2))/4);
      		cell_value = b4_mod_value % n;
      		if (cell_value == 1) {
         		found_prime = false;
         		j = n - 2;
      		}
      		j++;
      }
   }
   return found_prime;
}

long long int count_primes_in_range (long long int n1, long long int n2) {
	long long int total_primes=0, k;
	bool found_prime = false;
	for (k=n1; k<=n2; k++) {
		found_prime=check4prime(k);
		if (found_prime==true) {
			total_primes++;
//			Uncomment the following line to print out primes.			
//			cout << k << " is a Prime." << endl;
		}
	}
	return total_primes;
}

int main() {
	long long int beginning_value, ending_value;
	long long int total_primes = 0;
	
	time_t timestamp;
	
	cout << "===================================" << endl;
	cout << "Count_Primes_in_Range_function_timed.cpp" << endl;
	cout << "===================================" << endl;	
	cout << "Enter the value for lowest bound: ";
    cin >> beginning_value; 
	cout << "Enter the value for highest bound: ";
    cin >> ending_value; 
	cout << "===================================" << endl;	
	time(&timestamp);	
	cout << "Start date and time: " << ctime(&timestamp);
		
	total_primes = count_primes_in_range (beginning_value,ending_value);
	
	cout << "===================================" << endl;
	cout << endl;
	cout << "Lower Bound:  " << beginning_value << endl;
	cout << "Upper Bound:  " << ending_value << endl;
	cout << "Total Primes found:  " << total_primes << endl;
	cout << "===================================" << endl;
	cout << endl;
	time(&timestamp);
 	cout << "End date and time: " << ctime(&timestamp);
 	cout << "===================================" << endl;
}

// End Code
