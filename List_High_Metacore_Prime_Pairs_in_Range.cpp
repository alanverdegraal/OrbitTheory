// List_High_Metacore_Prime_Pairs_in_Range.cpp
// Created by Alan Verdegraal
//
// Sophie Germain Primes are primes where 2*p+1
// is also a prime known as a Safe Prime. These
// pairs of primes are those where 2*p-1 is also
// a prime. These are all High Metacore Primes.
//
// This program goes through a range of numbers
// looking for primes and identifying any High
// Metacore Prime Pairs that meet the 2*p-1 criteria.
//
#include <iostream>
#include <math.h>
#include <limits>
#include <iomanip>
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

int main() {
	bool found_first_prime = false;
	bool found_second_prime = false;
	long long int beginning_value, ending_value;
    long long int i, j, print_option;
    float diff_divided_by_3;
 
 	cout << "List High Metacore Prime Pairs" << endl;
 	cout << "==============================" << endl;
 	cout << endl;
 	cout << "Print Options:" << endl;
 	cout << "     1 - Print High Metacore Prime Pairs only" << endl;
 	cout << "     2 - Print P2 Primes only" << endl;
 	cout << "     3 - Print Pairs in Set format" << endl;
 	cout << "     4 - Print Pairs separated by a Comma" << endl;
 	cout << "     5 - Print Difference between P1 and P2" << endl;
 	cout << "     6 - Print the Difference divided by 3" << endl;
 	cout << endl;
 	cout << "Enter the desired Print Option: ";
 	cin >> print_option;
 	cout << endl;
     
    cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 
    cout << endl;

    for (i = beginning_value; i < ending_value; i++) { 
		found_first_prime=check4prime(i);
		if (found_first_prime==true) {
			j=2*i-1;    // The minus sign is the only change from SGP program.
			found_second_prime=check4prime(j);
			if (found_second_prime==true) {
				if (print_option == 1) {
					cout << i << endl;
				}
				if (print_option == 2) {
					cout << j << endl;
				}
				if (print_option == 3) {
					cout << "{" << i << "," << j << "}" << endl;
				}
				if (print_option == 4) {
					cout << i << "," << j << endl;
				}
				if (print_option == 5) {
					cout << i << "  " << j << "  Diff = " << j - i << endl;
				}
				if (print_option == 6) {
					diff_divided_by_3 = (j - i)/3.0;
					cout << i << "  " << j << "  Diff = " << j - i;
					cout << "  Diff/3 = " << setprecision(10) << diff_divided_by_3 << endl;
				}	
			}
		}
	}
}

// End Code
