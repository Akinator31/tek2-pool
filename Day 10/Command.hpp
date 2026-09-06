/*
** EPITECH PROJECT, 2026
** Command
** File description:
** Command
*/

#pragma once

#include <exception>
#include <functional>
#include <map>
#include <string>

class Command {
    std::map<std::string, std::function<void()>> _instructions = {};

  public:
    void registerCommand(const std::string& name, const std::function<void()>& function);
    void executeCommand(const std::string& name);

    class Error : public std::exception {
        std::string _message;

      public:
        Error(const char* message);
        const char* what() const noexcept override {
            return this->_message.c_str();
        }
    };
};
