#include <iostream>
#include <string>
#include <vector>

#include "catalogue/catalogue.h"

int main(int argc, char* argv[])
{
    parse_args<int>({"./catalogue", "get", "1"});

    print_hello();

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
