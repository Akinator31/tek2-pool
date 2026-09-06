/*
** EPITECH PROJECT, 2026
** FruitUtils
** File description:
** FruitUtils
*/

#pragma once

#include "FruitBox.hpp"
#include "IFruit.hpp"

class FruitUtils {
  public:
    static void sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry);

    static FruitBox** pack(IFruit** fruits, unsigned int boxSize);
    static IFruit** unpack(FruitBox** fruitBoxes);
};
