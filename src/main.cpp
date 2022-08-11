#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "arguments_parser.hpp"
#include "password.hpp"



std::vector<char> buildCharSet ();
int calculateNumberOfElements ();




void fillCharSetVector (std::vector<char>& vectorToFill, int lastElementIndex, std::vector<char>& charSetToBeInserted) {
    int currentVectorIndex = lastElementIndex;
    int sizeIndex = 0;
    int charSetIndex = 0;
    for (currentVectorIndex; sizeIndex < charSetToBeInserted.size(); currentVectorIndex++) {
        vectorToFill[currentVectorIndex] = charSetToBeInserted[charSetIndex];
        charSetIndex++;
        sizeIndex++;
    }

}

int main (int argc, char *argv[]) {
    parseCmdLineArguments(argc, argv);
    int numberOfChars = calculateNumberOfElements();
    // std::cout << numberOfChars << std::endl;
    std::vector<char> charSetVector;
    charSetVector.reserve(numberOfChars);
    fillCharSetVector(charSetVector, 0, ANSI_CHARS);
    std::cout << charSetVector.size() << std::endl;
    for (int i = 0; i < charSetVector.size(); i++) {
        std::cout << charSetVector[i] << std::endl;
    }  

    // std::cout << numberOfChars << std::endl;
    // std::vector<char> charSetVector;
    // charSetVector.reserve(numberOfChars);
    // std::vector<char>::iterator vecIterator;
    // vecIterator = charSetVector.begin();
    // O insert tá gerando algum erro. Preciso investigar:
    // charSetVector.insert(vecIterator, ANSI_CHARS.begin(), ANSI_CHARS.end());
    // for (int i = 0; i < charSetVector.size(); i++) {
    //     std::cout << charSetVector[i] << std::endl;
    // }   
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



// std::vector<char> buildCharSet () {
//     int numberOfChars = calculateNumberOfElements();
//     std::vector<char> completeCharSet = reserveCharVector(numberOfChars);
//     completeCharSet = fillCharSetVector(completeCharSet);
//     return completeCharSet;
// }







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