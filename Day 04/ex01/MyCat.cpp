/*
** EPITECH PROJECT, 2026
** MyCat
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>

int print_file(char *file_args)
{
    std::string destination;

    if (!file_args)
        return 0;
    std::ifstream buff = std::ifstream(file_args);
    if (buff.fail() || !buff.is_open()) {
        return 0;
    }
    std::cout << buff.rdbuf();
    buff.close();
    return 1;
}

int print_std()
{
    std::cout << std::cin.rdbuf();
    return 0;
}

int main(int argc, char **argv)
{
    int code_return = 0;

    if (argc < 2)
        return print_std();
    for (int i = 1; i < argc; i++) {
        if (!print_file(argv[i])) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            code_return = 84;
        }
    }
    return code_return;
}
