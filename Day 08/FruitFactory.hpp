/*
** EPITECH PROJECT, 2026
** FruitFactory
** File description:
** FruitFactory
*/

#pragma once

#include "IFruit.hpp"
#include <string>
#include <vector>
class FruitFactory {
    std::vector<IFruit*>* list;

  public:
    FruitFactory(void);
    ~FruitFactory(void);
    void registerFruit(IFruit* fruit);
    void unregisterFruit(const std::string& name);
    IFruit* createFruit(const std::string& name) const;
};
