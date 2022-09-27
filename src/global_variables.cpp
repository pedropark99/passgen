#include <set>
#include <string>
#include <vector>


#include "global_variables.hpp"

// Global variables used across the program

std::vector<std::string> USER_CMDLINE_ARGUMENTS;

const std::string PASSGEN_VERSION = "0.2.0";
const std::string PASSGEN_COMMAND_NAME = "passgen";





int PASSWORD_LENGTH = 10;
bool LOWER_CASE_LETTERS_FLAG = true;
bool UPPER_CASE_LETTERS_FLAG = true;
bool NUMBERS_FLAG = false;
bool SPECIAL_CHARS_FLAG = false;
int NUMBER_OF_PASSWORDS = 1;




const std::vector<CommandLineArgument> COMMAND_LINE_ARGUMENTS = {
    { "-l", "--length", "The length of the password to be generated (default to 10). Expect a integer as argument;" },
    { "-p", "--number-of-passwords", "The number of passwords to be generated (default to 1). Expect a integer as argument;" },
    { "-u", "--no-upper-case-letters", "Exclude upper case Basic-Latin letters from the character set;" },
    { "-o", "--no-lower-case-letters", "Exclude lower case Basic-Latin letters from the character set;" },
    { "-s", "--special-chars", "Include special characters (e.g. &, #, $, etc.) in the character set;" },
    { "-n", "--numbers", "Include numbers (e.g. 0, 1, 2, etc.) in the character set;" },
    { "-v", "--version", "Print the current version of the passgen program;" },
    { "-h", "--help", "Print the help documentation;" }
};






const std::vector<char> LOWER_CASE_LETTERS = {
    u8'a', u8'b', u8'c', u8'd', u8'e', u8'f',
    u8'g', u8'h', u8'i', u8'j', u8'k', u8'l',
    u8'm', u8'n', u8'o', u8'p', u8'q', u8'r',
    u8's', u8't', u8'u', u8'v', u8'x', u8'w',
    u8'y', u8'z'
};

const std::vector<char> UPPER_CASE_LETTERS = {
    u8'A', u8'B', u8'C', u8'D', u8'E', u8'F',
    u8'G', u8'H', u8'I', u8'J', u8'K', u8'L',
    u8'M', u8'N', u8'O', u8'P', u8'Q', u8'R',
    u8'S', u8'T', u8'U', u8'V', u8'X', u8'W',
    u8'Y', u8'Z'
};

const std::vector<char> NUMBERS = {
    u8'0', u8'1', u8'2', u8'3', u8'4',
    u8'5', u8'6', u8'7', u8'8', u8'9'
};


const std::vector<char> SPECIAL_CHARS = {
    u8'!', u8'@', u8'#', u8'$', u8'%',
    u8'^', u8'&', u8'*', u8'(', u8')',
    u8'-', u8'_', u8'=', u8'|', u8'\\',
    u8'/', u8'<', u8'>', u8';', u8':',
    u8'[', u8']', u8'{', u8'}', u8',',
    u8'?', u8'.', u8'+', u8'~', u8'`',
    u8'\'', u8'\u0022'
};