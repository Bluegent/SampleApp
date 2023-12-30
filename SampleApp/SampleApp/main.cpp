#include <iostream>


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


void printArgs(int argc, const char* argv[])
{
    std::cout << "Argument count: " << argc << '\n';
    for (size_t i = 0; i < argc; ++i)
    {
        std::cout << "Arg#" << i << ": " << argv[i] << '\n';
    }
}

//let's print the command line arguments
int main(int argc, const char * argv[])
{
    printArgs(argc, argv);
}