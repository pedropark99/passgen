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
    "-s", "--special-chars",
    "-n", "--numbers",
    "-u", "--no-upper-case-letters"
    "-o", "--no-lower-case-letters",
    "-p", "--number-of-passwords",
    "-v", "--version",
    "-h", "--help"
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