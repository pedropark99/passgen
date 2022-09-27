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
    cacheUserCmdLineOptions(argc, argv);
    executeArgumentEvaluators();
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

void cacheUserCmdLineOptions (int argc, char *argv[]) {
    std::string currentArgument;
    USER_CMDLINE_OPTIONS.reserve(argc);
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        currentArgument = transformArgumentToShortVersion(currentArgument);
        USER_CMDLINE_OPTIONS.push_back(currentArgument);
    }
}

std::string transformArgumentToShortVersion (std::string argument) {
    if (argument == "passgen") {
        return argument;
    }
    if (isLongVersionOption(argument)) {
        std::string shortVersion;
        shortVersion = getShortNameFromLongName(argument);
        return shortVersion;
    } else {
        return argument;
    }
}

bool isLongVersionOption (std::string argument) {
    return argument.rfind("--", 0) == 0;
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







void evaluateLengthArgument () {
    std::vector<std::string>::iterator position;
    position = getArgumentPosition("-l");
    if (position != USER_CMDLINE_OPTIONS.end()) {
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
    if (position != USER_CMDLINE_OPTIONS.end()) {
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



std::vector<std::string>::iterator getArgumentPosition (std::string argument) {
	std::vector<std::string>::iterator position;
	position = USER_CMDLINE_OPTIONS.begin();
    for (std::string currentArgument : USER_CMDLINE_OPTIONS) {
		if (currentArgument == argument) {
			return position;
		}
		position++;
	}
	return position;
}

bool argumentWasProvidedByTheUser (std::string argument) {
    bool argumentWasFound = false;
    for (std::string currentArgument : USER_CMDLINE_OPTIONS) {
		if (currentArgument == argument) {
            argumentWasFound = true;
		}
	}
    return argumentWasFound;
}


std::vector<functionPointer> argumentsEvaluators = {
    &evaluateLengthArgument,
    &evaluateSpecialCharsArgument,
    &evaluateLowerCaseArgument,
    &evaluateUpperCaseArgument,
    &evaluateNumbersArgument,
    &evaluateNumberOfPasswordsArgument
};

void executeArgumentEvaluators () {
    for (functionPointer argumentEvaluator : argumentsEvaluators) {
        executeFunctionFromPointer(argumentEvaluator);
    }
}


void executeFunctionFromPointer (functionPointer fun) {
    fun();
}






std::string getNextArgument (std::vector<std::string>::iterator &position) {
    if (std::next(position) != USER_CMDLINE_OPTIONS.end()) {
        position++;
        return *position;
    } else {
        throw std::invalid_argument("After the arguments `-l`, `--length`, `-p`, `--number-of-passwords`, you need to provide a integer, but, none was given!");
    };
}




void reportInvalidArgument (std::string option) {
    bool notFoundInCmdOptions;
    notFoundInCmdOptions = !searchInCmdOptions(option);
    if (notFoundInCmdOptions) {
        std::string errorMessage = "The option `` is invalid! Use `passgen -h` to see the available command-line options.";
        errorMessage.insert(12, option);
        errorMessage = std::string(errorMessage);
        throw std::invalid_argument(errorMessage);
    }
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


void exitProgram () {
    exit(0);
}