/*
** EPITECH PROJECT, 2026
** Lemon
** File description:
** Lemon
*/

#include "Lemon.hpp"
#include "ACitrus.hpp"

Lemon::Lemon(void) : ACitrus(new std::string("lemon"), 4, false) {
}

std::ostream& operator<<(std::ostream& stream, Lemon& lemon) {
    return stream << "{ \"name\": \"" << lemon.getName()
                  << "\", \"vitamins\": " << lemon.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << lemon.isPeeled() << " }";
}

IFruit* Lemon::clone(void) const {
    return new Lemon();
}
