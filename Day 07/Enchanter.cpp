/*
** EPITECH PROJECT, 2026
** Enchanter
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include "Peasant.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string& name, int power) : Peasant(name, power) {
    std::cout << this->getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter(void) {
    std::cout << this->getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack(void) {
    if (this->getHp() == 0) {
        std::cout << this->getName() << " is out of combat." << std::endl;
        return 0;
    }

    std::cout << this->getName() << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special(void) {
    if (this->getHp() == 0) {
        std::cout << this->getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() < 50) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }

    this->setPower(this->getPower() - 50);
    std::cout << this->getName() << " casts a fireball." << std::endl;

    return 99;
}

void Enchanter::rest(void) {
    if (this->getHp() == 0) {
        std::cout << this->getName() << " is out of combat." << std::endl;
        return;
    }

    this->setPower(this->getPower() + 100);
    std::cout << this->getName() << " meditates." << std::endl;
}
