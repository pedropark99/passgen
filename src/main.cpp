#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"

#include <getopt.h>
#include <unistd.h>

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



int main (int argc, char **argv) {
    int aflag = 0;
    int bflag = 0;
    int index;
    int option;

    opterr = 0;

    while ((option = getopt (argc, argv, "ab")) != -1)
        switch (option)
        {
        case 'a':
            aflag = 1;
            break;
        case 'b':
            bflag = 1;
            break;
        default:
            abort ();
        }

    printf("Variável a: %d, Variável b: %d", aflag, bflag);

    return 1;
}
