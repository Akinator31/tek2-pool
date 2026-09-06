/*
** EPITECH PROJECT, 2026
** Raspberry
** File description:
** Raspberry
*/

#include "Raspberry.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& stream, const Raspberry& raspberry) {
    return stream << "{ \"name\": \"" << raspberry.getName()
                  << "\", \"vitamins\": " << raspberry.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << raspberry.isPeeled() << " }";
}

IFruit* Raspberry::clone(void) const {
    return new Raspberry();
}
