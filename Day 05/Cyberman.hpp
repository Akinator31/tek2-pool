/*
** EPITECH PROJECT, 2026
** Cyberman
** File description:
** Cyberaman
*/

#pragma once
#include <string>

std::string convert_name(std::string human_name);

namespace Mondas {
    class Human;
    class Cyberman {
        public:
            Cyberman(Human &_human);
            ~Cyberman();
            Human& getHuman(void);
            const Human& getHuman(void) const;
            void think(void) const;
            unsigned int getIq(void) const;

            class Inhibitor {
                public:
                    Inhibitor() = default;
                    ~Inhibitor() = default;
                    void set(bool is_device_active);
                    bool get(void);

                private:
                    bool _is_device_active = false;
            };

        private:
            Human &_human;
    };
}
