#include "math_func.h"
#include <iostream>

//write a function that returns the absolute of an integer
int32_t abs_(int32_t num)
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


void math_func_main()
{
    std::cout << "Math func\n";
    int a = 10;
    int b = -10;
    std::cout << "a = " << a << " , b = " << b << '\n';
    std::cout << "max = " << max(a, b) << '\n';
    std::cout << "min = " << min(a, b) << '\n';
    std::cout << "abs(b) = " << abs_(b) << '\n';
}