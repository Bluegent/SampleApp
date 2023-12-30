#include "args.h"
#include <iostream>

void printArgs(int argc, const char* argv[])
{
    std::cout << "Argument count: " << argc << '\n';
    for (size_t i = 0; i < argc; ++i)
    {
        std::cout << "Arg#" << i << ": " << argv[i] << '\n';
    }
}