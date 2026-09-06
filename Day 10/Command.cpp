/*
** EPITECH PROJECT, 2026
** Command
** File description:
** Command
*/

#include "Command.hpp"
#include <string>

Command::Error::Error(const char* message) {
    this->_message = message;
}

void Command::registerCommand(const std::string& name, const std::function<void()>& function) {
    if (this->_instructions.contains(name))
        throw Command::Error("Already registered command");
    this->_instructions[name] = function;
}

void Command::executeCommand(const std::string& name) {
    if (this->_instructions.find(name) == this->_instructions.end())
        throw Command::Error("Unknow command");
    this->_instructions[name]();
}
