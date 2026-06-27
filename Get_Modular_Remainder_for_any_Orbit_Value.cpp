// Get_Modular_Remainder_for_any_Orbit_Value.cpp
// Created by Alan Verdegraal June 13, 2023
//
// For an Orbit On(d), this returns the modular
// remainder r where n === r (mod d).
//
// Basically, it counts the Orbit cells from 
// Ok(d) to Ok(d)=1 for decreasing k.
//
// It uses the function get_orbit_value(n,d).
// 

#include <iostream>
#include <limits>
using namespace std;

long long int get_orbit_value (long long int n, long long int d) {
      long long int k, t=0;
      long long int orbit_value;

      k = 1 + d;                      // starting value of the sequence

      while (k != 1) {  
         if (k > n) {
            k -= n;       // k after the modulo operation: if k > n, then k = k - n
            t++;          // t being incremented when passing 1 on the circle, 
			                 //       increasing the Orbit for that sequence
         } 
         else {
            k += d;            // k being increased by the increment
         }
      }
      orbit_value = t;
      return orbit_value;
    }

int main() {
   long long int orbit_value, remainder=0;
   long long int d, n, k;

   cout << "Enter the value for n: ";
   cin >> n;
   cout << "Enter the value for d: ";
   cin >> d; 
   
   orbit_value = get_orbit_value(n,d);
   
   if (orbit_value == 1) {
   		cout << "Remainder for (" << n << "," << d << ") is " << remainder << endl;
   }
   else {
   		k=n;
   		remainder++;
   	  	while (orbit_value != 1) {
   	  		k--;
   	  		orbit_value = get_orbit_value(k,d);
			if (orbit_value == 1) {
				cout << "Remainder for (" << n << "," << d << ") is " << remainder << endl;
			}
			else {
				remainder++;
			}
			
		}
   	}
}

// End_code
