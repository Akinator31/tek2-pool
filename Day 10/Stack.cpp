/*
** EPITECH PROJECT, 2026
** Stack
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value) {
    this->_stack.push(value);
}

double Stack::pop(void) {
    if (this->_stack.empty())
        throw Stack::Error("Empty stack");
    double value = this->_stack.top();
    this->_stack.pop();
    return value;
}

double Stack::top(void) const {
    if (this->_stack.empty())
        throw Stack::Error("Empty stack");
    return this->_stack.top();
}

void Stack::add(void) {
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double a = this->_stack.top();
    this->_stack.pop();
    double b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a + b);
}

void Stack::sub(void) {
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double a = this->_stack.top();
    this->_stack.pop();
    double b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a - b);
}

void Stack::mul(void) {
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double a = this->_stack.top();
    this->_stack.pop();
    double b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a * b);
}

void Stack::div(void) {
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double a = this->_stack.top();
    this->_stack.pop();
    double b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a / b);
}
