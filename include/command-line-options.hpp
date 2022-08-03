#pragma once

#include <string>


void printHelp();
void formatOption (std::string shortName, std::string longName, std::string description);

void check_cmd_line_options (int argc, char *argv[]);

struct commandLineArgument {
    std::string shortName;
    std::string longName;
    std::string description;
};



