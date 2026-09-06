/*
** EPITECH PROJECT, 2026
** Peasent
** File description:
** Peasent
*/

#pragma once
#include "ICharacter.hpp"
#include <string>

class Peasant : public virtual ICharacter {
  public:
    Peasant(const std::string& name, int power);
    ~Peasant(void);
    const std::string& getName(void) const override;

    int getPower(void) const override;
    int getHp(void) const override;

    void setPower(int new_power) override;
    void setHp(int new_hp) override;

    virtual int attack(void) override;
    virtual int special(void) override;
    virtual void rest(void) override;
    void damage(int damage) override;

  private:
    const std::string& _name;
    int _power;
    int _health;
};
