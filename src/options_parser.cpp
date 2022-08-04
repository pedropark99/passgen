#include <iostream>
#include <string>
#include <sstream>

// Global variables
int PASSWORD_LENGTH = 10;
int SPECIAL_CHARS_FLAG = 0;
std::string CMD_LINE_OPTIONS[] = {
    "-l", "--length",
    "-s", "--special-chars"
};


// Functions defined in this cpp:
void parseCmdLineArguments (int argc, char *argv[]);
bool isLengthArgument (std::string arg);
bool isSpecialCharsArgument (std::string arg);
int castLengthValue (std::string lengthValue);





void parseCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    std::string nextArgument;
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        if (isLengthArgument(currentArgument)) {
            argumentIndex++;
            nextArgument = std::string(argv[argumentIndex]);
            PASSWORD_LENGTH = castLengthValue(nextArgument);
            continue;
        }
        if (isSpecialCharsArgument(currentArgument)) {
            SPECIAL_CHARS_FLAG = 1;
            continue;
        }
    }
}


bool isLengthArgument (std::string arg) {
    return arg == "-l" | arg == "--length";
}

bool isSpecialCharsArgument (std::string arg) {
    return arg == "-s" | arg == "--special-chars";
}

int castLengthValue (std::string lengthValue) {
    std::istringstream ss(lengthValue);
    int castedValue;
    if (!(ss >> castedValue)) {
        std::cerr << "Error: Invalid number passed to `-l` or `--length` argument: " << lengthValue << '\n';
    } else if (!ss.eof()) {
        std::cerr << "Error: Trailing characters after number passed to `-l` or `--length` argument: " << lengthValue << '\n';
    }
    return castedValue;
}