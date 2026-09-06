/*
** EPITECH PROJECT, 2026
** Human
** File description:
** Human
*/

#include <cstdlib>
#include <iostream>
#include "Human.hpp"
#include "Cyberman.hpp"

Mondas::Human::Human(std::string name, unsigned int iq, Mondas::Cyberman::Inhibitor *inhibitor)
{
    this->_name = name;
    if (iq != 192)
        this->_iq = iq;
    if (inhibitor != NULL)
        this->_inhibitor = inhibitor;

    std::cout << this->_name << ": I must save Mondas with my IQ of " << this->_iq << "." << std::endl;
}

Mondas::Human::Human(std::string name, Cyberman::Inhibitor *inhibitor)
{
    this->_name = name;
    if (inhibitor != NULL)
        this->_inhibitor = inhibitor;

    std::cout << this->_name << ": I must save Mondas with my IQ of " << this->_iq << "." << std::endl;
}

Mondas::Human::Human(std::string name, unsigned int iq)
{
    this->_name = name;
    if (iq != 192)
        this->_iq = iq;

    std::cout << this->_name << ": I must save Mondas with my IQ of " << this->_iq << "." << std::endl;
}

Mondas::Human::Human(std::string name)
{
    this->_name = name;

    std::cout << this->_name << ": I must save Mondas with my IQ of " << this->_iq << "." << std::endl;
}

Mondas::Human::~Human(void)
{
    std::cout << this->_name << ": I failed to save my world..." << std::endl;
}

std::string Mondas::Human::getName(void) const
{
    return this->_name;
}

unsigned int Mondas::Human::getIq(void) const
{
    return this->_iq;
}

void Mondas::Human::setIq(unsigned int new_iq)
{
    if (new_iq <= this->_iq)
        return;
    this->_iq = new_iq;
    std::cout << this->_name << ": My IQ is now " << this->_iq << "." << std::endl;
}

void Mondas::Human::think(void) const
{
    std::cout << this->_name << ": Think, think, think..." << std::endl;
}

void Mondas::Human::setInhibitor(Mondas::Cyberman::Inhibitor *inhibitor)
{
    if (this->_inhibitor == NULL)
        this->_inhibitor = inhibitor;
}

Mondas::Cyberman::Inhibitor *Mondas::Human::getInhibitor(void)
{
    return this->_inhibitor;
}

const Mondas::Cyberman::Inhibitor *Mondas::Human::getInhibitor(void) const
{
    return this->_inhibitor;
}

void Mondas::Human::deleteInhibitor()
{
    delete this->_inhibitor;
    this->_inhibitor = NULL;
}
