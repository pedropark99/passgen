#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"

int getRandomNumber(int maxLimit) {
    int number = std::rand() % maxLimit;
    return number;
}

void startRandomSeed () {
    std::srand(time(NULL));
}



int main () {

    int kpasswordLength = 5;
    int knumberOfAnsiChars = sizeof(ANSI_CHARS) / sizeof(ANSI_CHARS[0]);
    
    int randomIndex;
    char password[kpasswordLength];
    startRandomSeed();
    for (int i = 0; i < kpasswordLength; i++) {
        randomIndex = getRandomNumber(knumberOfAnsiChars);
        password[i] = ANSI_CHARS[randomIndex];
    }

    std::cout << password << std::endl;

    return 1;
}
