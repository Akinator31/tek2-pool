/*
** EPITECH PROJECT, 2026
** Shell
** File description:
** Shell
*/

#include "Shell.hpp"
#include <istream>
#include <sstream>
#include <string>

Shell::Error::Error(const char* message) : _message(message) {
}

Shell::Warning::Warning(const char* message) : _message(message) {
}

Shell::Shell(std::istream& stream) : _stream(stream) {
}

void Shell::next(void) {
    std::string line;

    if (std::getline(this->_stream, line))
        this->_ss = std::stringstream(line);
    if (this->_stream.eof())
        throw Error("End of input");
    if (this->_stream.fail())
        throw Error("Input failed");
}
