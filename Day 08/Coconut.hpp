/*
** EPITECH PROJECT, 2026
** Coconut
** File description:
** Coconut
*/

#pragma once

#include "ANut.hpp"

class Coconut : public ANut {
  public:
    Coconut(void);
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Coconut& coconut);
