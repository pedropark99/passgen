#include <iostream>
#include <vector>


#include "arguments_parser.hpp"
#include "password.hpp"




int main (int argc, char *argv[]) {
    parseCmdLineArguments(argc, argv);
    int numberOfChars = calculateNumberOfElements();
    std::vector<char> charSetVector = buildCharSetVector(numberOfChars);
    std::string password = generatePassword(PASSWORD_LENGTH, charSetVector);
    std::cout << password << std::endl;
    return 1;
}