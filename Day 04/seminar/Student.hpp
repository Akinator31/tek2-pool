/*
** EPITECH PROJECT, 2026
** seminar
** File description:
** seminar
*/

#pragma once

#include <string>

class Student {
    private:
        std::string name;
        int energy_point = 100;
        void updateEnergy(int new_value);

    public:
        Student(std::string value);
        ~Student();

        bool learn(std::string text);
        void drink(std::string drink_name);
        std::string getName();
};
