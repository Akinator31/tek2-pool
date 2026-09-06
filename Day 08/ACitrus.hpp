/*
** EPITECH PROJECT, 2026
** ACitrus
** File description:
** ACitrus
*/

#pragma once

#include "AFruit.hpp"

class ACitrus : public AFruit {
  public:
    ACitrus(std::string* name, unsigned int vitamins, bool isFruitPeeled);
};
