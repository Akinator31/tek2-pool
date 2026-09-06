/*
** EPITECH PROJECT, 2026
** Cyberman
** File description:
** Cyberman
*/

#include <iostream>
#include <string>
#include "Cyberman.hpp"
#include "Human.hpp"

std::string convert_name(std::string human_name)
{
    std::string result = "";

    for (size_t i = 0; i < human_name.length(); i++) {
        if (human_name[i] == 'a' || human_name[i] == 'A')
            result.append("4");
        else if (human_name[i] == 'b' || human_name[i] == 'B')
            result.append("8");
        else if (human_name[i] == 'e' || human_name[i] == 'E')
            result.append("3");
        else if (human_name[i] == 'g' || human_name[i] == 'G')
            result.append("6");
        else if (human_name[i] == 'i' || human_name[i] == 'I' || human_name[i] == 'l' || human_name[i] == 'L')
            result.append("1");
        else if (human_name[i] == 'o' || human_name[i] == 'O')
            result.append("0");
        else if (human_name[i] == 'r' || human_name[i] == 'R')
            result.append("2");
        else if (human_name[i] == 's' || human_name[i] == 'S')
            result.append("5");
        else if (human_name[i] == 't' || human_name[i] == 'T' || human_name[i] == 'y' || human_name[i] == 'Y')
            result.append("7");
        else if (human_name[i] == ' ')
            result.append("_");
        else
            result.append(std::string(1, human_name[i]));
    }

    return result;
}

Mondas::Cyberman::Cyberman(Mondas::Human &human): _human(human)
{
    this->_human = human;

    std::cout << convert_name(this->_human.getName()) << ": Unit activated." << std::endl;
}

Mondas::Cyberman::~Cyberman(void)
{
    std::cout << convert_name(this->_human.getName()) << ": Unit deactivated." << std::endl;
}

Mondas::Human& Mondas::Cyberman::getHuman(void)
{
    return this->_human;
}

const Mondas::Human& Mondas::Cyberman::getHuman(void) const
{
    return this->_human;
}

void Mondas::Cyberman::think(void) const
{
    Mondas::Cyberman::Inhibitor *human_inhibitor = this->_human.getInhibitor();

    if (human_inhibitor && human_inhibitor->get()) {
        std::cout << convert_name(this->_human.getName()) << ": Computation in progress." << std::endl;
        return;
    }
    std::cout << convert_name(this->_human.getName()) << ": Pain, pain, pain..." << std::endl;
}

void Mondas::Cyberman::Inhibitor::set(bool is_device_activated)
{
    this->_is_device_active = is_device_activated;
}

bool Mondas::Cyberman::Inhibitor::get(void)
{
    return this->_is_device_active;
}

unsigned int Mondas::Cyberman::getIq(void) const
{
    Mondas::Cyberman::Inhibitor *human_inhibitor = this->_human.getInhibitor();

    if (human_inhibitor || human_inhibitor->get())
        return this->_human.getIq();
    else
        return 0;
}
