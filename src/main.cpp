#include <iostream>
#include <vector>
#include <string>


#include "arguments_parser.hpp"
#include "constants.hpp"
#include "password.hpp"




int main (int argc, char *argv[]) {
    parseCmdLineArguments(argc, argv);
    int numberOfChars = calculateNumberOfElements();
    std::vector<char> charSetVector = buildCharSetVector(numberOfChars);
    
    if (NUMBER_OF_PASSWORDS > 1) {
        std::vector<std::string> passwords;
        startRandomSeed();
        passwords = generateMultiplePasswords(PASSWORD_LENGTH, charSetVector, NUMBER_OF_PASSWORDS);
        for (std::string password: passwords) {
            std::cout << password << std::endl;
        }
    } else {
        std::string password;
        startRandomSeed();
        password = generatePassword(PASSWORD_LENGTH, charSetVector);
        std::cout << password << std::endl;
    }

    return 1;
}