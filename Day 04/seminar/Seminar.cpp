/*
** EPITECH PROJECT, 2026
** Seminar
** File description:
** Seminar
*/

#include <iostream>
#include "Seminar.hpp"

Seminar::Seminar()
{
    this->dean = NULL;
    this->assistants = {};
    this->students = {};
}

void Seminar::printAssistants(void)
{
    std::cout << "Teaching assistants: ";
    Assistant *last = NULL;

    for (Assistant *a: this->assistants) {
        if (this->assistants.at(this->assistants.size() - 1) == a) {
            last = a;
            break;
        }
        std::cout << a->getId() << ", ";
    }
    std::cout << last->getId() << std::endl;
}

void Seminar::printStudent(void)
{
    std::cout << "Students: ";
    Student *last = NULL;

    for (Student *s: this->students) {
        if (this->students.at(this->students.size() - 1) == s) {
            last = s;
            break;
        }
        std::cout << s->getName() << ", ";
    }
    std::cout << last->getName() << std::endl;
}

void Seminar::timeCheckAssistants(void)
{
    for (Assistant *a: this->assistants) {
        a->timeCheck();
    }
}

void Seminar::run()
{
    if (!this->dean || this->assistants.empty() || this->students.empty()) {
        std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
        return;
    }
    std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
    std::cout << "Dean of Studies: " << this->dean->getName() << std::endl;
    this->printAssistants();
    this->printStudent();
    this->dean->timeCheck();
    this->timeCheckAssistants();
    int assistant_selector = 0;

    for (size_t i = 0; i < this->students.size(); i++) {

        for (Student *s: this->students) {
            Assistant *actual = this->assistants.at(assistant_selector);
            this->dean->teachStudent(s, "I'm learning C++!");
            if (assistant_selector == this->assistants.size() - 1)
                assistant_selector = 0;
            else
                assistant_selector += 1;
            actual->helpStudent(s);
        }
    }

    this->dean->timeCheck();
    this->timeCheckAssistants();
}

void Seminar::addDean(Dean *dean)
{
    if (!dean)
        return;
    if (this->dean) {
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
        return;
    }
    std::cout << "Seminar: Dean " << dean->getName() << " is here." << std::endl;
    this->dean = dean;
}

void Seminar::addAssistant(Assistant *assistant)
{
    if (!assistant)
        return;
    for (Assistant *a: this->assistants) {
        if (a == assistant) {
            std::cout << "Seminar: Assistant " << assistant->getId() << " is already registered." << std::endl;
            return;
        }
    }
    if (this->assistants.size() == 2) {
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
        return;
    }
    std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team." << std::endl;
    this->assistants.push_back(assistant);
}

void Seminar::addStudent(Student *student)
{
    if (!student)
        return;
    for (Student *s: this->students) {
        if (s == student) {
            std::cout << "Seminar: Student " << student->getName() << " is already registered." << std::endl;
            return;
        }
    }
    if (this->students.size() == 5) {
        std::cout << "Seminar: There is only room for five Students." << std::endl;
        return;
    }
    std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
    this->students.push_back(student);
}
