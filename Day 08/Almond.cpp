/*
** EPITECH PROJECT, 2026
** Lemon
** File description:
** Lemon
*/

#include "Almond.hpp"
#include "IFruit.hpp"
#include <ios>
#include <iostream>
#include <string>

Almond::Almond(void) : ANut(new std::string("almond"), 2, false) {
}

std::ostream& operator<<(std::ostream& stream, const Almond& almond) {
    return stream << "{ \"name\": \"" << almond.getName()
                  << "\", \"vitamins\": " << almond.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << almond.isPeeled() << " }";
}

IFruit* Almond::clone(void) const {
    return new Almond();
}
