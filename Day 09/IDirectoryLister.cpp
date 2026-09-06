/*
** EPITECH PROJECT, 2026
** IDirectoryLister
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"
#include <cerrno>
#include <cstring>

const char* IDirectoryLister::OpenFailureException::what(void) const noexcept {
    return strerror(errno);
}

const char* IDirectoryLister::NoMoreFileException::what(void) const noexcept {
    return "End of stream";
}
