#include <iostream>
#include <string>
#include <sstream>

// Global variables
int PASSWORD_LENGTH = 10;
int SPECIAL_CHARS_FLAG = 0;
std::string CMD_LINE_ARGUMENTS[] = {
    "-l", "--length",
    "-s", "--special-chars"
};


// Functions defined in this cpp:
void parseCmdLineArguments (int argc, char *argv[]);
void checkNumberOfArguments (int argc);
void checkIfNextArgumentExists (int argc, int argumentIndex);
bool isLengthArgument (std::string arg);
bool isSpecialCharsArgument (std::string arg);
int castLengthValue (std::string lengthValue);





void parseCmdLineArguments (int argc, char *argv[]) {
    std::string currentArgument;
    std::string nextArgument;
    checkNumberOfArguments(argc);
    for (int argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
        currentArgument = std::string(argv[argumentIndex]);
        if (isLengthArgument(currentArgument)) {
            checkIfNextArgumentExists(argc, argumentIndex);
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


void checkNumberOfArguments (int argc) {
    int numberOfCmdArguments = (sizeof(CMD_LINE_ARGUMENTS) / sizeof(CMD_LINE_ARGUMENTS[0])) / 2;
    int lengthValueArgument = 1;
    int commandNameArgument = 1;
    int numberOfValidArguments = numberOfCmdArguments + lengthValueArgument + commandNameArgument;
    if (argc > numberOfValidArguments) {
        throw std::invalid_argument("Too many arguments given to `password` command at the command line!");
    }
}

void checkIfNextArgumentExists (int argc, int argumentIndex) {
    int nextIndex = argumentIndex + 1;
    if (nextIndex > argc) {
        throw std::invalid_argument("After the argument `-l` or `--length`, you need to provide a integer (that represents the password length), but, none was given!");
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