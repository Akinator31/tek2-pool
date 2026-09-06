/*
** EPITECH PROJECT, 2026
** Cyberleader
** File description:
** Cyberlegion
*/

#include "Cyberlegion.hpp"
#include "Cyberfoundry.hpp"
#include "Cyberleader.hpp"
#include "Cyberman.hpp"
#include "Human.hpp"
#include <iostream>

Mondas::Cyberlegion::Cyberlegion(unsigned int &energy)
{
    static unsigned int id = 1;

    this->_id = id;
    this->cyberleader = NULL;
    this->foundry = new Mondas::Cyberfoundry(energy);
    std::cout << "Cyberlegion #" << this->_id << ": Humanity will be upgraded." << std::endl;
    id += 1;
}

Mondas::Cyberlegion::~Cyberlegion(void)
{
    Mondas::Human *human = NULL;

    std::cout << "Cyberlegion #" << this->_id << ": Impossible, we can't fail." << std::endl;
    if (this->cyberleader) {
        human = this->cyberleader->get_human();
    }

    delete this->cyberleader;
    delete human;

    for (Cyberman *c: this->cybermen) {
        Mondas::Human temp = c->getHuman();
        delete c;
    }
    delete this->foundry;
}

bool Mondas::Cyberlegion::assimilate(Mondas::Human *human)
{
    if (!human)
        return false;
    if (!this->cyberleader) {
        Mondas::Cyberleader *new_cyberleader = this->foundry->buildCyberleader(*human);

        if (!new_cyberleader) {
            std::cout << "Cyberlegion #" << this->_id << ": '" << human->getName() << "' can't be assimilated. " << "'" << human->getName() << "' will be deleted." << std::endl;
            human->~Human();
            return false;
        }

        this->cyberleader = new_cyberleader;
        std::cout << "Cyberlegion #" << this->_id << ": '" << convert_name(human->getName()) << "' is now our Cyberleader." << std::endl;
        return true;
    } else {
        Mondas::Cyberman *new_cyberman = this->foundry->buildCyberman(*human);

        if (!new_cyberman) {
            std::cout << "Cyberlegion #" << this->_id << ": '" << human->getName() << "' can't be assimilated. " << "'" << human->getName() << "' will be deleted." << std::endl;
            human->~Human();
            return false;
        }

        this->cyberleader->upgrade(*new_cyberman);
        this->cybermen.push_back(new_cyberman);
        std::cout << "Cyberlegion #" << this->_id << ": '" << convert_name(human->getName()) << "' has joined our Cyberlegion." << std::endl;
        return true;
    }
}

Mondas::Cyberleader *Mondas::Cyberlegion::getCyberleader(void)
{
    return this->cyberleader;
}

const Mondas::Cyberleader *Mondas::Cyberlegion::getCyberleader(void) const
{
    return this->cyberleader;
}

Mondas::Cyberman **Mondas::Cyberlegion::getCybermen(void)
{
    return this->cybermen.data();
}

const Mondas::Cyberman* const* Mondas::Cyberlegion::getCybermen(void) const
{
    return this->cybermen.data();
}

unsigned int Mondas::Cyberlegion::getSize(void) const
{
    return this->cybermen.size();
}

unsigned int Mondas::Cyberlegion::getIq(void) const
{
    unsigned int iq_result = 0;

    for (Cyberman *a: this->cybermen) {
        iq_result += a->getIq();
    }
    return iq_result;
}
