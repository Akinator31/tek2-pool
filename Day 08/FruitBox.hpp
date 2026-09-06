/*
** EPITECH PROJECT, 2026
** FruitBox
** File description:
** FruitBox
*/

#pragma once

#include "IFruit.hpp"
#include <ostream>
#include <vector>

class FruitBox {
  public:
    FruitBox(const unsigned int size);
    ~FruitBox(void);
    unsigned int getSize(void) const;
    unsigned int nbFruits() const;
    bool pushFruit(IFruit*);
    IFruit* popFruit(void);
    std::vector<IFruit*> getFifo(void) const;

  private:
    std::vector<IFruit*> fifo;
    unsigned int size;
};

std::ostream& operator<<(std::ostream& stream, const FruitBox& box);
