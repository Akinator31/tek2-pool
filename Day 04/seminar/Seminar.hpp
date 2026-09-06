/*
** EPITECH PROJECT, 2026
** seminar
** File description:
** seminar
*/

#pragma once
#include <vector>
#include "Dean.hpp"
#include "Student.hpp"
#include "Assistant.hpp"

class Seminar {
    public:
        Seminar();
        void run(void);

        void addDean(Dean *dean);
        void addAssistant(Assistant *assistant);
        void addStudent(Student *student);

        void printAssistants(void);
        void printStudent(void);

        void timeCheckAssistants(void);

    private:
        Dean *dean;
        std::vector<Assistant *> assistants;
        std::vector<Student *> students;
};
