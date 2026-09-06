/*
** EPITECH PROJECT, 2026
** ABerry
** File description:
** ABerry
*/

#include "ABerry.hpp"

ABerry::ABerry(std::string* name, unsigned int vitamins, bool isFruitPeeled)
    : AFruit(name, vitamins, isFruitPeeled) {
}

void ABerry::peel(void) {
    this->isFruitPeeled = 1;
}
