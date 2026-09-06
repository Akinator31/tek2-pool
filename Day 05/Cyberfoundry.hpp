/*
** EPITECH PROJECT, 2026
** Cyberfoundry
** File description:
** Cyberfoundry
*/

#pragma once

#include "Cyberleader.hpp"
#include "Cyberman.hpp"
namespace Mondas {
    class Cyberfoundry {
        public:
            Cyberfoundry(unsigned int &energy);
            ~Cyberfoundry(void);
            Mondas::Cyberman *buildCyberman(Mondas::Human &human);
            Mondas::Cyberleader *buildCyberleader(Mondas::Human &human);
            void recycle(Mondas::Cyberman *&cyberman);
            void recycle(Mondas::Cyberleader *&cyberleader);

        private:
            unsigned int &_energie;
    };
}
