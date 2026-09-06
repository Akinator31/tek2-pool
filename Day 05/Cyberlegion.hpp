/*
** EPITECH PROJECT, 2026
** Cyberleader
** File description:
** Cyberlegion
*/

#include "Cyberfoundry.hpp"
#include "Cyberleader.hpp"
#include "Cyberman.hpp"
#include <vector>
namespace Mondas {
    class Cyberlegion {
        public:
            Cyberlegion(unsigned int &energy);
            ~Cyberlegion(void);
            bool assimilate(Mondas::Human *human);
            Mondas::Cyberleader *getCyberleader(void);
            const Mondas::Cyberleader *getCyberleader(void) const;
            Mondas::Cyberman **getCybermen(void);
            const Mondas::Cyberman *const *getCybermen(void) const;
            unsigned int getSize(void) const;
            unsigned int getIq(void) const;

        private:
            unsigned int _id;
            Mondas::Cyberfoundry *foundry;
            Mondas::Cyberleader *cyberleader;
            std::vector<Cyberman *> cybermen;
    };
}
