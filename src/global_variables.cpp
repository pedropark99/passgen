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


const std::vector<std::string> SHORT_CMD_ARGS = {
    "-l", "-p", "-u",
    "-o", "-s", "-n",
    "-v", "-h"
};

const std::vector<std::string> LONG_CMD_ARGS = {
    "--length",
    "--number-of-passwords",
    "--no-upper-case-letters",
    "--no-lower-case-letters",
    "--special-chars",
    "--numbers",
    "--version",
    "--help"
};


const std::vector<std::string> CMD_LINE_ARGUMENTS_DESCRIPTION = {
    "The length of the password to be generated (default to 10). Expect a integer as argument;",
    "The number of passwords to be generated (default to 1). Expect a integer as argument;",
    "Exclude upper case Basic-Latin letters from the character set;",
    "Exclude lower case Basic-Latin letters from the character set;",
    "Include special characters (e.g. &, #, $, etc.) in the character set;",
    "Include numbers (e.g. 0, 1, 2, etc.) in the character set;",
    "Print the current version of the passgen program;",
    "Print the help documentation;"
};






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