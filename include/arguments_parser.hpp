#pragma once
#include <string>
#include <set>


void parseCmdLineArguments (int argc, char *argv[]);
void checkNumberOfArguments (int argc);
void checkInvalidArgument (std::string argument);
void checkIfNextArgumentExists (int argc, int argumentIndex);


bool isCommandName (std::string argument);
bool isLengthArgument (std::string argument);
bool isSpecialCharsArgument (std::string argument);
bool isNumbersArgument (std::string argument);
bool isLowerCaseArgument (std::string argument);
bool isUpperCaseArgument (std::string argument);
bool isNumberOfPasswordsArgument (std::string argument);
bool isVersionArgument (std::string argument);
bool isHelpArgument (std::string argument);


int castValueToInteger (std::string value);
bool stringEndsWith (std::string stringToCheck, std::string endToCompare);

void printProgramVersion ();
void printProgramHelp ();
void printProgramBasicInfo ();
void printProgramOptions ();
