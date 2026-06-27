// Find_Equidistant_Primes_from_another_Prime.cpp
// Created by Alan Verdegraal  February 9, 2023
// 
// This finds two primes that are equidistant from another
// prime. Most of these are not Balanced Primes since a
// Balanced Prime has no other primes between it and its
// two nearest equidistant primes.
//
// This will search a range of numbers. When it finds
// a Prime p2, it backtracks to the first Prime p1 encountered,
// then checks if there is a Prime p3 equidistance from Prime
// p2. 
//

#include <iostream>
#include <math.h>
#include <limits>
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
	int long long i, gap;
	bool found_prime = false;
	int long long center_prime;
	int long long p1, p2, p3;
	
	cout << "Enter center prime: ";
	cin >> center_prime;
	
	cout << "Searching for Equidistant Primes from " << center_prime << endl;
	cout << "=============================================" << endl;

	found_prime=check4prime(center_prime);
	if (found_prime==true) {
		p2=center_prime;
		for (i=2; i<p2; i++) {
			found_prime=check4prime(i);
			if (found_prime==true) {
				p1=i;
				gap=p2-p1;
				found_prime=check4prime(p2+gap);
				if (found_prime==true) {
					p3=p2+gap;
					cout << "p1=" << p1 << " p2=" << p2;
					cout << " p3=" << p3 << " :: ";
					cout << p2-p1 << endl;
				}
			}
		}
	}
	else {
		cout << "Entered number is not Prime. Exiting." << endl;
		i=center_prime+1;
	}
}

// End Code
