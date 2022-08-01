#include <iostream>
#include <string>

#include "command-line-options.hpp"

commandLineArgument COMMAND_LINE_ARGUMENTS[2] = {
    {"-l", "--length", "The length (how many characters) of the password;"},
    {"-s", "--special", "Do you want special characters? (e.g. %$#@&*!...). Accepted values are 1 (FALSE) and 0 (NO);"}
};


void printHelp () {
    std::string opShortName;
    std::string opLongName;
    std::string opDescription;

    std::cout << "Options for password command line:" << std::endl;
    for (int i = 0; i < 2; i++) {
        opShortName = COMMAND_LINE_ARGUMENTS[i].shortName;
        opLongName = COMMAND_LINE_ARGUMENTS[i].longName;
        opDescription = COMMAND_LINE_ARGUMENTS[i].description;
        formatOption(opShortName, opLongName, opDescription);
    };
}

void formatOption (std::string shortName, std::string longName, std::string description) {
    std::cout << "  ";
    std::cout << shortName << ", " << longName << " \t " << description << std::endl;
}

