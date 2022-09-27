#pragma once
#include <vector>
#include <string>


int calculateNumberOfElements ();
/* If all char set flags are false, the program
does not have a char set to build the password; */
void checkIfAllFlagsAreFalse ();

// Initiate the vector, and fill it with the choosen char set;
std::vector<char> buildCharSetVector (int numberOfElements);
void fillCharSetVector (std::vector<char>& charSetVector);
void copyElementsToVector (
    std::vector<char>& destinationVector,
    std::vector<char>::iterator& destionationIterator,
    const std::vector<char>& sourceVector
);



std::string generatePassword (int passwordLength, std::vector<char>& charSet);
void startRandomSeed ();
int getRandomNumber (int maxLimit);
std::vector<std::string> generateMultiplePasswords (
    int passwordLength,
    std::vector<char>& charSet,
    int numberOfPasswords
);