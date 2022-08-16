#pragma once
#include <set>
#include <string>
#include <vector>


extern std::string PASSGEN_VERSION;
extern std::set<std::string> CMD_LINE_ARGUMENTS;

extern int PASSWORD_LENGTH;
extern bool LOWER_CASE_LETTERS_FLAG;
extern bool UPPER_CASE_LETTERS_FLAG;
extern bool NUMBERS_FLAG;
extern bool SPECIAL_CHARS_FLAG;
extern int NUMBER_OF_PASSWORDS;

extern std::vector<char> LOWER_CASE_LETTERS;
extern std::vector<char> UPPER_CASE_LETTERS;
extern std::vector<char> NUMBERS;
extern std::vector<char> SPECIAL_CHARS;