// CPP_long_long_limits.cpp
// This program displays the limits for c++

#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int main() {
    long long int maxnum;
    std::cout << std::numeric_limits<long long int>::max() << endl;
    maxnum = 9223372036854775807;
    std::cout << sqrt(maxnum) << endl;
}

// End-Code
 
