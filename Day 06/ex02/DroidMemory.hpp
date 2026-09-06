/*
** EPITECH PROJECT, 2026
** DroidMemory
** File description:
** DroidMemory
*/

#pragma once

#include <cstddef>
#include <cstdlib>
#include <ostream>

class DroidMemory {
    public:
        DroidMemory() = default;
        DroidMemory(const DroidMemory &droid): _fingerprint(droid._fingerprint), _exp(droid._exp) {};

        DroidMemory& operator=(const DroidMemory &other) = default;
        DroidMemory& operator<<(const DroidMemory &mem);
        DroidMemory& operator>>(DroidMemory &mem) const;
        DroidMemory& operator+=(const DroidMemory &mem);
        DroidMemory& operator+=(size_t exp);
        DroidMemory operator+(const DroidMemory &droid) const;
        DroidMemory operator+(const size_t exp) const;

        bool operator==(const DroidMemory &mem) const;
        bool operator!=(const DroidMemory &mem) const;
        bool operator<(const DroidMemory &mem) const;
        bool operator>(const DroidMemory &mem) const;
        bool operator<=(const DroidMemory &mem) const;
        bool operator>=(const DroidMemory &mem) const;

        bool operator==(const size_t &exp) const;
        bool operator!=(const size_t &exp) const;
        bool operator<(const size_t &exp) const;
        bool operator>(const size_t &exp) const;
        bool operator<=(const size_t &exp) const;
        bool operator>=(const size_t &exp) const;

        void setFingerprint(const size_t new_fingerprint);
        void setExp(const size_t exp);

        size_t getFingerprint(void) const;
        size_t getExp(void) const;

    private:
        std::size_t _fingerprint = rand();
        std::size_t _exp = 0;
};

std::ostream &operator<<(std::ostream &stream, const DroidMemory &mem);
