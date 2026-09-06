/*
** EPITECH PROJECT, 2026
** PowerPotion
** File description:
** PowerPotion
*/

#include "PowerPotion.hpp"

int PowerPotion::addPower(void) const {
    return 50;
}

int PowerPotion::addHealth(void) const {
    return 0;
}

int PowerPotion::removePower(void) const {
    return 0;
}

int PowerPotion::removeHealth(void) const {
    return 0;
}

const std::string& PowerPotion::getOutput(void) const {
    std::string* out = new std::string("'s power is restored.");
    return *out;
}
