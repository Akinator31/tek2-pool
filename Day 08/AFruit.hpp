/*
** EPITECH PROJECT, 2026
** AFruit
** File description:
** AFruit
*/

#pragma once

#include "IFruit.hpp"

class AFruit : public IFruit {
  protected:
    bool _0;
    unsigned int vitamins;
    std::string* name;
    bool isFruitPeeled = false;

  public:
    AFruit(std::string* name, unsigned int vitamins, bool isFruitPeeled);
    virtual ~AFruit(void);

    unsigned int getVitamins(void) const override;
    std::string getName(void) const override;
    bool isPeeled(void) const override;
    void peel(void) override;
};
