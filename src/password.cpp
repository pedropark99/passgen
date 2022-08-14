#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "arguments_parser.hpp"
#include "password.hpp"


int calculateNumberOfElements () {
    int numberOfChars = ANSI_CHARS.size();
    if (SPECIAL_CHARS_FLAG == true) {
        numberOfChars = numberOfChars + SPECIAL_CHARS.size();
    }
    return numberOfChars;
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
    copyElementsToVector(charSetVector, ANSI_CHARS, destinationIterator);

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