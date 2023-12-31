#include <iostream>
#include "args.h"
#include "math_func.h"
#include "valid_link.h"



//let's print the command line arguments
int main(int argc, const char * argv[])
{
    //printArgs(argc, argv);
    math_func_main();
    valid_link_main();
}