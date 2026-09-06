/*
** EPITECH PROJECT, 2026
** Peasent
** File description:
** Peasent
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string& name, int power) : _name(name), _health(100) {
    this->_power = power;
    if (power > 100)
        this->_power = 100;
    if (power < 0)
        this->_power = 0;

    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant(void) {
    std::cout << this->_name << " is back to his crops." << std::endl;
}

const std::string& Peasant::getName(void) const {
    return this->_name;
}

int Peasant::getPower(void) const {
    return this->_power;
}

int Peasant::getHp(void) const {
    return this->_health;
}

void Peasant::setPower(int new_power) {
    if (new_power > 100) {
        this->_power = 100;
        return;
    }
    if (new_power < 0) {
        this->_power = 0;
        return;
    }
    this->_power = new_power;
    return;
}

void Peasant::setHp(int new_hp) {
    if (new_hp > 100) {
        this->_health = 100;
        return;
    }
    if (new_hp < 0) {
        this->_health = 0;
        return;
    }
    this->_health = new_hp;
    return;
}

int Peasant::attack(void) {
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }

    this->setPower(this->getPower() - 10);
    std::cout << this->_name << " tosses a stone." << std::endl;

    return 5;
}

int Peasant::special(void) {
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }

    std::cout << this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest(void) {
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }

    this->setPower(this->getPower() + 30);

    std::cout << this->_name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage) {
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }

    if (damage < 0) {
        std::cout << this->_name << " takes " << 0 << " damage." << std::endl;
        return;
    }

    int damage_return = damage;

    if (this->_health < 5)
        damage_return = this->_health;

    this->setHp(this->getHp() - damage);

    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    std::cout << this->_name << " takes " << damage_return << " damage." << std::endl;
}
