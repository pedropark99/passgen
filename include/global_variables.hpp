#pragma once
#include <set>
#include <string>
#include <vector>


extern const std::string PASSGEN_VERSION;
extern const std::string PASSGEN_COMMAND_NAME;


extern int PASSWORD_LENGTH;
extern bool LOWER_CASE_LETTERS_FLAG;
extern bool UPPER_CASE_LETTERS_FLAG;
extern bool NUMBERS_FLAG;
extern bool SPECIAL_CHARS_FLAG;
extern int NUMBER_OF_PASSWORDS;

extern const std::set<std::string> CMD_LINE_ARGUMENTS;
extern const std::vector<std::string> SHORT_CMD_ARGS;
extern const std::vector<std::string> LONG_CMD_ARGS;
extern const std::vector<std::string> CMD_LINE_ARGUMENTS_DESCRIPTION;

struct CommandLineOption {
    std::string shortName;
    std::string longName;
    std::string description;
};

extern std::vector<CommandLineOption> CMDS;

extern const std::vector<char> LOWER_CASE_LETTERS;
extern const std::vector<char> UPPER_CASE_LETTERS;
extern const std::vector<char> NUMBERS;
extern const std::vector<char> SPECIAL_CHARS;