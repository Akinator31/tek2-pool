/*
** EPITECH PROJECT, 2026
** Lemon
** File description:
** Lemon
*/

#pragma once

#include "ACitrus.hpp"
#include <iostream>

class Lemon : public ACitrus {
  public:
    Lemon(void);
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Lemon& lemon);
