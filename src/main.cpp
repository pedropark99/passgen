#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "command-line-options.hpp"

// Global variables
int lflag = 10;
int sflag = 0;
char CMD_LINE_OPTIONS[] = {
    'l', 's'
};


bool isLengthArgument (std::string arg) {
    return arg == "-l" | arg == "--length";
}

int castLengthValue (std::string lengthValue) {
    std::istringstream ss(lengthValue);
    int castedValue;
    if (!(ss >> castedValue)) {
        std::cerr << "Invalid number: " << lengthValue << '\n';
    } else if (!ss.eof()) {
        std::cerr << "Trailing characters after number: " << lengthValue << '\n';
    }
    return castedValue;
}

bool isSpecialCharsArgument (std::string arg) {
    return arg == "-s" | arg == "--special-chars";
}


void checkCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    std::string nextArgument;
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        if (isLengthArgument(currentArgument)) {
            argumentIndex++;
            nextArgument = std::string(argv[argumentIndex]);
            lflag = castLengthValue(nextArgument);
            continue;
        }
        if (isSpecialCharsArgument(currentArgument)) {
            sflag = 1;
            continue;
        }
    }
}






int main (int argc, char *argv[]) {
    checkCmdLineArguments(argc, argv);
    std::cout << lflag << std::endl;
    std::cout << sflag << std::endl;
    return 1;
}








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