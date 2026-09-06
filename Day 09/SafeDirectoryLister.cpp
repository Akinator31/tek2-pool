/*
** EPITECH PROJECT, 2026
** SafeDirectoryLister
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden) {
    this->hidden = hidden;

    SafeDirectoryLister::open(path, this->hidden);
}

SafeDirectoryLister::~SafeDirectoryLister(void) {
    if (this->directory_stream)
        closedir(this->directory_stream);
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden) {
    if (this->directory_stream)
        closedir(this->directory_stream);
    this->directory_stream = opendir(path.c_str());
    this->hidden = hidden;

    if (!this->directory_stream) {
        throw OpenFailureException();
    }
    return true;
}

std::string SafeDirectoryLister::get(void) {
    if (!this->directory_stream)
        return "";
    dirent* dir_entry = readdir(this->directory_stream);

    if (!dir_entry)
        throw NoMoreFileException();
    if (dir_entry->d_name[0] == '.' && !this->hidden)
        return SafeDirectoryLister::get();
    return dir_entry->d_name;
}
