/*
** EPITECH PROJECT, 2026
** Raspberry
** File description:
** Raspberry
*/

#pragma once

#include "ABerry.hpp"
#include <string>

class Raspberry : public ABerry {
  public:
    Raspberry(void) : ABerry(new std::string("raspberry"), 5, true) {};
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Raspberry& raspberry);
