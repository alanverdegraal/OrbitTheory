// Primality_Check_using_the_Zone_Sector.cpp
// Created by Alan Verdegraal   February 1, 2024
//
// This program checks the first cell value on each
// row for Zone m that lay in primality sector. It then
// checks the cell value to see if it equals the Zone number.
// If it does equal the Zone number, then n+1 is composite.
// If the cell values never equal the Zone number, then
// n+1 is prime.
//
#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

long long int get_cell_value(long long int n, long long int c, long long int r) {
	long long int b4_mod_value, remainder, cell_value, j;
	b4_mod_value=0;
	for (j=1; j<=r; j++) {
		b4_mod_value = b4_mod_value + c;
	}
//	cout << b4_mod_value << endl;
	remainder = b4_mod_value%n;
	cell_value = remainder + 1;
	return cell_value;
}


long long int get_first_value(long long int n, long long int m, bool prime_flag) {
	long long int cell_value;
	long long int k, c, r;
	bool found_prime;

    for (k=m; k<=int(n/2)+1; k++) {
//    	cout << "k=" << k << endl;
 		found_prime=prime_flag;	
	   	if (((m-1)*n)%k == 0) {
   			c=((m-1)*n)/k; r=k;
   			cell_value = get_cell_value(n,c,r);	
		}
		else {
			c=int(((m-1)*n)/k)+1; r=k;
			cell_value = get_cell_value(n,c,r);
		}
		if ((c>=m) && (c<=int(n/2)+1) && (r<=c)) {
//			cout << "c is " << c << " and m is " << m << endl;
//			cout << "The cell value for n = " << n << " in zone " << m << " at location (" << c << "," << r << ") is " << cell_value << endl;
//			cout << "m is " << m << " (" << n << ", " << c << ", " << r << ")" << " and cell_value is " << cell_value << endl;
			if (m == cell_value) {
//				cout << "Testing m vs cell_value." << endl;
				found_prime = false;
				k=n;
//				cout << "k = " << k << endl;
				return found_prime;
			}
		}	
	}
	return found_prime;
}

int main( int argc, char *argv[] ) {
	long long int n, m;
	bool found_prime=true, stop=false, prime_flag=true;
	
	n = stoll( argv[1] );
	
//	cout << "Enter value for n: ";
//	cin >> n;
	
    while ((found_prime == true) && (stop==false)) {
		for (m=2; m<=n/2; m++) {
			if (stop==false) {
//				cout << "m is " << m << endl; 
				found_prime = get_first_value(n, m, prime_flag);
				prime_flag = found_prime;
				stop=true;
			}
			else {
				m=n;
//				cout << "prime_flag= " << prime_flag << " m = " << m << endl;
			}
		}
		if (found_prime==true) {
			cout << "n+1 = " << n+1 << " is a prime number." << endl;
		}		
		else {
			cout << "n+1 = " << n+1 << " is a composite number." << endl;
		}
		stop = true;
	}	
}
// End_code
