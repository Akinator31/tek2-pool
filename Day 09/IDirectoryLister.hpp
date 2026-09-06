/*
** EPITECH PROJECT, 2026
** IDirectoryLister
** File description:
** IDirectoryLister
*/

#pragma once

#include <exception>
#include <string>

class IDirectoryLister {
  public:
    virtual bool open(const std::string& path, bool hidden) = 0;
    virtual std::string get(void) = 0;

    class OpenFailureException : public std::exception {
      public:
        OpenFailureException(void) = default;
        const char* what() const noexcept override;
    };

    class NoMoreFileException : public std::exception {
      public:
        NoMoreFileException(void) = default;
        const char* what() const noexcept override;
    };
};
