/*
** EPITECH PROJECT, 2026
** HealthPotion
** File description:
** HealthPotion
*/

#include "HealthPotion.hpp"

int HealthPotion::addPower(void) const {
    return 0;
}

int HealthPotion::addHealth(void) const {
    return 50;
}

int HealthPotion::removePower(void) const {
    return 0;
}

int HealthPotion::removeHealth(void) const {
    return 0;
}

const std::string& HealthPotion::getOutput(void) const {
    std::string* tkt = new std::string(" feels rejuvenated.");
    return *tkt;
}
