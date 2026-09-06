#include "AreaChart.hpp"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>

void SfmlAreaChartDisplay::draw(sf::RenderWindow& window, AreaChartSerie& data, Position pos,
                                Rect rect) {
    line.clear();
    int step = rect.width / (data.size() - 1);
    for (std::size_t i = 0; i < data.size(); ++i) {
        sf::Vertex point(
            sf::Vertex(sf::Vector2f(pos.x + (i * step), rect.height + (pos.y - data[i].value)),
                       sf::Color::White));
        line.append(point);
    }
    window.draw(line);
}
