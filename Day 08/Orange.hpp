/*
** EPITECH PROJECT, 2026
** Orange
** File description:
** Orange
*/

#pragma once

#include "ACitrus.hpp"

class Orange : public ACitrus {
  public:
    Orange(void);
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Orange& orange);
