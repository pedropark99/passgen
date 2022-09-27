#pragma once
#include <string>
#include <set>


void parseCmdLineArguments (int argc, char *argv[]);
void checkNumberOfArguments (int argc);
void cacheCmdLineArguments (int argc, char *argv[]);
std::string transformArgumentToShortVersion (std::string argument);
std::string getShortNameFromLongName (std::string argument);
bool isLongVersionArgument (std::string argument);
std::string getNextArgument (std::vector<std::string>::iterator &position);
bool argumentWasProvidedByTheUser (std::string argument);
std::vector<std::string>::iterator getArgumentPosition (std::string argument);
typedef void (*functionPointer)(void);
void executeFunctionFromPointer (functionPointer fun);
void reportInvalidArgument (std::string argument);
void checkIfNextArgumentExists (int argc, int argumentIndex);




void evaluateLengthArgument ();
void evaluateSpecialCharsArgument ();
void evaluateLowerCaseArgument ();
void evaluateUpperCaseArgument ();
void evaluateNumberOfPasswordsArgument ();
void evaluateNumbersArgument ();
void evaluateVersionArgument ();
void evaluateHelpArgument ();


void executeArgumentEvaluators ();





bool isCommandName (std::string argument);
bool isLengthArgument (std::string argument);
bool isSpecialCharsArgument (std::string argument);
bool isNumbersArgument (std::string argument);
bool isLowerCaseArgument (std::string argument);
bool isUpperCaseArgument (std::string argument);
bool isNumberOfPasswordsArgument (std::string argument);
bool isVersionArgument (std::string argument);
bool isHelpArgument (std::string argument);

bool searchInCmdArguments (std::string argumentToSearch);
int castValueToInteger (std::string value);
bool stringEndsWith (std::string stringToCheck, std::string endToCompare);


void printProgramVersion ();
void printProgramHelp ();
void printProgramBasicInfo ();
void printProgramOptions ();
void exitProgram ();
