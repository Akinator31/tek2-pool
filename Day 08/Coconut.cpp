/*
** EPITECH PROJECT, 2026
** Coconut
** File description:
** Coconut
*/

#include "Coconut.hpp"
#include "ANut.hpp"
#include "ostream"

Coconut::Coconut(void) : ANut(new std::string("coconut"), 4, false) {
}

std::ostream& operator<<(std::ostream& stream, const Coconut& coconut) {
    return stream << "{ \"name\": \"" << coconut.getName()
                  << "\", \"vitamins\": " << coconut.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << coconut.isPeeled() << " }";
}

IFruit* Coconut::clone(void) const {
    return new Coconut();
}
