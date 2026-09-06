/*
** EPITECH PROJECT, 2026
** seminar
** File description:
** seminar
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "Assistant.hpp"

Assistant::Assistant(int id)
{
    this->id = id;
    std::cout << "Assistant " << this->id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << this->id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

int Assistant::getId()
{
    return this->id;
}

void Assistant::giveDrink(Student *student, std::string drink_name)
{
    if (!student)
        return;
    std::cout << "Assistant " << this->id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(drink_name);
}

std::string Assistant::readDrink(std::string student_name)
{
    std::string file_name = student_name;
    file_name.append(".drink");
    std::ifstream file = std::ifstream(file_name);

    if (file.fail() || !file.is_open())
        return "";
    std::stringstream content;
    content << file.rdbuf();
    std::string drink = content.str();

    if (std::filesystem::remove(file_name))
        std::cout << "Assistant " << this->id << ": " << student_name << " needs a " << drink << " *sip coffee*" << std::endl;
    file.close();
    return drink;
}

void Assistant::helpStudent(Student *student)
{
    if (!student)
        return;
    std::string drink = this->readDrink(student->getName());

    if (drink.empty()) {
        std::cout << "Assistant " << this->id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
        return;
    }
    this->giveDrink(student, drink);
}

void Assistant::timeCheck(void)
{
    if (!this->is_working) {
        this->is_working = true;
        std::cout << "Assistant " << this->id << ": Time to teach some serious business *sip coffee*" << std::endl;
        return;
    }
    this->is_working = false;
    std::cout << "Assistant " << this->id << ": Enough teaching for today *sip coffee*" << std::endl;
    return;
}
