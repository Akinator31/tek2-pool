/*
** EPITECH PROJECT, 2026
** IFruit
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const IFruit& fruit) {
    return stream << "{ \"name\": \"" << fruit.getName()
                  << "\", \"vitamins\": " << fruit.getVitamins()
                  << ", \"peeled\": " << std::boolalpha << fruit.isPeeled() << " }";
}
