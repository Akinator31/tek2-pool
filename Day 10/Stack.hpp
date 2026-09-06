/*
** EPITECH PROJECT, 2026
** Stack
** File description:
** Stack
*/

#pragma once

#include <exception>
#include <stack>
#include <string>

class Stack {
    std::stack<double> _stack;

  public:
    class Error : public std::exception {
        std::string _message;

      public:
        Error(std::string message) : _message(message) {};
        const char* what(void) const noexcept override {
            return this->_message.c_str();
        }
    };

    void push(double value);
    double pop(void);
    double top(void) const;

    void add(void);
    void sub(void);
    void mul(void);
    void div(void);
};
