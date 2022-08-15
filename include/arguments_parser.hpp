#pragma once

#include <string>
#include <set>

extern std::set<std::string> CMD_LINE_ARGUMENTS;
extern int PASSWORD_LENGTH;
extern bool LOWER_CASE_LETTERS_FLAG;
extern bool UPPER_CASE_LETTERS_FLAG;
extern bool NUMBERS_FLAG;
extern bool SPECIAL_CHARS_FLAG;
extern int NUMBER_OF_PASSWORDS;


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


int castValueToInteger (std::string value);
bool stringEndsWith (std::string stringToCheck, std::string endToCompare);


