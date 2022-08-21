#include <set>
#include <string>
#include <vector>


#include "global_variables.hpp"

// Global variables

const std::string PASSGEN_VERSION = "0.1.0";
const std::string PASSGEN_COMMAND_NAME = "passgen";



int PASSWORD_LENGTH = 10;
bool LOWER_CASE_LETTERS_FLAG = true;
bool UPPER_CASE_LETTERS_FLAG = true;
bool NUMBERS_FLAG = false;
bool SPECIAL_CHARS_FLAG = false;
int NUMBER_OF_PASSWORDS = 1;

const std::set<std::string>  CMD_LINE_ARGUMENTS = {
    "-l", "--length",
    "-p", "--number-of-passwords",
    "-u", "--no-upper-case-letters",
    "-o", "--no-lower-case-letters",
    "-s", "--special-chars",
    "-n", "--numbers",
    "-v", "--version",
    "-h", "--help"
};







std::vector<CommandLineOption> COMMAND_LINE_OPTIONS = {
    { "-l", "--length", "The length of the password to be generated (default to 10). Expect a integer as argument;" },
    { "-p", "--number-of-passwords", "The number of passwords to be generated (default to 1). Expect a integer as argument;" },
    { "-u", "--no-upper-case-letters", "Exclude upper case Basic-Latin letters from the character set;" },
    { "-o", "--no-lower-case-letters", "Exclude lower case Basic-Latin letters from the character set;" },
    { "-s", "--special-chars", "Include special characters (e.g. &, #, $, etc.) in the character set;" },
    { "-n", "--numbers", "Include numbers (e.g. 0, 1, 2, etc.) in the character set;" },
    { "-v", "--version", "Print the current version of the passgen program;" },
    { "-h", "--help", "Print the help documentation;" }
};

std::vector<std::string> SHORT_CMD_ARGS;
std::vector<std::string> LONG_CMD_ARGS;

void fillCmdVectors () {
    for (CommandLineOption option : COMMAND_LINE_OPTIONS) {
        SHORT_CMD_ARGS.push_back(option.shortName);
        LONG_CMD_ARGS.push_back(option.longName);
    }
};

fillCmdVectors();




const std::vector<char> LOWER_CASE_LETTERS = {
    'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'x', 'w',
    'y', 'z'
};

const std::vector<char> UPPER_CASE_LETTERS = {
    'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'X', 'W',
    'Y', 'Z',
};

const std::vector<char> NUMBERS = {
    '0', '1', '2', '3', '4', '5',
    '6', '7', '8', '9'
};


const std::vector<char> SPECIAL_CHARS = {
    '!', '@', '#', '$', '%',
    '^', '&', '*', '(', ')',
    '-', '_', '=', '|', '\\',
    '/', '<', '>', ';', ':',
    '[', ']', '{', '}', ',',
    '?', '.', '+'
};