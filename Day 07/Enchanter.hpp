/*
** EPITECH PROJECT, 2026
** Enchanter
** File description:
** Enchanter
*/

#pragma once
#include "Peasant.hpp"
#include <string>

class Enchanter : virtual public Peasant {
  public:
    Enchanter(const std::string& name, int power);
    ~Enchanter(void);

    int attack(void) override;
    int special(void) override;
    virtual void rest(void) override;
};
