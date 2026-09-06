/*
** EPITECH PROJECT, 2026
** ABerry
** File description:
** ABerry
*/

#pragma once

#include "AFruit.hpp"

class ABerry : public AFruit {
  public:
    ABerry(std::string* name, unsigned int vitamins, bool isFruitPeeled);
    void peel(void) override;
};
