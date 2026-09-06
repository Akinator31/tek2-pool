/*
** EPITECH PROJECT, 2026
** seminar
** File description:
** seminar
*/

#pragma once

#include "Student.hpp"

class Assistant {
    private:
        int id;
        bool is_working = 0;
    
    public:
        Assistant(int id);
        ~Assistant(void);
        void giveDrink(Student *student, std::string drink_name);
        std::string readDrink(std::string student_name);
        void helpStudent(Student *student);
        void timeCheck(void);
        int getId(void);
};