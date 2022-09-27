#pragma once
#include <string>
#include <vector>


/* Functions responsible for evaluating the command line arguments given by the user */



// Entry point for the command line arguments parser;
void parseCmdLineArguments (int argc, char *argv[]);

// Check if user gave too many arguments at the command line;
void checkNumberOfArguments (int argc);

/* Every argument provided by the user (i.e. `argv`) is stored (or cached)
inside `USER_CMDLINE_ARGUMENTS` variable, to be globally available
to every function in the program that might need them; */
void cacheCmdLineArguments (int argc, char *argv[]);


std::string transformArgumentToShortVersion (std::string argument);
std::string getShortNameFromLongName (std::string argument);
bool isLongVersionArgument (std::string argument);

/* Considering a position `x` in `argv`, get the 
next argument (i.e. the argument in position `x + 1`); */
std::string getNextArgument (std::vector<std::string>::iterator &position);

// Check if user provided the argument `x` or not;
bool argumentWasProvidedByTheUser (std::string argument);

// Get the position of argument `x` in `argv` (is in position 3? 1? 12? etc...);
std::vector<std::string>::iterator getArgumentPosition (std::string argument);





/* Arguments evaluators functions ==================
These are the main functions that decide which
action to take, or, which global variable
to set, based on the command line arguments
provided by the user. All of them, consult
the `USER_CMDLINE_ARGUMENTS` variable to
check which arguments the user provided;
*/
void evaluateLengthArgument ();
void evaluateSpecialCharsArgument ();
void evaluateLowerCaseArgument ();
void evaluateUpperCaseArgument ();
void evaluateNumberOfPasswordsArgument ();
void evaluateNumbersArgument ();
void evaluateVersionArgument ();
void evaluateHelpArgument ();

// Function responsible for executing all of the "argument evaluators functions"
void executeArgumentEvaluators ();

/* Functions used by `executeArgumentEvaluators()`
to execute the "argument evaluators functions"; */
typedef void (*functionPointer)(void);
void executeFunctionFromPointer (functionPointer fun);
void reportInvalidArgument (std::string argument);

/* See if `argument` exists in the avaiable (or supported)
command line arguments in the `passgen` program*/
bool searchInCmdArguments (std::string argumentToSearch);
// Some utils functions;
int castValueToInteger (std::string value);
bool stringEndsWith (std::string stringToCheck, std::string endToCompare);


/* Functions used to print basic info about the program
to the screen of the user, like the version of the
program, or, the help documentation; */
void printProgramVersion ();
void printProgramHelp ();
void printProgramBasicInfo ();
void printProgramOptions ();
void exitProgram ();
