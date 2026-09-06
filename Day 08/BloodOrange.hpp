/*
** EPITECH PROJECT, 2026
** BloodOrange
** File description:
** BloodOrange
*/

#pragma once

#include "Orange.hpp"
#include <iostream>

class BloodOrange : public Orange {
  public:
    BloodOrange(void);
    IFruit* clone(void) const override;
};

std::ostream& operator<<(std::ostream& stream, const BloodOrange& bloodorange);
