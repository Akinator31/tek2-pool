/*
** EPITECH PROJECT, 2026
** SafeDirectoryLister
** File description:
** SafeDirectoryLister
*/

#pragma once

#include "IDirectoryLister.hpp"
#include "dirent.h"
#include <dirent.h>

class SafeDirectoryLister : public IDirectoryLister {
  public:
    SafeDirectoryLister(void) = default;
    SafeDirectoryLister(const std::string& path, bool hidden);
    ~SafeDirectoryLister(void);
    bool open(const std::string& path, bool hidden) override;
    std::string get(void) override;

  private:
    DIR* directory_stream = NULL;
    bool hidden = false;
};
