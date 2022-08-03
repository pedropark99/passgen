#pragma once

#include <string>


void printHelp();
void formatOption (std::string shortName, std::string longName, std::string description);

void checkCmdLineOptions (int argc, char *argv[]);
void raiseCmdOptionException ();

struct commandLineArgument {
    std::string shortName;
    std::string longName;
    std::string description;
};



