#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "arguments_parser.hpp"
#include "password.hpp"



std::vector<char> buildCharSet ();


int main (int argc, char *argv[]) {
    parseCmdLineArguments(argc, argv);
    std::vector<char> completeCharSet = buildCharSet();
    for (int i = 0; i < completeCharSet.size(); i++) {
        std::cout << completeCharSet[i] << std::endl;
    }
    return 1;
}






std::vector<char> reserveCharVector (int numberOfElements) {
    std::vector<char> reservedVector;
    reservedVector.reserve(numberOfElements);
    return reservedVector;
}

int calculateNumberOfElements () {
    int numberOfChars = ANSI_CHARS.size();
    if (SPECIAL_CHARS_FLAG == true) {
        numberOfChars = numberOfChars + SPECIAL_CHARS.size();
    }
    return numberOfChars;
}

std::vector<char> fillCharSetVector (std::vector<char> charSetVector) {
    std::vector<char>::iterator vecIterator;
    vecIterator = charSetVector.begin();
    charSetVector.insert(vecIterator, ANSI_CHARS.begin(), ANSI_CHARS.end());
    // if (SPECIAL_CHARS_FLAG == true) {

    //     charSetVector.insert(vecIterator, ANSI_CHARS.end());
    // }
    return charSetVector;
}

std::vector<char> buildCharSet () {
    int numberOfChars = calculateNumberOfElements();
    std::vector<char> completeCharSet = reserveCharVector(numberOfChars);
    completeCharSet = fillCharSetVector(completeCharSet);
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