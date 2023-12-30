#include <iostream>
#include "args.h"

//write a function that returns the absolute of an integer
int32_t abs(int32_t num)
{
    return num > 0 ? num : -1 * num;
}


//write a function that returns the max of two integers
int32_t max(int32_t a, int32_t b)
{
    return a > b ? a : b;
}

//write a function that returns the min of two integers
int32_t min(int32_t a, int32_t b)
{
    return a < b ? a : b;
}


//let's print the command line arguments
int main(int argc, const char * argv[])
{
    printArgs(argc, argv);
}