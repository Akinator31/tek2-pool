/*
** EPITECH PROJECT, 2026
** DirectoryLister
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"
#include <cstdio>
#include <dirent.h>

DirectoryLister::DirectoryLister(const std::string& path, bool hidden) {
    this->hidden = hidden;

    DirectoryLister::open(path, this->hidden);
}

DirectoryLister::~DirectoryLister(void) {
    if (this->directory_stream)
        closedir(this->directory_stream);
}

bool DirectoryLister::open(const std::string& path, bool hidden) {
    if (this->directory_stream)
        closedir(this->directory_stream);
    this->directory_stream = opendir(path.c_str());
    this->hidden = hidden;

    if (!this->directory_stream) {
        perror(path.c_str());
        return false;
    }
    return true;
}

std::string DirectoryLister::get(void) {
    if (!this->directory_stream)
        return "";
    dirent* dir_entry = readdir(this->directory_stream);

    if (!dir_entry)
        return "";
    if (dir_entry->d_name[0] == '.' && !this->hidden)
        return DirectoryLister::get();
    return dir_entry->d_name;
}
