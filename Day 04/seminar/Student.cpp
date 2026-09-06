/*
** EPITECH PROJECT, 2026
** seminar
** File description:
** seminar
*/

#include "Student.hpp"
#include <iostream>
#include <variant>

Student::Student(std::string value)
{
    this->name = value;
    std::cout << "Student " << this->name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << this->name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

std::string Student::getName()
{
    return this->name;
}

void Student::updateEnergy(int new_value)
{
    if (this->energy_point == 100)
        return;
    this->energy_point += new_value;
    if (this->energy_point > 100)
        this->energy_point = 100;
}

bool Student::learn(std::string text)
{
    int pos = 0;

    if (this->energy_point < 42) {
        pos = text.find("C++");
        while (pos != std::variant_npos) {
            text.replace(pos, 3, "shit");
            pos = text.find("C++");
        }
        std::cout << "Student " << this->name << ": " << text << std::endl;
        return false;
    }
    this->energy_point -= 42;
    std::cout << "Student " << this->name << ": " << text << std::endl;
    return true;
}

void Student::drink(std::string drink_name)
{
    if (drink_name == "Red Bull") {
        this->updateEnergy(32);
        std::cout << "Student " << this->name << ": Red Bull gives you wings!" << std::endl;
        return;
    }
    if (drink_name == "Monster") {
        this->updateEnergy(64);
        std::cout << "Student " << this->name << ": Unleash The Beast!" << std::endl;
        return;
    }
    this->updateEnergy(1);
    std::cout << "Student " << this->name << ": ah, yes... enslaved moisture." << std::endl;
    return;
}
