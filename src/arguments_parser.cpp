#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "arguments_parser.hpp"
#include "constants.hpp"



void parseCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    std::string nextArgument;
    checkNumberOfArguments(argc);
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        if (isCommandName(currentArgument)) {
            continue;
        }
        if (isVersionArgument(currentArgument)) {
            printProgramVersion();
            exit(0);
        }
        if (isLengthArgument(currentArgument)) {
            checkIfNextArgumentExists(argc, argumentIndex);
            argumentIndex++;
            nextArgument = std::string(argv[argumentIndex]);
            PASSWORD_LENGTH = castValueToInteger(nextArgument);
            continue;
        }
        if (isSpecialCharsArgument(currentArgument)) {
            SPECIAL_CHARS_FLAG = true;
            continue;
        }
        if (isNumbersArgument(currentArgument)) {
            NUMBERS_FLAG = true;
            continue;
        }
        if (isLowerCaseArgument(currentArgument)) {
            LOWER_CASE_LETTERS_FLAG = false;
            continue;
        }
        if (isUpperCaseArgument(currentArgument)) {
            UPPER_CASE_LETTERS_FLAG = false;
            continue;
        }
        if (isNumberOfPasswordsArgument(currentArgument)) {
            checkIfNextArgumentExists(argc, argumentIndex);
            argumentIndex++;
            nextArgument = std::string(argv[argumentIndex]);
            NUMBER_OF_PASSWORDS = castValueToInteger(nextArgument);
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
        throw std::invalid_argument("Too many arguments given to `passgen` command at the command line!");
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
    std::string commandName = "passgen";
    if (argument.length() < commandName.length()) {
        return false;
    }
    return argument == commandName | stringEndsWith(argument, commandName);
}

bool isLengthArgument (std::string argument) {
    return argument == "-l" | argument == "--length";
}

bool isSpecialCharsArgument (std::string argument) {
    return argument == "-s" | argument == "--special-chars";
}

bool isNumbersArgument (std::string argument) {
    return argument == "-n" | argument == "--numbers";
}

bool isLowerCaseArgument (std::string argument) {
    return argument == "-o" | argument == "--no-lower-case-letters";
}

bool isUpperCaseArgument (std::string argument) {
    return argument == "-u" | argument == "--no-upper-case-letters";
}

bool isNumberOfPasswordsArgument (std::string argument) {
    return argument == "-p" | argument == "--number-of-passwords";
}

bool isVersionArgument (std::string argument) {
    return argument == "-v" | argument == "--version";
}


bool stringEndsWith (std::string stringToCheck, std::string endToCompare) {
    int result = stringToCheck.compare(
        stringToCheck.length() - endToCompare.length(),
        stringToCheck.length(),
        endToCompare
    );
    
    return result == 0;
}



int castValueToInteger (std::string value) {
    std::istringstream ss(value);
    int castedValue;
    if (!(ss >> castedValue)) {
        std::string errorMessage = "Invalid number argument: ";
        errorMessage.insert(errorMessage.length(), value);
        throw std::invalid_argument(errorMessage);
    }
    if (!ss.eof()) {
        std::string errorMessage = "Trailing characters after number argument: ";
        errorMessage.insert(errorMessage.length(), value);
        throw std::invalid_argument(errorMessage);
    }
    if (castedValue < 0) {
        std::string errorMessage = "Negative number argument: ";
        errorMessage.insert(errorMessage.length(), value);
        throw std::invalid_argument(errorMessage);
    }
    return castedValue;
}




void printProgramVersion () {
    std::cout << "Version: " << PASSGEN_VERSION << std::endl;
}