// Display_any_Primes_that_do_not_meet_6n-1_or_6n+1.cpp
// Created by Alan Verdegraal 12/04/2022 

#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

bool check4prime(long long int n) {
   long long int j = 0;
   long long int cell_value = 0;
   long long int b4_mod_value = 0; 
   bool found_prime = false;
   if (n!=1) {
      found_prime = true;
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
	bool found_prime = false;
	long long int beginning_value, ending_value;
	long long int num_found_primes=0, total_matching=0, total_not_matching=0;
    long long int i, n;
    
    cout << "Enter the initial value of the range: ";
    cin >> beginning_value;
    if (beginning_value <= 1) {beginning_value = 2;}  // only integers > 1 are allowed
    cout << "Enter the final value of the range: ";
    cin >> ending_value; 
    if (ending_value - beginning_value < 0) {ending_value = beginning_value;} 
                                // range must be > 0
    cout << endl;
   
    cout << "Display Primes that do not meet 6n-1,6n,6n+1 between " << beginning_value;
    cout << " and " << ending_value << endl;
    cout << "=========================" << endl;      
    
  
    for (i = beginning_value; i <= ending_value; i++) { 
        found_prime=false;
        n=i;
        if (n%2==0) {
        	n++;
        	i++;
		}
		found_prime=check4prime(n);
		if (found_prime==true) {
			num_found_primes++;
		    if (((n+1)%6 == 0) || ((n-1)%6 == 0)) { 
			   total_matching++;
		    }
		    else {
		       cout << n << endl;
		       total_not_matching++;
		    }
	    }
    }
    cout << "Number Found Primes " << num_found_primes << endl;
    cout << "Total Matching " << total_matching << endl;
	cout << "Total Not Matching " << total_not_matching << endl;
}

// End_Code

