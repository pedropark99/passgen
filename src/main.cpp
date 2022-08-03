#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <getopt.h>
#include <unistd.h>

#include "constants.hpp"
#include "command-line-options.hpp"


int getRandomNumber (int maxLimit) {
    int number = std::rand() % maxLimit;
    return number;
}

void startRandomSeed () {
    std::srand(time(NULL));
}

char CMD_LINE_OPTIONS[] = {
    'l', 'b'
};

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


void checkCmdLineOptions (int argc, char *argv[]) {
    char *lflag;
    int bflag = 0;
    int option;
    while ((option = getopt(argc, argv, "l:b")) != 1) {
        switch (option) {
        case 'l':
            lflag = optarg;
            break;
        case 'b':
            bflag = 1;
            break;
        default:
            raiseCmdOptionException();
            abort();
            break;
        }
    }

    std::cout << lflag << std::endl;
}


void raiseCmdOptionException () {
    std::cout << "Invalid command line option! Available options are: ";
    for (int i = 0; i < sizeof(CMD_LINE_OPTIONS) / sizeof(CMD_LINE_OPTIONS[0]); i++) {
        std::cout << CMD_LINE_OPTIONS[i];
    };
    std::cout << std::endl;
}



int main (int argc, char **argv) {
    checkCmdLineOptions(argc, argv);

    return 1;
}
