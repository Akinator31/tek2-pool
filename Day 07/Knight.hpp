/*
** EPITECH PROJECT, 2026
** Knight
** File description:
** Knight
*/

#pragma once

#include "Peasant.hpp"
#include <string>

class Knight : virtual public Peasant {
  public:
    Knight(const std::string& name, int power);
    ~Knight(void);

    int attack(void);
    int special(void);
    void rest(void);
};
