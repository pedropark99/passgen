#pragma once
#include <set>
#include <string>
#include <vector>


/* Used to store (or cache) all of the command line arguments
given by the user; */
extern std::vector<std::string> USER_CMDLINE_ARGUMENTS;

/* Basic infos about the `passgen` program; */
extern const std::string PASSGEN_VERSION;
extern const std::string PASSGEN_COMMAND_NAME;


/* Variables that describe the password to be generated; */
extern int PASSWORD_LENGTH;
extern bool LOWER_CASE_LETTERS_FLAG;
extern bool UPPER_CASE_LETTERS_FLAG;
extern bool NUMBERS_FLAG;
extern bool SPECIAL_CHARS_FLAG;
extern int NUMBER_OF_PASSWORDS;


struct CommandLineArgument {
    std::string shortName;
    std::string longName;
    std::string description;
};
/* Object that stores all of the available (or supported) command line arguments; */
extern const std::vector<CommandLineArgument> COMMAND_LINE_ARGUMENTS;


/* Objects that stores all of the supported characters set; */
extern const std::vector<char> LOWER_CASE_LETTERS;
extern const std::vector<char> UPPER_CASE_LETTERS;
extern const std::vector<char> NUMBERS;
extern const std::vector<char> SPECIAL_CHARS;