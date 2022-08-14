#include <iostream>
#include <string>
#include <sstream>
#include <set>

#include "arguments_parser.hpp"

// Global variables
int PASSWORD_LENGTH = 10;
bool SPECIAL_CHARS_FLAG = false;
std::set<std::string>  CMD_LINE_ARGUMENTS = {
    "-l", "--length",
    "-s", "--special-chars"
};





void parseCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    std::string nextArgument;
    checkNumberOfArguments(argc);
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        if (isCommandName(currentArgument)) {
            continue;
        }
        if (isLengthArgument(currentArgument)) {
            checkIfNextArgumentExists(argc, argumentIndex);
            argumentIndex++;
            nextArgument = std::string(argv[argumentIndex]);
            PASSWORD_LENGTH = castLengthValue(nextArgument);
            continue;
        }
        if (isSpecialCharsArgument(currentArgument)) {
            SPECIAL_CHARS_FLAG = true;
            continue;
        }

        checkInvalidArgument(currentArgument);
    }
}

void checkNumberOfArguments (int argc) {
    int numberOfCmdArguments = CMD_LINE_ARGUMENTS.size() / 2;
    int lengthValueArgument = 1;
    int commandNameArgument = 1;
    int numberOfValidArguments = numberOfCmdArguments + lengthValueArgument + commandNameArgument;
    if (argc > numberOfValidArguments) {
        throw std::invalid_argument("Too many arguments given to `password` command at the command line!");
    }
}

void checkInvalidArgument (std::string argument) {
    if (CMD_LINE_ARGUMENTS.find(argument) == CMD_LINE_ARGUMENTS.end()) {
        std::string errorMessage;
        errorMessage = std::string("The argument  is invalid!").insert(13, argument);
        throw std::invalid_argument(errorMessage);
    }
}


void checkIfNextArgumentExists (int argc, int argumentIndex) {
    int zeroBasedIndexOffSet = 1;
    int nextIndex = argumentIndex + zeroBasedIndexOffSet + 1;
    if (nextIndex > argc) {
        throw std::invalid_argument("After the argument `-l` or `--length`, you need to provide a integer (that represents the password length), but, none was given!");
    }
}



bool isCommandName (std::string argument) {
    return argument == "passgen";
}

bool isLengthArgument (std::string argument) {
    return argument == "-l" | argument == "--length";
}

bool isSpecialCharsArgument (std::string argument) {
    return argument == "-s" | argument == "--special-chars";
}



int castLengthValue (std::string lengthValue) {
    std::istringstream ss(lengthValue);
    int castedValue;
    if (!(ss >> castedValue)) {
        std::cerr << "Error: Invalid number passed to `-l` or `--length` argument: " << lengthValue << '\n';
    } else if (!ss.eof()) {
        std::cerr << "Error: Trailing characters after number passed to `-l` or `--length` argument: " << lengthValue << '\n';
    }
    return castedValue;
}