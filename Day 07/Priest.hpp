/*
** EPITECH PROJECT, 2026
** Priest
** File description:
** Priest
*/

#pragma once
#include "Enchanter.hpp"
#include <string>

class Priest : public Enchanter {
  public:
    Priest(const std::string& name, int power);
    ~Priest(void);

    void rest(void) override;
};
