/*
** EPITECH PROJECT, 2026
** Cyberleader
** File description:
** Cyberleader
*/

#pragma once

#include "Cyberman.hpp"
namespace Mondas {
    class Human;
    class Cyberleader {
        public:
            Cyberleader(Mondas::Human &human);
            ~Cyberleader(void);
            void upgrade(Mondas::Cyberman &cyberman);
            void upgrade(Mondas::Human &human);
            void upgrade(Mondas::Cyberman::Inhibitor &inhibitor);
            void think(void);
            Mondas::Human *get_human(void);
        private:
            Mondas::Human &_human;
    };
}
