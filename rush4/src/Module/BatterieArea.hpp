#pragma once

#include "Module/Module.hpp"
#include <SFML/Window.hpp>
#include <ncurses.h>

namespace sf {
class RenderWindow;
}

class BatFetcher {
    unsigned char _bat = 0;

  public:
    unsigned char& get();
    void update();
};

class SfmlBatterieDisplay {
  public:
    using Renderer = sf::RenderWindow&;
    void draw(sf::RenderWindow& window, unsigned char& data, Position pos, Rect rect);
};

class NcursesBatterieDisplay {
  public:
    using Renderer = WINDOW**;
    void draw(WINDOW** win, unsigned char& data, Position pos, Rect rect);
};

Widget(SfmlBatterieArea, unsigned char, SfmlBatterieDisplay, BatFetcher);
Widget(NcursesBatterieArea, unsigned char, NcursesBatterieDisplay, BatFetcher);
