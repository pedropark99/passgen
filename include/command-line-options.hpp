#ifndef COMMAND_LINE_H_INCLUDED
#define COMMAND_LINE_H_INCLUDED

#include <string>


void printHelp();

namespace password {

    struct commandLineArgument {
        std::string optionName;
        std::string description;
    };

    commandLineArgument COMMAND_LINE_ARGUMENTS[2] = {
        {"l", "The length (how many characters) of the password;"},
        {"c", "Do you want special characters? (e.g. %$#@&*!...). Accepted values are 1 (FALSE) and 0 (NO);"}
    };

};




#endif