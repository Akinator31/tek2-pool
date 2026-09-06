#pragma once

#include "fwd.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <ncurses.h>
#include <string>

using HashMapSerie = std::map<std::string, std::string>;

class SfmlHaspMapDisplay {
    sf::Text text = sf::Text();
    sf::Font font;

  public:
    using Renderer = sf::RenderWindow&;
    SfmlHaspMapDisplay();

    void draw(sf::RenderWindow& window, HashMapSerie& data, Position pos, Rect rect);
};

class NcursesHaspMapDisplay {
    int attributes;

  public:
    using Renderer = WINDOW**;
    NcursesHaspMapDisplay();

    void draw(WINDOW** win, HashMapSerie& data, Position pos, Rect rect);
};
