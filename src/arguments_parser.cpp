#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>


#include "arguments_parser.hpp"
#include "global_variables.hpp"



void parseCmdLineArguments (int argc, char *argv[]) {
    checkNumberOfArguments(argc);
    cacheCmdLineArguments(argc, argv);
    executeArgumentEvaluators();
}


void checkNumberOfArguments (int argc) {
    int numberOfCmdArguments = COMMAND_LINE_ARGUMENTS.size();
    int numberOfValidArguments = numberOfCmdArguments + 3;
    if (argc > numberOfValidArguments) {
        throw std::invalid_argument("Too many arguments given to `passgen` command at the command line!");
    }
}

void cacheCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    USER_CMDLINE_ARGUMENTS.reserve(argc);
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        currentArgument = transformArgumentToShortVersion(currentArgument);
        USER_CMDLINE_ARGUMENTS.push_back(currentArgument);
    }
}


std::vector<functionPointer> argumentsEvaluators = {
    &evaluateLengthArgument,
    &evaluateSpecialCharsArgument,
    &evaluateLowerCaseArgument,
    &evaluateUpperCaseArgument,
    &evaluateNumbersArgument,
    &evaluateNumberOfPasswordsArgument,
    &evaluateVersionArgument,
    &evaluateHelpArgument
};

void executeArgumentEvaluators () {
    for (functionPointer argumentEvaluator : argumentsEvaluators) {
        executeFunctionFromPointer(argumentEvaluator);
    }
}

void executeFunctionFromPointer (functionPointer fun) {
    fun();
}

std::string transformArgumentToShortVersion (std::string argument) {
    if (argument == "passgen") {
        return argument;
    }
    if (isLongVersionArgument(argument)) {
        std::string shortVersion;
        shortVersion = getShortNameFromLongName(argument);
        return shortVersion;
    }
    return argument;
}

bool isLongVersionArgument (std::string argument) {
    return argument.rfind("--", 0) == 0;
}

std::string getShortNameFromLongName (std::string argument) {
    for (CommandLineArgument cmdArgument : COMMAND_LINE_ARGUMENTS) {
        if (cmdArgument.longName == argument) {
            return cmdArgument.shortName;
        }
    }
    return argument;
}








void evaluateLengthArgument () {
    std::vector<std::string>::iterator position;
    position = getArgumentPosition("-l");
    if (position != USER_CMDLINE_ARGUMENTS.end()) {
        std::string nextArgument;
        nextArgument = getNextArgument(position);
        PASSWORD_LENGTH = castValueToInteger(nextArgument);
    }
}

void evaluateSpecialCharsArgument () {
    if (argumentWasProvidedByTheUser("-s")) {
        SPECIAL_CHARS_FLAG = true;
    }
}

void evaluateLowerCaseArgument () {
    if (argumentWasProvidedByTheUser("-o")) {
        LOWER_CASE_LETTERS_FLAG = false;
    } 
}

void evaluateUpperCaseArgument () {
    if (argumentWasProvidedByTheUser("-u")) {
        UPPER_CASE_LETTERS_FLAG = false;
    } 
}

void evaluateNumberOfPasswordsArgument () {
    std::vector<std::string>::iterator position;
    position = getArgumentPosition("-p");
    if (position != USER_CMDLINE_ARGUMENTS.end()) {
        std::string nextArgument;
        nextArgument = getNextArgument(position);
        NUMBER_OF_PASSWORDS = castValueToInteger(nextArgument);
    }
}

void evaluateNumbersArgument () {
    if (argumentWasProvidedByTheUser("-n")) {
        NUMBERS_FLAG = true;
    }
}

void evaluateVersionArgument () {
    if (argumentWasProvidedByTheUser("-v")) {
        printProgramVersion();
    }
}

void evaluateHelpArgument () {
    if (argumentWasProvidedByTheUser("-h")) {
        printProgramHelp();
    }
}






std::vector<std::string>::iterator getArgumentPosition (std::string argument) {
	std::vector<std::string>::iterator position;
	position = USER_CMDLINE_ARGUMENTS.begin();
    for (std::string currentArgument : USER_CMDLINE_ARGUMENTS) {
		if (currentArgument == argument) {
			return position;
		}
		position++;
	}
	return position;
}

bool argumentWasProvidedByTheUser (std::string argument) {
    bool argumentWasFound = false;
    for (std::string currentArgument : USER_CMDLINE_ARGUMENTS) {
		if (currentArgument == argument) {
            argumentWasFound = true;
		}
	}
    return argumentWasFound;
}

std::string getNextArgument (std::vector<std::string>::iterator &position) {
    if (std::next(position) != USER_CMDLINE_ARGUMENTS.end()) {
        position++;
        return *position;
    } else {
        throw std::invalid_argument("After the arguments `-l`, `--length`, `-p`, `--number-of-passwords`, you need to provide a integer, but, none was given!");
    };
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







void reportInvalidArgument (std::string argument) {
    bool notFoundInValidArguments;
    notFoundInValidArguments = !searchInCmdArguments(argument);
    if (notFoundInValidArguments) {
        std::string errorMessage = "The argument `` is invalid! Use `passgen -h` to see the available command-line arguments.";
        errorMessage.insert(14, argument);
        errorMessage = std::string(errorMessage);
        throw std::invalid_argument(errorMessage);
    }
}

bool searchInCmdArguments (std::string argumentToSearch) {
    bool argumentFound;
    for (CommandLineArgument argument : COMMAND_LINE_ARGUMENTS) {
        argumentFound = argument.shortName == argumentToSearch;
        if (argumentFound) {
            return true;
        }
    }
    return false;
}






bool stringEndsWith (std::string stringToCheck, std::string endToCompare) {
    int result = stringToCheck.compare(
        stringToCheck.length() - endToCompare.length(),
        stringToCheck.length(),
        endToCompare
    );
    
    return result == 0;
}










void printProgramVersion () {
    std::cout << "Version: " << PASSGEN_VERSION << std::endl;
    exitProgram();
}

void printProgramHelp () {
    printProgramBasicInfo();
    printProgramOptions();
    exitProgram();
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
    for (int i = 0; i < COMMAND_LINE_ARGUMENTS.size(); i++) {
        std::cout << std::left << "    " 
            << COMMAND_LINE_ARGUMENTS[i].shortName
            << ", "
            << std::setw(minPrintHorizontalSpace)
            << COMMAND_LINE_ARGUMENTS[i].longName
            << " - "
            << COMMAND_LINE_ARGUMENTS[i].description
            << std::endl; 
    }
}

void exitProgram () {
    exit(0);
}