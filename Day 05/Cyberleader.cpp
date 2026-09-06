/*
** EPITECH PROJECT, 2026
** Cyberleader
** File description:
** Cyberleader
*/

#include "Cyberleader.hpp"
#include "Cyberman.hpp"
#include "Human.hpp"
#include <iostream>
#include <ostream>

Mondas::Cyberleader::Cyberleader(Mondas::Human &human): _human(human)
{
    std::cout << convert_name(this->_human.getName()) << ": Master unit activated." << std::endl;
}

void Mondas::Cyberleader::think(void)
{
    std::cout << convert_name(this->_human.getName()) << ": Pain, pain, pain..." << std::endl;
}

Mondas::Cyberleader::~Cyberleader(void)
{
    std::cout << convert_name(this->_human.getName()) << ": Master unit deactivated." << std::endl;
}

Mondas::Human *Mondas::Cyberleader::get_human(void)
{
    return &this->_human;
}

void upgrade_human(Mondas::Human &human)
{
    unsigned int actual_iq = human.getIq();

    human.setIq(actual_iq * 2);
    std::cout << "IQ of unit doubled, increased to " << actual_iq * 2 << "." << std::endl;
}

void Mondas::Cyberleader::upgrade(Mondas::Cyberman &cyberman)
{
    if (this->_human.getInhibitor() && this->_human.getInhibitor()->get()) {
        Mondas::Human &human = cyberman.getHuman();
        std::cout << convert_name(this->_human.getName()) << ": Upgrading unit '" << convert_name(human.getName()) << "'." << std::endl;
        this->upgrade(human);
    } else {
        this->think();
    }
}

void Mondas::Cyberleader::upgrade(Mondas::Human &human)
{
    if (this->_human.getInhibitor() && this->_human.getInhibitor()->get()) {
        std::cout << convert_name(this->_human.getName()) << ": Upgrading human '" << human.getName() << "'." << std::endl;
        upgrade_human(human);
        if (!human.getInhibitor()) {
            std::cout << "No inhibitor installed." << std::endl;
        } else {
            this->upgrade(*human.getInhibitor());
        }
    } else {
        this->think();
    }
}

void Mondas::Cyberleader::upgrade(Mondas::Cyberman::Inhibitor &inhibitor)
{
    if (this->_human.getInhibitor() && this->_human.getInhibitor()->get()) {
        if (!inhibitor.get()) {
            std::cout << convert_name(this->_human.getName()) << ": Activating inhibitor." << std::endl;
            inhibitor.set(true);
        } else {
            std::cout << convert_name(this->_human.getName()) << ": Inhibitor already activated." << std::endl;
        }
    } else {
        this->think();
    }
}
