#include "AbstractVM.hpp"
#include "Parser.hpp"
#include <cstring>
#include <exception>
#include <iostream>

int print_help(void) {
    std::cout << "usage: bistroMatic [options]" << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "-h, --help Show this help" << std::endl;
    std::cout << "-b, --bonus Add any flag you want for bonuses! (no)" << std::endl;
    return 0;
}

int main(int ac, char** av) {
    if (ac > 1 && (strcmp(av[1], "--help") || strcmp(av[1], "-h"))) {
        return print_help();
    }

    try {
        AbstractVM vm;
        Parser parser(vm);

        parser.loop();

        return 0;
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        return 84;
    }

    return 0;
}
