#pragma once

#include "fwd.hpp"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

struct AreaChartSerieValue {
    float time;
    float value;
};

using AreaChartSerie = std::vector<AreaChartSerieValue>;

class SfmlAreaChartDisplay {
    sf::VertexArray line = sf::VertexArray(sf::PrimitiveType::LineStrip);

  public:
    using Renderer = sf::RenderWindow&;

    void draw(sf::RenderWindow& window, AreaChartSerie& data, Position pos, Rect rect);
};
