/*
** EPITECH PROJECT, 2026
** ICharacter
** File description:
** ICharacter
*/

#pragma once
#include "HealthPotion.hpp"
#include "IPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"
#include <iostream>
#include <string>

class ICharacter {
  public:
    virtual ~ICharacter() = default;

    virtual const std::string& getName(void) const = 0;
    virtual int getPower(void) const = 0;
    virtual int getHp(void) const = 0;

    virtual void setPower(int new_power) = 0;
    virtual void setHp(int new_hp) = 0;

    virtual int attack(void) = 0;
    virtual int special(void) = 0;
    virtual void rest(void) = 0;
    virtual void damage(int) = 0;

    void drink(const PoisonPotion& potion) {
        std::cout << this->getName() << potion.getOutput() << std::endl;

        this->setHp(this->getHp() + potion.addHealth());
        this->setHp(this->getHp() - potion.removeHealth());
        this->setPower(this->getPower() + potion.addPower());
        this->setPower(this->getPower() - potion.removePower());
    }

    void drink(const PowerPotion& potion) {
        std::cout << this->getName() << potion.getOutput() << std::endl;

        this->setHp(this->getHp() + potion.addHealth());
        this->setHp(this->getHp() - potion.removeHealth());
        this->setPower(this->getPower() + potion.addPower());
        this->setPower(this->getPower() - potion.removePower());
    }

    void drink(const HealthPotion& potion) {
        std::cout << this->getName() << potion.getOutput() << std::endl;

        this->setHp(this->getHp() + potion.addHealth());
        this->setHp(this->getHp() - potion.removeHealth());
        this->setPower(this->getPower() + potion.addPower());
        this->setPower(this->getPower() - potion.removePower());
    }

    void drink(const IPotion& potion) {
        std::cout << this->getName() << " drinks a mysterious potion." << std::endl;

        this->setHp(this->getHp() + potion.addHealth());
        this->setHp(this->getHp() - potion.removeHealth());
        this->setPower(this->getPower() + potion.addPower());
        this->setPower(this->getPower() - potion.removePower());
    }
};
