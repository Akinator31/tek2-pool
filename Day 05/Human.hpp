/*
** EPITECH PROJECT, 2026
** Human
** File description:
** Human
*/

#pragma once
#include <string>
#include "Cyberman.hpp"

class Cyberman;

namespace Mondas {
    class Human {
        public:
            Human(std::string name, unsigned int iq, Cyberman::Inhibitor *inhibitor);
            Human(std::string name, unsigned int iq);
            Human(std::string name, Cyberman::Inhibitor *inhibitor);
            Human(std::string name);
            ~Human(void);
            std::string getName(void) const;
            unsigned int getIq(void) const;
            void setIq(unsigned int new_iq);
            void think(void) const;
            void setInhibitor(Mondas::Cyberman::Inhibitor *inhibitor);
            Mondas::Cyberman::Inhibitor *getInhibitor(void);
            const Mondas::Cyberman::Inhibitor *getInhibitor(void) const;
            void deleteInhibitor(void);

        private:
            std::string _name;
            unsigned int _iq = 192;
            Mondas::Cyberman::Inhibitor *_inhibitor = NULL;
    };
}
