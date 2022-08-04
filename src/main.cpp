#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "arguments_parser.hpp"
#include "password.hpp"






int main (int argc, char *argv[]) {
    parseCmdLineArguments(argc, argv);
    // std::cout << PASSWORD_LENGTH << std::endl;
    // std::cout << SPECIAL_CHARS_FLAG << std::endl;
    return 1;
}






std::vector<char> reserveCharVector (int numberOfElements) {
    std::vector<char> reservedVector;
    reservedVector.reserve(numberOfElements);
    return reservedVector;
}

int calculateNumberOfElements () {
    int numberOfChars = sizeof(ANSI_CHARS);
    if (SPECIAL_CHARS_FLAG == true) {
        numberOfChars = numberOfChars + (sizeof(SPECIAL_CHARS) / sizeof(SPECIAL_CHARS[0]));
    }
    return numberOfChars;
}

std::vector<char> buildCharSet () {
    int numberOfChars = calculateNumberOfElements();
    std::vector<char> completeCharSet = reserveCharVector(numberOfChars);
    return completeCharSet;
}

std::string generatePassword (int passwordLength, std::vector<char> charSet) {
    int randomIndex;
    char password[passwordLength];
    int numberOfChars = charSet.size();
    startRandomSeed();
    for (int i = 0; i < passwordLength; i++) {
        randomIndex = getRandomNumber(numberOfChars);
        password[i] = charSet[randomIndex];
    }

    return std::string(password);
}

void startRandomSeed () {
    std::srand(time(NULL));
}

int getRandomNumber (int maxLimit) {
    int number = std::rand() % maxLimit;
    return number;
}