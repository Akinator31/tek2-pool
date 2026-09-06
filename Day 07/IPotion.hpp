/*
** EPITECH PROJECT, 2026
** IPotion
** File description:
** IPotion
*/

#pragma once
#include <string>

class IPotion {
  public:
    IPotion() = default;

    virtual int addHealth(void) const = 0;
    virtual int addPower(void) const = 0;

    virtual int removePower(void) const = 0;
    virtual int removeHealth(void) const = 0;

    virtual const std::string& getOutput(void) const = 0;
};
