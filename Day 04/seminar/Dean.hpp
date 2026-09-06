/*
** EPITECH PROJECT, 2026
** dean
** File description:
** dean
*/

#pragma once
#include <string>
#include "Student.hpp"

class Dean {
    public:
        Dean(std::string name);
        ~Dean();
        void teachStudent(Student *student, std::string lesson_name);
        void timeCheck(void);
        std::string getName();

    private:
        std::string name;
        bool is_working = 0;
};
