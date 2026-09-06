#pragma once
#include <exception>
#include <string>

class LoadException : public std::exception {
  private:
    std::string message = "Cannot open file : ";

  public:
    LoadException(const std::string& path) {
        message += path;
    };

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class MemoryException : public std::exception {
  private:
    std::string message = "Not enough data to get memory info.";

  public:
    const char* what() const noexcept override {
        return message.c_str();
    }
};
