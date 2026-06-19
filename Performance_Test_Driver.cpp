// Performance_Test_Driver.cpp
// Created by Alan Verdegraal July 14, 2022

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
int main(int argc, char *argv[])
{

std::stringstream stream;    
stream << "\"C:\\Users\\averdegraal\\Desktop\\Mathematics\\C-Programs\\Performance_Testing\\Perf_Test_Staircase_Search_for_1_long_long.exe\""
       << " " // don't forget a space between the path and the arguments
       << "240007";
system(stream.str().c_str());

return 0;
}

// End-Code
