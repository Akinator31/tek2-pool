/*
** EPITECH PROJECT, 2026
** BloodOrange
** File description:
** BloodOrange
*/

#include "BloodOrange.hpp"

BloodOrange::BloodOrange(void) : Orange() {
    if (this->name)
        delete this->name;
    this->name = new std::string("blood orange");
    this->vitamins = 6;
}

std::ostream& operator<<(std::ostream& stream, const BloodOrange& bloodorange) {
    return stream << "{ \"name\": \"" << bloodorange.getName()
                  << "\", \"vitamins\": " << bloodorange.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << bloodorange.isPeeled() << " }";
}

IFruit* BloodOrange::clone(void) const {
    return new BloodOrange();
}
