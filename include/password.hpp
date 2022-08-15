#pragma once

#include <vector>
#include <string>


std::vector<char> buildCharSet ();
int calculateNumberOfElements ();
void checkIfAllFlagsAreFalse ();
std::vector<char> buildCharSetVector (int numberOfElements);
void fillCharSetVector (std::vector<char>& charSetVector);
void copyElementsToVector (
    std::vector<char>& destinationVector,
    std::vector<char>& sourceVector,
    std::vector<char>::iterator& destionationIterator
);

std::string generatePassword (int passwordLength, std::vector<char>& charSet);
void startRandomSeed ();
int getRandomNumber (int maxLimit);
std::vector<std::string> generateMultiplePasswords (
    int passwordLength,
    std::vector<char>& charSet,
    int numberOfPasswords
);