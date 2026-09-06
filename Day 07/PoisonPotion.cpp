/*
** EPITECH PROJECT, 2026
** PoisonPotion
** File description:
** PoisonPotion
*/

#include "PoisonPotion.hpp"

int PoisonPotion::addPower(void) const {
    return 0;
}

int PoisonPotion::addHealth(void) const {
    return 0;
}

int PoisonPotion::removePower(void) const {
    return 0;
}

int PoisonPotion::removeHealth(void) const {
    return 50;
}

const std::string& PoisonPotion::getOutput(void) const {
    std::string* out = new std::string(" has been poisoned.");
    return *out;
}
