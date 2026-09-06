/*
** EPITECH PROJECT, 2026
** FruitMixer
** File description:
** FruitMixer
*/

#include "FruitMixer.hpp"
#include "IFruit.hpp"
#include "IFruitMixer.hpp"
#include <cstddef>
#include <iostream>

FruitMixer::FruitMixer(void) {
    this->blade = NULL;
}

void FruitMixer::setBlade(IFruitMixer::IBlade* blade) {
    this->blade = blade;
}

unsigned int FruitMixer::mixFruits(FruitBox& box) const {
    int nb_fruit = 0;
    unsigned int result = 0;
    IFruit* temp = NULL;
    unsigned int fruit_vitamins = 0;

    if (!this->blade) {
        std::cout << "mixer has no blade" << std::endl;
        return 0;
    }
    nb_fruit = box.nbFruits();
    for (int i = 0; i < nb_fruit; i++) {
        temp = box.popFruit();
        fruit_vitamins = (*this->blade)(*temp);
        if (fruit_vitamins > 0 && temp->isPeeled()) {
            result += fruit_vitamins;
            delete temp;
        } else {
            box.pushFruit(temp);
        }
    }
    return result;
}
