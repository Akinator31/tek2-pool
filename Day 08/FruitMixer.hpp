/*
** EPITECH PROJECT, 2026
** FruitMixer
** File description:
** FruitMixer
*/

#pragma once

#include "IFruitMixer.hpp"

class FruitMixer : public IFruitMixer {
    IBlade* blade;

  public:
    FruitMixer(void);
    ~FruitMixer() = default;

    void setBlade(IBlade* blade) override;
    unsigned int mixFruits(FruitBox& box) const override;
};
