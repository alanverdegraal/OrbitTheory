// Validate_High_Metacore_Prime_Pairs.cpp
// Created by Alan Verdegraal July 14, 2023
//
// This checks the High Metacore Prime Pair Orbit
// Structure at a variety of known Orbit Values 
// where On(d)=1. A High Metacore Prime Pair are
// two Primes where P2=2*P1-1.
//
// It will print out a letter location from the
// generic map of a High Metacore Prime Pair Orbit
// Structure. All the values should be 1, except
// R, which is the midpoint of the P1-1 row.
//
#include <iostream>
#include <math.h>
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
    long long int orbit_value;
    long long int d, n;
    long long int P1, P2;
    
	cout << "Enter the initial Prime P1 value: ";
    cin >> P1;
    cout << "Enter the second Prime P2 value: ";
    cin >> P2; 
    cout << endl;
    
	cout << "Validating High Metacore Prime Pairs: " << P1 << "  " << P2 << endl;
	cout << "==============================================" << endl;
    n=P1-1; d=(P1-1)/3;
    orbit_value=get_orbit_value(n,d);
	cout << "A: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1+2; d=(P1-1)/3 + 1;
	orbit_value=get_orbit_value(n,d);
	cout << "B: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-5; d=(P2-P1)/2 - 1;
	orbit_value=get_orbit_value(n,d);
	cout << "C: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1-1; d=(P2-P1)/2;
	orbit_value=get_orbit_value(n,d);
	cout << "D: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=(P1+P2)/2 - 1; d=(P2-P1)/2;
	orbit_value=get_orbit_value(n,d);
	cout << "E: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-1; d=(P2-P1)/2;
	orbit_value=get_orbit_value(n,d);
	cout << "F: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1+1; d=(P2-P1)/2 + 1;
	orbit_value=get_orbit_value(n,d);
	cout << "G: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=(P1+P2)/2 + 2; d=(P2-P1)/2 + 1;
	orbit_value=get_orbit_value(n,d);
	cout << "H: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-4; d=2*(P1-1)/3 - 1;
	orbit_value=get_orbit_value(n,d);
	cout << "I: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1-1+(P1-1)/3; d=2*(P1-1)/3;
	orbit_value=get_orbit_value(n,d);
	cout << "J: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-1; d=2*(P1-1)/3;
	orbit_value=get_orbit_value(n,d);
	cout << "K: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1+1+(P1-1)/3; d=2*(P1-1)/3 + 1;
	orbit_value=get_orbit_value(n,d);
	cout << "L: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-5; d=P1-3;
	orbit_value=get_orbit_value(n,d);
	cout << "M: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-3; d=P1-2;
	orbit_value=get_orbit_value(n,d);
	cout << "N: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2-1; d=P1-1;
	orbit_value=get_orbit_value(n,d);
	cout << "O: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1-1; d=P1-1;
	orbit_value=get_orbit_value(n,d);
	cout << "P: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P1; d=P1;
	orbit_value=get_orbit_value(n,d);
	cout << "Q: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=(P1+P2)/2; d=P1-1;
	orbit_value=get_orbit_value(n,d);
	cout << "R: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	n=P2+1; d=P1;
	orbit_value=get_orbit_value(n,d);
	cout << "S: n=" << n << " d=" << d << " On(d)= " << orbit_value << endl;
	
}

// End Code
