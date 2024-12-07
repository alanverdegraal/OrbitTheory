// Check_Zone_1_for_n.cpp
// Created by Alan Verdegraal   March 4, 2024
//
// This program checks Zone 1 for n to see if n-1
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

bool check_4_n_in_zone_1(long long int n) {
       long long int cell_value, midpoint;
       long long int i, c, r;
       bool found_n = false;

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
                     c=int(n/i); r=i;
                     cell_value = get_cell_value(n,c,r);
              }
              if (cell_value == n) {
                     found_n=true;
                     i = midpoint+1;
              }	
       }
       return found_n;
}

int main() {
       long long int n;
       bool found_n = false;
	
       cout << "Enter value for n: ";
       cin >> n;

       found_n=check_4_n_in_zone_1(n);
	
       if (found_n == false) {
              cout << n << " has no n in Zone 1. " << "Thus, " << n-1 << " is prime.";
       }
       else {
              cout << n << " has an n in Zone 1. " << "Thus, " << n-1 << " is composite.";
       }
}

// End_code

