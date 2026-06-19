// Check_product_table_4_composite_timed_precision.cpp
// Created by Alan Verdegraal -- June 9, 2026
// Added June 11, 2026 -- Using high precision clock.
//
// This creates a function called alt_check4composite that takes an integer
// as input and returns the boolean found_composite.
//
// This follows the Staircase Search Path but looks for factors and cofactors
// in a Square Sq(n) to determine if the number n is a Composite number.

// It starts at the main diagonal where j=3 and walks down that diagona
// to the Kernel. Then it descends the diagonal below the main diagonal.
// If it finds a factor or cofactor for n, it has found a composite number.
// If it doesn't find these, then the number is deemed a prime.

// This function has been optimized to exit as soon as it finds
// a composite number.

// This has been demonstrated to be accurate for all Composites and 
// Primes up through 1,000,000.
//
// This C++ program uses 64 bit number size with data type long long int.
// Maximum value of any register is the limit 9223372036854775807
// Since the formula of the Staircase Search Path involves squaring n
// the maximum number able to be processed is the square root of the limit
// or 3032000000.
//
// However, through testing, the maximum Prime that my Windows 10 64-bit 
// laptop can identify is 4294967291. Beyond that, the limits begin to 
// identify known Primes as Composites due to exceeding system limits.

#include <iostream>
#include <math.h>
#include <limits>
#include <chrono>
using namespace std;

bool check_product_table_4_composite(unsigned long long int n) {
   unsigned long long int j = 0;
   bool found_composite = false;
   unsigned long long int half_n = trunc((n-1)/2 - 1);

   for (j = 3; j <= half_n; j++) {
		if ((j * j) % n == 0) {
			found_composite = true;
			j = half_n + 1;
		}
		else {
		    if ((j * (j + 1)) % n == 0) {
				found_composite = true;
				j = half_n + 1;
			}
		}	
	}	
    return found_composite;
}

int main() {
   bool found_composite = false;
   unsigned long long int n;
   
   time_t timestamp;
	
   cout << "===================================" << endl;
   cout << "Check_product_table_4_composite_timed_precision.cpp" << endl;
   cout << "===================================" << endl;	   
   cout << "Enter the value for n: ";
   cin >> n; 

   cout << "===================================" << endl;	
   time(&timestamp);	
   cout << "Start date and time: " << ctime(&timestamp);
   cout << "===================================" << endl;	
   auto start = std::chrono::high_resolution_clock::now();   
		
   found_composite = check_product_table_4_composite(n);
   
   auto end = std::chrono::high_resolution_clock::now();

   if (found_composite == true) {
   	   cout << endl;
       cout << "Number " << n << " is Composite." << endl;
   }
   else {
       cout << endl;
	   cout << "Number " << n << " is Prime." << endl;
   }
    cout << endl;
	cout << "===================================" << endl;
// 	auto duration = std::chrono::duration_cast < std::chrono::microseconds > (end - start);
// 	std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

 	auto duration = std::chrono::duration_cast < std::chrono::nanoseconds > (end - start);
 	std::cout << "Time taken: " << duration.count() << " nanoseconds" << std::endl;

//    std::chrono::duration<double, std::milli> ms_double = end - start;
//    std::cout << "Time taken: " << ms_double.count() << " milliseconds" << std::endl;	
	cout << "===================================" << endl;
}

// End code

