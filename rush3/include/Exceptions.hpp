#pragma once

#include <exception>
#include <string>

class ParsingErrorException : public std::exception {
  private:
    std::string message = "";

  public:
    ParsingErrorException(const size_t line, const std::string& error) {
        std::string errorMessage = "on line: " + std::to_string(line) + error;
        this->message = errorMessage;
    };

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class PopException : public std::exception {
  private:
    std::string message = "pop instruction on an empty stack";

  public:
    PopException(void) {};

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class AssertException : public std::exception {
  private:
    std::string message = "assert instruction is not verified";

  public:
    AssertException(void) {};

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class StackSizeException : public std::exception {
  private:
    std::string message = "the stack strictly has less than two values during the execution of an "
                          "arithmetical instruction.";

  public:
    StackSizeException(void) {};

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class DivisionException : public std::exception {
  private:
    std::string message = "division by zero c non";

  public:
    DivisionException(void) {};

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class LoadException : public std::exception {
  private:
    std::string message = "load instruction on an empty register";

  public:
    LoadException(void) {};

    const char* what() const noexcept override {
        return message.c_str();
    }
};
