/*
** EPITECH PROJECT, 2026
** FruitBox
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include "IFruit.hpp"
#include <cstddef>
#include <iostream>
#include <vector>

FruitBox::FruitBox(const unsigned int size) {
    this->fifo = std::vector<IFruit*>();
    this->size = size;
}

FruitBox::~FruitBox(void) {
    if (this->fifo.size() == 0)
        return;
    for (IFruit* fruit : this->fifo) {
        if (fruit)
            delete fruit;
    }
}

unsigned int FruitBox::getSize(void) const {
    return this->size;
}

unsigned int FruitBox::nbFruits(void) const {
    return this->fifo.size();
}

bool FruitBox::pushFruit(IFruit* fruit) {
    if (!fruit)
        return false;

    if (this->fifo.size() == size)
        return false;

    for (IFruit* f : this->fifo) {
        if (f == fruit)
            return false;
    }
    this->fifo.push_back(fruit);
    return true;
}

IFruit* FruitBox::popFruit(void) {
    IFruit* result = NULL;

    if (this->fifo.size() == 0)
        return NULL;
    result = this->fifo.at(0);
    this->fifo.erase(this->fifo.begin());
    return result;
}

std::vector<IFruit*> FruitBox::getFifo(void) const {
    return this->fifo;
}

std::ostream& operator<<(std::ostream& stream, const FruitBox& box) {
    stream << "[";

    const std::vector<IFruit*> fifo = box.getFifo();

    if (fifo.empty())
        return stream << "]";

    for (size_t i = 0; i < fifo.size() - 1; i++) {
        if (fifo[i])
            stream << *fifo[i] << ", ";
    }

    if (fifo.back())
        stream << *fifo.back() << "]";

    return stream;
}
