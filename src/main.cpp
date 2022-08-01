#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"

int getRandomNumber (int maxLimit) {
    int number = std::rand() % maxLimit;
    return number;
}

void startRandomSeed () {
    std::srand(time(NULL));
}

std::string generatePassword (int passwordLength) {
    int randomIndex;
    char password[passwordLength];
    int numberOfAnsiChars = sizeof(ANSI_CHARS) / sizeof(ANSI_CHARS[0]);
    startRandomSeed();
    for (int i = 0; i < passwordLength; i++) {
        randomIndex = getRandomNumber(numberOfAnsiChars);
        password[i] = ANSI_CHARS[randomIndex];
    }

    return std::string(password);
}



int main () {
    
    std::string password = generatePassword(15);
    std::cout << password << std::endl;

    return 1;
}
