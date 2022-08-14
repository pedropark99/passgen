#pragma once

#include <string>
#include <set>

extern std::set<std::string> CMD_LINE_ARGUMENTS;
extern int PASSWORD_LENGTH;
extern bool SPECIAL_CHARS_FLAG;
void parseCmdLineArguments (int argc, char *argv[]);
void checkNumberOfArguments (int argc);
void checkInvalidArgument (std::string argument);
void checkIfNextArgumentExists (int argc, int argumentIndex);
bool isCommandName (std::string argument);
bool isLengthArgument (std::string arg);
bool isSpecialCharsArgument (std::string arg);
int castLengthValue (std::string lengthValue);
bool stringEndsWith (std::string stringToCheck, std::string endToCompare);


