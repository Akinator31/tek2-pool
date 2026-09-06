/*
** EPITECH PROJECT, 2026
** Grapefruit
** File description:
** Grapefruit
*/

#include "Grapefruit.hpp"

std::ostream& operator<<(std::ostream& stream, Grapefruit& grapefruit) {
    return stream << "{ \"name\": \"" << grapefruit.getName()
                  << "\", \"vitamins\": " << grapefruit.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << grapefruit.isPeeled() << " }";
}

IFruit* Grapefruit::clone(void) const {
    return new Grapefruit();
}
