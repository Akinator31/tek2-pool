/*
** EPITECH PROJECT, 2026
** Strawberry
** File description:
** Strawberry
*/

#include "Strawberry.hpp"
#include <ios>
#include <ostream>

Strawberry::Strawberry(void) : ABerry(new std::string("strawberry"), 6, true) {
}

std::ostream& operator<<(std::ostream& stream, const Strawberry& strawberry) {
    return stream << "{ \"name\": \"" << strawberry.getName()
                  << "\", \"vitamins\": " << strawberry.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << strawberry.isPeeled() << " }";
}

IFruit* Strawberry::clone(void) const {
    return new Strawberry();
}
