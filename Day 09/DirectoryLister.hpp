/*
** EPITECH PROJECT, 2026
** DirectoryLister
** File description:
** DirectoryLister
*/

#pragma once

#include "IDirectoryLister.hpp"
#include "dirent.h"
#include <dirent.h>

class DirectoryLister : public IDirectoryLister {
  public:
    DirectoryLister(void) = default;
    DirectoryLister(const std::string& path, bool hidden);
    ~DirectoryLister(void);
    bool open(const std::string& path, bool hidden) override;
    std::string get(void) override;

  private:
    DIR* directory_stream = NULL;
    bool hidden = false;
};
