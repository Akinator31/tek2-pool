/*
** EPITECH PROJECT, 2026
** Priest
** File description:
** Priest
*/

#include "Priest.hpp"
#include "Enchanter.hpp"
#include "Peasant.hpp"
#include <iostream>
#include <ostream>
#include <string>

Priest::Priest(const std::string& name, int power) : Peasant(name, power), Enchanter(name, power) {
    std::cout << this->getName() << " enters in the order." << std::endl;
}

Priest::~Priest(void) {
    std::cout << this->getName() << " finds peace." << std::endl;
}

void Priest::rest(void) {
    if (this->getHp() == 0) {
        std::cout << this->getName() << " is out of combat." << std::endl;
        return;
    }

    this->setPower(this->getPower() + 100);
    this->setHp(this->getHp() + 100);

    std::cout << this->getName() << " prays." << std::endl;
}
