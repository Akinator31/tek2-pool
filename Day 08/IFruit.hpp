/*
** EPITECH PROJECT, 2026
** IFruit
** File description:
** IFruit
*/

#pragma once

#include <string>

class IFruit {
  public:
    virtual ~IFruit(void) = default;

    virtual unsigned int getVitamins(void) const = 0;
    virtual std::string getName(void) const = 0;
    virtual bool isPeeled(void) const = 0;
    virtual void peel(void) = 0;
    virtual IFruit* clone(void) const = 0;
};

std::ostream& operator<<(std::ostream& stream, const IFruit& fruit);
