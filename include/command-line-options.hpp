#pragma once

#include <string>


void printHelp();
void formatOption (std::string shortName, std::string longName, std::string description);

struct commandLineArgument {
    std::string shortName;
    std::string longName;
    std::string description;
};



