#pragma once

#include "fwd.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>


class SfmlTextChartDisplay {
    sf::Text txt = sf::Text();

    public:
    using Renderer = sf::RenderWindow&;
    SfmlTextChartDisplay() {
        this->txt.setFillColor(sf::Color::White);
        this->txt.setCharacterSize(34);
    }

    void draw(sf::RenderWindow& window, std::string&, Position pos, Rect) {
        this->txt.setPosition(pos.x, pos.y);
        window.draw(this->txt);
    }
};
