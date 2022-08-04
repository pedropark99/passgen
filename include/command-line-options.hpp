#pragma once

#include <string>


void printHelp();
void formatOption (std::string shortName, std::string longName, std::string description);


void parseCmdLineArguments (int argc, char *argv[]);
extern std::string CMD_LINE_OPTIONS[];
extern int PASSWORD_LENGTH;
extern int SPECIAL_CHARS_FLAG;




