/*
** EPITECH PROJECT, 2026
** Paladin
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include "Enchanter.hpp"
#include "Knight.hpp"
#include "Peasant.hpp"
#include "Priest.hpp"
#include <iostream>

Paladin::Paladin(const std::string& name, int power)
    : Peasant(name, power), Knight(name, power), Priest(name, power) {

    std::cout << Knight::getName() << " fights for the light." << std::endl;
}

Paladin::~Paladin(void) {
    std::cout << Knight::getName() << " is blessed." << std::endl;
}

int Paladin::attack(void) {
    return Knight::attack();
}

int Paladin::special(void) {
    return Enchanter::special();
}

void Paladin::rest(void) {
    return Priest::rest();
}
