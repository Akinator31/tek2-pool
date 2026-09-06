/*
** EPITECH PROJECT, 2026
** Stack
** File description:
** Stack
*/

#pragma once

#include <exception>
#include <istream>
#include <sstream>

class Shell {
    std::istream& _stream;
    std::stringstream _ss;

  public:
    Shell(std::istream& stream);
    void next(void);

    template <typename T> T extract(void) {
        T value;
        if (!(this->_ss >> value))
            throw Warning("Invalid conversion");
        return value;
    }

    class Error : public std::exception {
        const char* _message = "";

      public:
        Error(const char* message);
        const char* what(void) const noexcept override {
            return this->_message;
        }
    };

    class Warning : public std::exception {
        const char* _message = "";

      public:
        Warning(const char* message);
        const char* what(void) const noexcept override {
            return this->_message;
        }
    };
};
