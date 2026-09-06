/*
** EPITECH PROJECT, 2026
** dean
** File description:
** dean
*/

#include <iostream>
#include <fstream>
#include <array>
#include "Dean.hpp"

Dean::Dean(std::string name)
{
    this->name = name;
    std::cout << "Dean " << this->name << ": I'm Dean " << this->name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean(void)
{
    std::cout << "Dean " << this->name << ": Time to go home." << std::endl;
}

std::string Dean::getName(void)
{
    return this->name;
}

void Dean::teachStudent(Student *student, std::string lesson_name)
{
    std::array<std::string, 5> drinks = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};

    if (!student->learn(lesson_name)) {
        std::cout << "Dean " <<this->name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;
        std::string file_name = student->getName();
        file_name.append(".drink");

        std::ofstream file(file_name);
        file << drinks[std::rand() % 5];
        file.close();
    }
}

void Dean::timeCheck(void)
{
    if (!this->is_working) {
        std::cout << "Dean " << this->getName() << ": Where is everyone?" << std::endl;
        this->is_working = 1;
    } else {
        std::cout << "Dean " << this->getName() << ": Don't forget to close the windows when you leave." << std::endl;
        this->is_working = 0;
    }
}
