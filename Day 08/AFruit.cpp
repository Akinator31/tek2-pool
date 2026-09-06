/*
** EPITECH PROJECT, 2026
** AFruit
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit(std::string* name, unsigned int vitamins, bool isFruitPeeled) {
    this->name = name;
    this->vitamins = vitamins;
    this->isFruitPeeled = isFruitPeeled;
}

AFruit::~AFruit(void) {
    if (this->name)
        delete this->name;
}

unsigned int AFruit::getVitamins(void) const {
    if (this->isPeeled())
        return this->vitamins;
    return 0;
}

std::string AFruit::getName(void) const {
    return *this->name;
}

bool AFruit::isPeeled(void) const {
    return this->isFruitPeeled;
}

void AFruit::peel(void) {
    this->isFruitPeeled = true;
}
