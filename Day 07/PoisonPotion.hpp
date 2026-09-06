/*
** EPITECH PROJECT, 2026
** PoisonPotion
** File description:
** PoisonPotion
*/

#pragma once

#include "IPotion.hpp"

class PoisonPotion : public IPotion {
  public:
    PoisonPotion(void) = default;

    int addPower(void) const override;
    int addHealth(void) const override;

    int removePower(void) const override;
    int removeHealth(void) const override;

    const std::string& getOutput(void) const override;
};
