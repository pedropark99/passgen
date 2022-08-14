#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "arguments_parser.hpp"
#include "password.hpp"


int calculateNumberOfElements () {
    checkIfAllFlagsAreFalse();
    int numberOfChars = 0;
    if (LOWER_CASE_LETTERS_FLAG == true) {
        numberOfChars = numberOfChars + LOWER_CASE_LETTERS.size();
    }
    if (UPPER_CASE_LETTERS_FLAG == true) {
        numberOfChars = numberOfChars + UPPER_CASE_LETTERS.size();
    }
    if (NUMBERS_FLAG == true) {
        numberOfChars = numberOfChars + NUMBERS.size();
    }
    if (SPECIAL_CHARS_FLAG == true) {
        numberOfChars = numberOfChars + SPECIAL_CHARS.size();
    }
    return numberOfChars;
}

void checkIfAllFlagsAreFalse () {
    bool allFlagsAreFalse;
    allFlagsAreFalse = LOWER_CASE_LETTERS_FLAG == false &
        UPPER_CASE_LETTERS_FLAG == false &
        NUMBERS_FLAG == false &
        SPECIAL_CHARS_FLAG == false;

    if (allFlagsAreFalse) {
        std::cerr << "All character set flags are set to false! As a result, the program does not have a character set to generate your password!" << std::endl;
        throw;
    }
}

std::vector<char> buildCharSetVector (int numberOfElements) {
    std::vector<char> charSetVector;
    charSetVector.reserve(numberOfElements);
    fillCharSetVector(charSetVector);
    return charSetVector;
}

void fillCharSetVector (std::vector<char>& charSetVector) {
    std::vector<char>::iterator destinationIterator;
    destinationIterator = charSetVector.begin();

    if (LOWER_CASE_LETTERS_FLAG == true) {
        copyElementsToVector(charSetVector, LOWER_CASE_LETTERS, destinationIterator);
    }
    if (UPPER_CASE_LETTERS_FLAG == true) {
        copyElementsToVector(charSetVector, UPPER_CASE_LETTERS, destinationIterator);
    }
    if (NUMBERS_FLAG == true) {
        copyElementsToVector(charSetVector, NUMBERS, destinationIterator);
    }
    if (SPECIAL_CHARS_FLAG == true) {
        copyElementsToVector(charSetVector, SPECIAL_CHARS, destinationIterator);
    }

}

void copyElementsToVector (std::vector<char>& destinationVector,
                           std::vector<char>& sourceVector,
                           std::vector<char>::iterator& destionationIterator) {

    destinationVector.insert(
        destionationIterator, sourceVector.begin(), sourceVector.end()
    );
    destionationIterator = std::next(destionationIterator, sourceVector.size());
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