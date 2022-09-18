#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <map>


#include "arguments_parser.hpp"
#include "global_variables.hpp"




void parseCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    std::string nextArgument;
    checkNumberOfArguments(argc);
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        currentArgument = transformArgumentToShortVersion(currentArgument);
        if (isCommandName(currentArgument)) {
            continue;
        }
        if (isVersionArgument(currentArgument)) {
            printProgramVersion();
            exit(0);
        }
        if (isHelpArgument(currentArgument)) {
            printProgramHelp();
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
    int numberOfCmdArguments = COMMAND_LINE_OPTIONS.size();
    int lengthValueArgument = 1;
    int commandNameArgument = 1;
    int numberOfValidArguments = numberOfCmdArguments + lengthValueArgument + commandNameArgument;
    if (argc > numberOfValidArguments) {
        throw std::invalid_argument("Too many arguments given to `passgen` command at the command line!");
    }
}

std::string transformArgumentToShortVersion (std::string argument) {
    if (argument == "passgen") {
        return argument;
    }
    std::string shortVersion;
    int stringSize = argument.size();
    bool isLongVersion = !(stringSize == 2);
    if (isLongVersion) {
        shortVersion = getShortNameFromLongName(argument);
        return shortVersion;
    } else {
        return argument;
    }
}


std::string getShortNameFromLongName (std::string argument) {
    for (CommandLineOption cmdOption : COMMAND_LINE_OPTIONS) {
        if (cmdOption.longName == argument) {
            return cmdOption.shortName;
        }
    }
    return argument;
}

bool searchInCmdOptions (std::string optionToSearch) {
    bool optionFound;
    for (CommandLineOption option : COMMAND_LINE_OPTIONS) {
        optionFound = optionToSearch == option.shortName | optionToSearch == option.longName;
        if (optionFound) {
            return true;
        }
    }
    return false;
}


void checkInvalidArgument (std::string option) {
    bool notFoundInCmdOptions;
    notFoundInCmdOptions = !searchInCmdOptions(option);
    if (notFoundInCmdOptions) {
        std::string errorMessage = "The option `` is invalid! Use `passgen -h` to see the available command-line options.";
        errorMessage.insert(12, option);
        errorMessage = std::string(errorMessage);
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

bool isHelpArgument (std::string argument) {
    return argument == "-h" | argument == "--help";
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



void printProgramHelp () {
    printProgramBasicInfo();
    printProgramOptions();
}

void printProgramBasicInfo () {
    const std::string usagePrefix = "Usage: ";
    const std::string versionPrefix = "Version: ";
    const int minPrintHorizontalSpace = 10;
    std::cout << std::endl << std::left 
        << std::setw(minPrintHorizontalSpace) << usagePrefix
        << std::setw(minPrintHorizontalSpace) << PASSGEN_COMMAND_NAME << std::endl
        << std::setw(minPrintHorizontalSpace) << versionPrefix
        << std::setw(minPrintHorizontalSpace) << PASSGEN_VERSION 
        << std::endl << std::endl << std::endl;
}


void printProgramOptions () {
    const int minPrintHorizontalSpace = 23;
    std::cout << "Options:" << std::endl << std::endl;
    for (int i = 0; i < COMMAND_LINE_OPTIONS.size(); i++) {
        std::cout << std::left << "    " 
            << COMMAND_LINE_OPTIONS[i].shortName
            << ", "
            << std::setw(minPrintHorizontalSpace)
            << COMMAND_LINE_OPTIONS[i].longName
            << " - "
            << COMMAND_LINE_OPTIONS[i].description
            << std::endl; 
    }
}