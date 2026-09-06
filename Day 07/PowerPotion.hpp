/*
** EPITECH PROJECT, 2026
** PowerPotion
** File description:
** PowerPotion
*/

#pragma once

#include "IPotion.hpp"

class PowerPotion : public IPotion {
  public:
    PowerPotion(void) = default;

    int addHealth(void) const override;
    int addPower(void) const override;

    int removePower(void) const override;
    int removeHealth(void) const override;

    const std::string& getOutput(void) const override;
};
