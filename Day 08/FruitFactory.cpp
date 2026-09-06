/*
** EPITECH PROJECT, 2026
** FruitFactory
** File description:
** FruitFactory
*/

#include "FruitFactory.hpp"
#include "IFruit.hpp"
#include <vector>

FruitFactory::FruitFactory(void) {
    this->list = new std::vector<IFruit*>;
}

FruitFactory::~FruitFactory(void) {
    for (IFruit* fruit : *this->list) {
        if (fruit)
            delete fruit;
    }
    delete this->list;
}

void FruitFactory::registerFruit(IFruit* fruit) {
    if (!fruit)
        return;
    for (IFruit*& f : *this->list) {
        if (f->getName() == fruit->getName()) {
            delete f;
            f = fruit;
            return;
        }
    }
    this->list->push_back(fruit);
}

void FruitFactory::unregisterFruit(const std::string& name) {
    size_t i = 0;

    for (IFruit* fruit : *this->list) {
        if (fruit->getName() == name) {
            this->list->erase(this->list->begin() + i);
            delete fruit;
            return;
        }
        i++;
    }
}

IFruit* FruitFactory::createFruit(const std::string& name) const {
    for (IFruit*& fruit : *this->list) {
        if (fruit->getName() == name)
            return fruit->clone();
    }
    return NULL;
}
