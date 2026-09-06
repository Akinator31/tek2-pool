/*
** EPITECH PROJECT, 2026
** Cyberfoundry
** File description:
** Cyberfoundry
*/

#include "Cyberfoundry.hpp"
#include "Cyberleader.hpp"
#include "Cyberman.hpp"
#include "Human.hpp"
#include <iostream>

Mondas::Cyberfoundry::Cyberfoundry(unsigned int &energy): _energie(energy)
{
    std::cout << "A new Cyberfoundry has opened." << std::endl;
}

Mondas::Cyberfoundry::~Cyberfoundry(void)
{
    std::cout << "A Cyberfoundry has closed." << std::endl;
}

Mondas::Cyberman *Mondas::Cyberfoundry::buildCyberman(Mondas::Human &human)
{
    unsigned int cost = 50 + human.getIq();

    if (this->_energie < cost) {
        std::cout << "Not enough energy to build a new Cyberman." << std::endl;
        return NULL;
    }
    if (!human.getInhibitor()) {
        human.setInhibitor(new Mondas::Cyberman::Inhibitor());
        human.getInhibitor()->set(true);
    }
    this->_energie -= cost;
    std::cout << "Building a new Cyberman from '" << human.getName() << "'." << std::endl;
    return new Mondas::Cyberman(human);
}

Mondas::Cyberleader *Mondas::Cyberfoundry::buildCyberleader(Mondas::Human &human)
{
    unsigned int cost = 150 + 2 * human.getIq();

    if (this->_energie < cost) {
        std::cout << "Not enough energy to build a new Cyberleader." << std::endl;
        return NULL;
    }
    if (!human.getInhibitor()) {
        human.setInhibitor(new Mondas::Cyberman::Inhibitor());
        human.getInhibitor()->set(true);
    }
    this->_energie -= cost;
    std::cout << "Building a new Cyberleader from '" << human.getName() << "'." << std::endl;
    return new Mondas::Cyberleader(human);
}

void Mondas::Cyberfoundry::recycle(Mondas::Cyberman *&cyberman)
{
    if (!cyberman) {
        std::cout << "Nothing to recycle." << std::endl;
        return;
    }

    std::cout << "Recycling Cyberman '" << convert_name(cyberman->getHuman().getName()) << "'." << std::endl;
    cyberman->getHuman().deleteInhibitor();
    delete cyberman;

    this->_energie += 50;
    cyberman = NULL;
}

void Mondas::Cyberfoundry::recycle(Mondas::Cyberleader *&cyberleader)
{
    if (!cyberleader) {
        std::cout << "Nothing to recycle." << std::endl;
        return;
    }

    std::cout << "Recycling Cyberleader '" << convert_name(cyberleader->get_human()->getName()) << "'." << std::endl;
    cyberleader->get_human()->deleteInhibitor();
    delete cyberleader;

    this->_energie += 150;
    cyberleader = NULL;
}
