/*
** EPITECH PROJECT, 2026
** HealthPotion
** File description:
** HealthPotion
*/

#pragma once

#include "IPotion.hpp"
class HealthPotion : public IPotion {
  public:
    HealthPotion(void) = default;

    int addPower(void) const override;
    int addHealth(void) const override;

    int removePower(void) const override;
    int removeHealth(void) const override;

    const std::string& getOutput(void) const override;
};
