#include <iostream>
#include <string>

#include "command-line-options.hpp"

#define print(x): std::cout << x << std::endl;


void printHelp() {
    for (int i = 0; i < 2; i++) {
        std::cout << "help" << std::endl;
    };
}

