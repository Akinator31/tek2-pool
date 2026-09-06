/*
** EPITECH PROJECT, 2026
** Strawberry
** File description:
** Strawberry
*/

#pragma once

#include "ABerry.hpp"

class Strawberry : public ABerry {
  public:
    Strawberry(void);
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const Strawberry& strawberry);
