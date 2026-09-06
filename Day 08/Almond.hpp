/*
** EPITECH PROJECT, 2026
** Almond
** File description:
** Almond
*/

#pragma once

#include "ANut.hpp"

class Almond : public ANut {
  public:
    Almond(void);
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Almond& almond);
