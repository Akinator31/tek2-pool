/*
** EPITECH PROJECT, 2026
** Paladin
** File description:
** Paladin
*/

#pragma once
#include "Knight.hpp"
#include "Priest.hpp"
#include <string>

class Paladin : public Knight, public Priest {
  public:
    Paladin(const std::string& name, int power);
    ~Paladin(void);
    int attack(void) override;
    void rest(void) override;
    int special(void) override;
};
