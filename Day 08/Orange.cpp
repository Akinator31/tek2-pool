/*
** EPITECH PROJECT, 2026
** Orange
** File description:
** Orange
*/

#include "Orange.hpp"
#include <iostream>

Orange::Orange(void) : ACitrus(new std::string("orange"), 7, false) {
}

std::ostream& operator<<(std::ostream& stream, const Orange& orange) {
    return stream << "{ \"name\": \"" << orange.getName()
                  << "\", \"vitamins\": " << orange.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << orange.isPeeled() << " }";
}

IFruit* Orange::clone(void) const {
    return new Orange();
}
