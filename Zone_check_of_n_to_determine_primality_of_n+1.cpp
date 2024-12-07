// Zone_check_of_n_to_determine_primality_of_n+1.cpp
// Created by Alan Verdegraal   March 4, 2024
//
// This program checks Zone 2 for a 2 in Square Sq(n) to see if n+1
// is a prime or composite number.
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
 
bool check_4_2_in_zone_2(long long int n) {
       long long int cell_value, midpoint;
       long long int i, c, r;
       bool found_2 = false;

       if (n%2==0) {
             midpoint=n/2;
       }
       else {
              midpoint=((n+1)/2);
       }	
       for (i=2; i<=midpoint; i++) {
              if (n%i == 0) {
                     c=n/i; r=i;
                     cell_value = get_cell_value(n,c,r);	
              }
              else {
                     c=int(n/i)+1; r=i;
                     cell_value = get_cell_value(n,c,r);
              }
              if (cell_value == 2) {
                     found_2=true;
                     i = midpoint+1;
              }	
       }
       return found_2;
}

int main() {
       long long int n;
       bool found_2 = false;
	
       cout << "Enter value for n: ";
       cin >> n;

       found_2=check_4_2_in_zone_2(n);
	
       if (found_2 == false) {
              cout << n << " has no 2s in Zone 2. " << "Thus, " << n+1 << " is prime.";
       }
       else {
              cout << n << " has a 2 in Zone 2. " << "Thus, " << n+1 << " is composite.";
       }
}

// End_code
