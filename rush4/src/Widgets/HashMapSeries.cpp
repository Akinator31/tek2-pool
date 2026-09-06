#include "Widgets/HashMapSeries.hpp"
#include "HashMapSeries.hpp"
#include "fwd.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>

SfmlHaspMapDisplay::SfmlHaspMapDisplay(void) {
    this->font.loadFromFile("assets/unbounded.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(25);
}

void SfmlHaspMapDisplay::draw(sf::RenderWindow& window, HashMapSerie& data, Position pos, Rect) {
    int index_x = 5;
    int index_y = 0;

    this->text.setFillColor(sf::Color::White);
    for (const auto& [key, value] : data) {
        this->text.setPosition(pos.x + index_x, pos.y + index_y);
        this->text.setString(key + " : " + value);
        window.draw(this->text);
        index_y += 25;
    }
}

NcursesHaspMapDisplay::NcursesHaspMapDisplay() {
    attributes = COLOR_PAIR(1) | A_BOLD;
}

void NcursesHaspMapDisplay::draw(WINDOW** winPtr, HashMapSerie& data, Position pos, Rect rect) {
    WINDOW* win = winPtr ? *winPtr : stdscr;
    if (!win)
        win = stdscr;

    int startx = static_cast<int>(pos.x);
    int starty = static_cast<int>(pos.y);
    int height = static_cast<int>(rect.height);
    int width = static_cast<int>(rect.width);

    if (width <= 2 || height <= 2)
        return;

    mvwaddch(win, starty, startx, ACS_ULCORNER);
    mvwaddch(win, starty, startx + width - 1, ACS_URCORNER);
    mvwaddch(win, starty + height - 1, startx, ACS_LLCORNER);
    mvwaddch(win, starty + height - 1, startx + width - 1, ACS_LRCORNER);

    mvwhline(win, starty, startx + 1, ACS_HLINE, width - 2);
    mvwhline(win, starty + height - 1, startx + 1, ACS_HLINE, width - 2);
    mvwvline(win, starty + 1, startx, ACS_VLINE, height - 2);
    mvwvline(win, starty + 1, startx + width - 1, ACS_VLINE, height - 2);

    std::string title = " SYSTEM INFO ";
    if (width > (int)title.length() + 2) {
        mvwprintw(win, starty, startx + 2, "%s", title.c_str());
    }

    int innerX = startx + 1;
    int innerY = starty + 1;
    int innerH = height - 2;
    int innerW = width - 2;

    int currentLine = 0;

    if (has_colors())
        wattron(win, COLOR_PAIR(1));

    for (auto const& [key, value] : data) {
        if (currentLine >= innerH)
            break;
        char buffer[256];

        snprintf(buffer, sizeof(buffer), "%s: %s", key.c_str(), value.c_str());
        mvwprintw(win, innerY + currentLine, innerX, "%.*s", innerW, buffer);
        currentLine++;
    }
    if (has_colors())
        wattroff(win, COLOR_PAIR(1));
}
