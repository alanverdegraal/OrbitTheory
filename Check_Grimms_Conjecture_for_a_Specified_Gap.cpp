// Check_Grimms_Conjecture_for_a_Specified_Gap.cpp
// Created by Alan Verdegraal June 20, 2023
//
// Grimm's Conjecture states that in any set of
// consecutive composite numbers between two consecutive
// primes, there are distinct prime factors for every
// composite number.
//
// This program checks the gap containing consecutive
// composite numbers, creating a partial Orbit Table
// for those numbers through the (ending_value+1)/2. 
// Factors do not appear beyond that point, except for
// the number N itself. The first column of this array
// has the values for increment-d. The top row is the
// list of prime and composite numbers being considered.
//
// It then cleans this up by deleting any rows without
// prime factors.
//
// It then validates if there is a distinct set
// of prime factors for this set of consecutive primes.
//
// There are two functions that are called:
// 		check4primes(n) -- Determines if a number is prime.
//		get_orbit_value(n,d) -- Gets the Orbit Value for a
//                           -- number n and increment-d.       
//
// There are three arrays that are created with this 
// program:
//      arr[a][b] -- Array of Orbit Values for Range,
//				  -- only includes up to (ending_value+1)/2.
//		array_of_factors[a][b] -- Includes only rows
//							   -- with factors deleting
//							   -- rows with no prime factors.
//		val_array[a][b] -- A two row array to hold the
//                      -- set of distinct factors for 
// 						-- for validation.
// 
// The program uses the formatting option setw() to place
// array output in columns. At the beginning in main(),
// the width_parameter is set to control the width of the
// output columns. The default is 5.
//
// The program requires the replacement of duplicate
// validation factors to achieve a set of distinct factors.
// Toward the end, there is a routine that does this and
// selects a new factor in the appropriate column.
// This routine is run twice in case that the first check
// also produces a duplicate factor. 
// 
// It is possible that for large gaps between large primes,
// duplicate factors will remain. The program will notify
// in those last routines if a duplicate is found. Always
// check the values in the last validation array to ensure
// there are no dups any longer, especially if dups were
// found.
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
	long long int beginning_value, ending_value;
	long long int i, j, k, l, m;
	long long int orbit_value, found_prime;
	long long int num_of_columns, num_of_rows, rows_with_factors, new_row_index;
	bool set_0_flag=false, grimms_counterexample_found=false, incomplete=false;
	long long int save_d, save_i, save_j, count_of_factors, save_orbit, total_rows;
	int width_parameter=5;

	cout << "Check on Grimm's Conjecture " << endl;
	cout << "for a set of consecutive composite numbers" << endl;
	cout << "between two prime numbers." << endl;
	cout << "==========================================" << endl;
	cout << endl;

	cout << "Enter a range of consecutive numbers bounded by two primes." << endl;	
	cout << "Enter the value of the first prime: ";
    cin >> beginning_value;
    cout << "Enter the value of the last prime: ";
    cin >> ending_value; 
    cout << endl;
    
    num_of_columns=ending_value - beginning_value + 2;
    num_of_rows=(ending_value+1)/2;
	    
    long long int arr[num_of_rows][num_of_columns];

// Initialize array
	for (l=0; l < num_of_rows; l++) {
		for (k=0; k <= num_of_columns; k++) {
			arr[l][k]=0;
		}
	}    

//   Initialize first row with values of n
	for (l=0; l < num_of_rows; l++) {    
		m=0;  
		for (k=1; k < num_of_columns; k++) {
     		arr[0][k]=beginning_value+m;
     		m++;
		}
	}

//	Initialized first column with values incrementing by 1
	for (l=0; l < num_of_rows; l++) {
		arr[l][0]=l;
	}

// Populate the array with Orbit Values
	for (j=1; j < num_of_rows; j++) {
		l=1;
		for (i=beginning_value; i<=ending_value; i++) {
			if (j>i) {
				arr[j][l]=0;
			}
			else {
				orbit_value=get_orbit_value(i,j);
				arr[j][l]=orbit_value;
			}
			l++;
		}
	}

// Print entire array
	cout << "Orbit Table Values" << endl;
	cout << endl;
	for (l=0; l < num_of_rows; l++) {  
		for (k=0; k < num_of_columns; k++) {  
    		cout << setw(width_parameter) << arr[l][k] << " ";
   	 	}
    	cout << endl;
	}    
    cout << endl;
    
// Find factors in the original array.

	cout << "Factors   N" << endl;
	cout << endl;
	for (j=2; j < num_of_rows; j++) {
		for (i=1; i < num_of_columns; i++) {
			if (arr[j][i]==1) {
				cout << setw(width_parameter) << arr[j][0];
				cout << setw(width_parameter) << arr[0][i] << endl;
			}
		}
	}

// Count rows with factors in the original array
	rows_with_factors=0;
	set_0_flag=false;
	for (j=2; j < num_of_rows; j++) {
		for (i=1; i < num_of_columns; i++) {
			if (arr[j][i]==0) {
				set_0_flag=true;
			}
			else {
				if (arr[j][i]==1) {
					if (set_0_flag==false) {
						found_prime=check4prime(j);
						if (found_prime==true) {
							rows_with_factors++;
							i=num_of_columns;
						}
					}
				}
			set_0_flag=false;
			}
		}
	}
	cout << endl;
	cout << "Number of Rows with Factors = " << rows_with_factors << endl;
	cout << endl;
	total_rows=rows_with_factors+1;

// Create new array and initialize
	long long int array_of_factors[total_rows][num_of_columns];
	for (j=0; j <= total_rows; j++) {
		for (i=0; i <= num_of_columns; i++) {
			array_of_factors[j][i]=0;
		}
	}

// Initialize first row
	for (i=1; i < num_of_columns; i++) {
		array_of_factors[0][i] = beginning_value + i - 1;
	}

// Print new_array
//	for (l=0; l < total_rows; l++) {  
//		for (k=0; k < num_of_columns; k++) {  
//    		cout << setw(width_parameter) << array_of_factors[l][k] << " ";
//   	 	}
//    	cout << endl;
//	}    
//    cout << endl;

// Copy rows with factors from original array to array_of_factors
// The set_0_flag is for leading 0s before a first 1.
	set_0_flag=false;
	new_row_index=1;
	for (j=0; j < num_of_rows; j++) {
		for (i=1; i < num_of_columns; i++) {
			if (arr[j][i]==0) {
				set_0_flag=true;
			}
			else {
				if (arr[j][i]==1) {
					if (set_0_flag==false) {
						found_prime=check4prime(j);
						if (found_prime==true) {
							for (m=0; m<num_of_columns; m++) {
								array_of_factors[new_row_index][m]=arr[j][m];
							}
							new_row_index++;
							i=num_of_columns;				
						}
						found_prime=false;
					}
				}
			set_0_flag=false;
			}
		}
	}

// Print new_array
	cout << endl;
	cout << "Prime Rows with Factors" << endl;
	cout << endl;
	for (l=0; l < total_rows; l++) {  
		for (k=0; k < num_of_columns; k++) {  
    		cout << setw(width_parameter) << array_of_factors[l][k] << " ";
   	 	}
    	cout << endl;
	}    
    cout << endl;

// Validate Grimm's Conjecture for entered range
	cout << "Validation of Grimm's Conjecture" << endl;
	cout << endl;
	cout << "Validation Array" << endl;
	cout << endl;


// Create a validation array
	long long int val_array[2][num_of_columns];
	for (i=0; i<2; i++) {
		for (j=0; j<=num_of_columns; j++) {
			val_array[i][j]=0;
		}
	}

// Print validation array
//	for (i=0; i<2; i++) {
//		for (j=0; j<num_of_columns; j++) {
//			cout << setw(width_parameter) << val_array[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;

// Initialize first row
	for (j=1; j<num_of_columns; j++) {
		val_array[0][j] = beginning_value+j-1;
	}	

	cout << "Initialized" << endl;
	cout << endl;

// Print validation array
	for (i=0; i<2; i++) {
		for (j=0; j<num_of_columns; j++) {
			cout << setw(width_parameter) << val_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

// Check for single factor
	for (j=2; j<num_of_columns; j++) {
		count_of_factors=0;
		for (i=0; i<total_rows; i++) {
			if (array_of_factors[i][j]==1) {
				count_of_factors++;
				save_i=i;
				save_j=j;
			}
		}
		if (count_of_factors==1) {
			save_d=array_of_factors[save_i][0];
			val_array[1][j]=save_d;
		}
	}

	cout << "Single Factors (Powers of the Factor)" << endl;
	cout << endl;

// Print validation array
	for (i=0; i<2; i++) {
		for (j=0; j<num_of_columns; j++) {
			cout << setw(width_parameter) << val_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

// Grab last factor
	for (m=1; m<num_of_columns; m++) {
		if (val_array[1][m]==0) {
			for (j=2; j<num_of_columns-1; j++) {
				count_of_factors=0;
				for (i=0; i<total_rows; i++) {
					if (array_of_factors[i][j]==1) {
						count_of_factors++;
						save_i=i;
						save_j=j;
					}
				}	
				save_d=array_of_factors[save_i][0];
				val_array[1][j]=save_d;
			}
		}
	}

	cout << "Including Last Factors" << endl;
	cout << endl;

// Print validation array
	for (i=0; i<2; i++) {
		for (j=0; j<num_of_columns; j++) {
			cout << setw(width_parameter) << val_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

// Check validation array for duplicate numbers
	for (m=2; m<num_of_columns; m++) {
		save_orbit=val_array[1][m];
		for (j=2; j<num_of_columns; j++) {
//			cout << save_orbit << " " << val_array[1][j] << endl;
			if ((val_array[1][j]==save_orbit) && !(m==j)) {
				cout << "Found duplicates in columns " << m << " " << j << endl;
				for (k=0; k<total_rows; k++) {
//					cout << "Row# is " << k << endl;
//					cout << "Array value is " << array_of_factors[k][j] << endl;
					if (array_of_factors[k][j]==1) {
						save_d=array_of_factors[k][0];
//						cout << "save_d = " << save_d << endl;
						val_array[1][j]=save_d;	
						k=total_rows;					
					}
				}
			}
		}
	}

	cout << endl;
	cout << "First Replacement of Duplicate Factors" << endl;
	cout << endl;

// Print validation array
	for (i=0; i<2; i++) {
		for (j=0; j<num_of_columns; j++) {
			cout << setw(width_parameter) << val_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

// Second Check of Validation Array for duplicate numbers
	for (m=2; m<num_of_columns; m++) {
		save_orbit=val_array[1][m];
		for (j=2; j<num_of_columns; j++) {
//			cout << save_orbit << " " << val_array[1][j] << endl;
			if ((val_array[1][j]==save_orbit) && !(m==j)) {
				cout << "Found duplicates in columns " << m << " " << j << endl;
				for (k=1; k<total_rows; k++) {
					if (array_of_factors[k][j]==1) {
						save_d=array_of_factors[k][0];
						val_array[1][j]=save_d;	
						k=total_rows;					
					}
				}
			}
		}
	}

	cout << "Second Replacement Check" << endl;
	cout << endl;

// Print validation array
	for (i=0; i<2; i++) {
		for (j=0; j<num_of_columns; j++) {
			cout << setw(width_parameter) << val_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

// Last check of validation array for duplicate numbers
	for (m=2; m<num_of_columns; m++) {
		save_orbit=val_array[1][m];
		for (j=2; j<num_of_columns; j++) {
			if ((val_array[1][j]==save_orbit) && !(m==j)) {
				cout << "Found duplicates in columns " << m << " " << j << endl;
				incomplete=true;
			}
		}
	}

// Final Check and Results
	for (j=2; j<num_of_columns-1; j++) {
		if (val_array[1][j]==0) {
			cout << "Non-existent Factor found at " << array_of_factors[0][j] << " column " << j << "." << endl;
			grimms_counterexample_found=true;
		}
	}
	if (incomplete==true) {
		cout << "Processing not complete. Duplicates have been found after final step." << endl;
	}
	else {
		if (grimms_counterexample_found==false) {
			cout << "All factors are distinct for composites between " << beginning_value << " and " << ending_value << "." << endl;
		}
	}

}

// End_Code
