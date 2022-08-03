#include <iostream>

#include <getopt.h>
#include <unistd.h>

void check_cmd_line_options (int argc, char *argv[]) {
    int option;
    while ((option = getopt(argc, argv, "l")) != 1) {
        switch (option) {
        case 'l':
            std::cout << option << std::endl;
            break;
        default:
            std::cout << "Erro! Opção não suportada!" << std::endl;
            break;
        }
    }
}

