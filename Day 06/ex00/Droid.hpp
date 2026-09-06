/*
** EPITECH PROJECT, 2026
** Droid
** File description:
** Droid
*/

#pragma once
#include <cstddef>
#include <ostream>
#include <string>

class Droid {
    public:
        Droid(std::string serial_number);
        Droid(void);
        Droid(const Droid &droid);
        ~Droid(void);
        Droid& operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
        Droid &operator<<(size_t &energy);

        const std::string getId(void) const;
        size_t getEnergy(void) const;
        size_t getAttack(void) const;
        size_t getToughness(void) const;
        const std::string *getStatus(void) const;
        std::string *getStatus(void);

        void setId(const std::string new_id);
        void setEnergy(const size_t new_energy);
        void setStatus(std::string *new_status);

    private:
        std::string _id;
        size_t _energy = 50;
        const size_t _attack = 25;
        const size_t _toughness = 15;
        std::string *_status = new std::string("Standing by");
};

std::ostream &operator<<(std::ostream &s, const Droid &droid);
