/*
** EPITECH PROJECT, 2026
** Droid
** File description:
** Droid
*/

#include <cstddef>
#include <ostream>
#include <iostream>
#include <string>
#include "Droid.hpp"

Droid::Droid(const std::string serial_number): _id(serial_number) {
    DroidMemory new_mem;
    std::cout << "Droid '" << this->getId() << "' Activated" << std::endl;

    this->_battledata = &new_mem;
}

Droid::Droid(const Droid &droid):
    _status(new std::string(*droid._status))
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    this->_battledata = droid._battledata;

    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(void)
{
    if (this->_status)
        delete this->_status;

    std::cout << "Droid '" << this->getId() << "' Destroyed" << std::endl;
}

Droid &Droid:: operator=(const Droid &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;

    if (this->_status)
        delete this->_status;

    this->_status = new std::string((droid.getStatus() ? *droid.getStatus() : ""));

    return *this;
}

const std::string Droid::getId(void) const
{
    return this->_id;
}

size_t Droid::getEnergy(void) const
{
    return this->_energy;
}

size_t Droid::getAttack(void) const
{
    return this->_attack;
}

size_t Droid::getToughness(void) const
{
    return this->_toughness;
}

const std::string *Droid::getStatus(void) const
{
    return this->_status;
}

std::string *Droid::getStatus(void)
{
    return this->_status;
}

void Droid::setId(const std::string new_id)
{
    this->_id = new_id;
}

void Droid::setEnergy(const size_t new_energy)
{
    if (new_energy >= 100) {
        this->_energy = 100;
        return;
    }
    this->_energy = new_energy;
}

void Droid::setStatus(std::string *new_status)
{
    if (this->_status)
        delete this->_status;
    this->_status = new_status;
}

bool Droid::operator==(const Droid &droid) const
{
    if (!this->_status && !droid._status)
        return true;
    if (!this->_status && droid._status)
        return false;
    if (this->_status && !droid._status)
        return false;
    if (*this->_status == *droid._status)
        return true;
    return false;
}

bool Droid::operator!=(const Droid &droid) const
{
    if (!this->_status && !droid._status)
        return false;
    if (!this->_status && droid._status)
        return true;
    if (this->_status && !droid._status)
        return true;
    if (*this->_status != *droid._status)
        return true;
    return false;
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t new_energy = 0;

    if ((this->_energy + energy) >= 100)
        new_energy = energy - (100 - this->_energy);
    this->setEnergy(this->getEnergy() + energy);
    energy = new_energy;

    return *this;
}

std::ostream &operator<<(std::ostream &s, const Droid &droid)
{
    return s << "Droid '" << droid.getId() << "', " << (droid.getStatus() ? *droid.getStatus() : "") << ", " << droid.getEnergy();
}

DroidMemory *Droid::getBattleData(void) const
{
    return this->_battledata;
}

void Droid::setBattleData(DroidMemory *mem)
{
    this->_battledata = mem;
}
