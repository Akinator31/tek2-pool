/*
** EPITECH PROJECT, 2026
** Grapefruit
** File description:
** Grapefruit
*/

#pragma once

#include "ACitrus.hpp"
#include <iostream>

class Grapefruit : public ACitrus {
  public:
    Grapefruit(void) : ACitrus(new std::string("grapefruit"), 5, false) {};
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Grapefruit& grapefruit);
