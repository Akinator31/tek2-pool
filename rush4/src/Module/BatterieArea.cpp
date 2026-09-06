#include "Module/BatterieArea.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <algorithm>
#include <fstream>
#include <string>

static int getBatteryPercentage() {
    std::ifstream batteryFile("/sys/class/power_supply/BAT0/capacity");

    if (!batteryFile.is_open()) {
        batteryFile.open("/sys/class/power_supply/BAT1/capacity");
    }
    if (batteryFile.is_open()) {
        std::string capacity;
        std::getline(batteryFile, capacity);
        batteryFile.close();
        try {
            return std::stoi(capacity);
        } catch (...) {
            return -1;
        }
    }
    return -1;
}

unsigned char& BatFetcher::get() {
    return this->_bat;
}

void BatFetcher::update() {
    int pct = getBatteryPercentage();
    if (pct < 0)
        pct = 0;
    if (pct > 100)
        pct = 100;
    this->_bat = static_cast<unsigned char>(pct);
}

void SfmlBatterieDisplay::draw(sf::RenderWindow& window, unsigned char& data, Position pos,
                               Rect rect) {
    float x = pos.x;
    float y = pos.y;
    float w = rect.width;
    float h = rect.height;
    if (w <= 4 || h <= 4)
        return;
    const float outlineThick = 4.f;
    sf::RectangleShape outer(sf::Vector2f(w, h));
    outer.setPosition(x, y);
    outer.setFillColor(sf::Color::Transparent);
    outer.setOutlineThickness(outlineThick);
    outer.setOutlineColor(sf::Color::Black);
    const float nubW = std::max(6.f, w * 0.06f);
    const float nubH = std::max(8.f, h * 0.4f);
    sf::RectangleShape nub(sf::Vector2f(nubW, nubH));
    nub.setPosition(x + w - nubW / 2.f, y + (h - nubH) / 2.f);
    nub.setFillColor(sf::Color::Black);
    sf::RectangleShape innerBg(sf::Vector2f(w - 2.f * outlineThick, h - 2.f * outlineThick));
    innerBg.setPosition(x + outlineThick, y + outlineThick);
    innerBg.setFillColor(sf::Color(40, 40, 40));
    float usableW = innerBg.getSize().x - 4.f;
    float usableH = innerBg.getSize().y - 6.f;
    float fillW = std::max(0.f, usableW * (static_cast<float>(data) / 100.f));
    sf::RectangleShape fill(sf::Vector2f(fillW, usableH));
    fill.setPosition(innerBg.getPosition().x + 2.f, innerBg.getPosition().y + 3.f);
    sf::Color fillColor = (data > 66)
                              ? sf::Color(100, 220, 100)
                              : (data > 33 ? sf::Color(255, 180, 60) : sf::Color(220, 80, 80));
    fill.setFillColor(fillColor);
    window.draw(outer);
    window.draw(nub);
    window.draw(innerBg);
    window.draw(fill);
    static sf::Font font;
    static bool loaded = false;
    if (!loaded)
        loaded = font.loadFromFile("assets/unbounded.ttf");
    if (loaded) {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(static_cast<unsigned int>(std::max(10.f, h * 0.18f)));
        text.setFillColor(sf::Color::Black);
        std::string pct = std::to_string(static_cast<int>(data)) + "%";
        text.setString(pct);
        sf::FloatRect tb = text.getLocalBounds();
        float tx = x + w - tb.width - 6.f;
        float ty = y + 4.f;
        text.setPosition(tx, ty);
        window.draw(text);
    }
}

void NcursesBatterieDisplay::draw(WINDOW** winPtr, unsigned char& data, Position pos, Rect rect) {
    WINDOW* win = winPtr ? *winPtr : stdscr;
    if (!win)
        win = stdscr;
    int startx = static_cast<int>(pos.x);
    int starty = static_cast<int>(pos.y);
    int height = static_cast<int>(rect.height);
    int width = static_cast<int>(rect.width);
    if (width < 2 || height < 2)
        return;

    int innerW = width - 2;
    int innerH = height - 2;
    mvwaddch(win, starty, startx, ACS_ULCORNER);
    mvwaddch(win, starty, startx + width - 1, ACS_URCORNER);
    mvwaddch(win, starty + height - 1, startx, ACS_LLCORNER);
    mvwaddch(win, starty + height - 1, startx + width - 1, ACS_LRCORNER);
    mvwhline(win, starty, startx + 1, ACS_HLINE, width - 2);
    mvwhline(win, starty + height - 1, startx + 1, ACS_HLINE, width - 2);
    mvwvline(win, starty + 1, startx, ACS_VLINE, height - 2);
    mvwvline(win, starty + 1, startx + width - 1, ACS_VLINE, height - 2);
    char buf[16];
    std::snprintf(buf, sizeof(buf), "%d%%", static_cast<int>(data));
    std::string pct(buf);
    int pctlen = static_cast<int>(pct.length());
    int pct_x = startx + width - pctlen - 2;
    int pct_y = starty;
    if (pct_x > startx) {
        mvwprintw(win, pct_y, pct_x, "%s", pct.c_str());
    }
    int fillCols = static_cast<int>((innerW * static_cast<int>(data)) / 100);
    for (int i = 0; i < innerW; ++i) {
        chtype ch = (i < fillCols) ? ACS_CKBOARD : ' ';
        for (int j = 0; j < innerH; ++j) {
            if (has_colors())
                wattron(win, COLOR_PAIR(2));
            mvwaddch(win, starty + 1 + j, startx + 1 + i, ch);
            if (has_colors())
                wattroff(win, COLOR_PAIR(2));
        }
    }
}
