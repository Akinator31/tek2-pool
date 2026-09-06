#include "Engine.hpp"
#include "Config/Parser.hpp"
#include "Module/Module.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <clocale>
#include <exception>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <ostream>
#include <sstream>
#include <vector>

Krell::Engine::Engine() {
    this->shape.setOutlineColor(sf::Color::White);
    this->shape.setOutlineThickness(5);
    this->shape.setFillColor(sf::Color::Transparent);
}

void Krell::Engine::apply_modules(std::vector<Krell::IModule*>& modules, sf::Vector2i size,
                                  bool isSfml, int cursor) {
    size.x = size.x / this->cols;
    size.y = size.y / this->rows;

    bool canUpdate = this->clock.getElapsedTime().asMilliseconds() > this->ms;
    if (canUpdate)
        this->clock.restart();

    for (int idx = 0; idx < (int)modules.size(); idx++) {
        auto module = modules[idx];
        int cell_width = module->cols() * size.x;
        int cell_height = module->rows() * size.y;

        try {
            float posX, posY;
            if (isSfml) {
                posX = static_cast<float>(((module->pos().x * size.x) + module->pos().x * 5) + 10);
                posY = static_cast<float>(((module->pos().y * size.y) + module->pos().y * 20)) + 10;
                this->shape.setPosition(posX, posY);
                this->shape.setSize(
                    {static_cast<float>(cell_width), static_cast<float>(cell_height)});
                this->shape.setOutlineColor(idx == cursor ? sf::Color::Red : sf::Color::White);
                this->window.draw(this->shape);
            } else {
                posX = static_cast<float>(module->pos().x * size.x);
                posY = static_cast<float>(module->pos().y * size.y);
                if (idx == cursor) {
                    attron(A_REVERSE);
                    for (int x = (int)posX; x < (int)posX + cell_width; x++) {
                        mvaddch((int)posY, x, ' ');
                        mvaddch((int)posY + cell_height, x, ' ');
                    }
                    for (int y = (int)posY; y <= (int)posY + cell_height; y++) {
                        mvaddch(y, (int)posX, ' ');
                        mvaddch(y, (int)posX + cell_width - 1, ' ');
                    }
                    attroff(A_REVERSE);
                }
            }
            if (canUpdate)
                module->update();
            module->draw({posX, posY},
                         {static_cast<float>(cell_width), static_cast<float>(cell_height)});
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Krell::Engine::runNcurses(int width, int height) {
    bool quit = false;
    int ch;

    this->initNcurses();
    this->ncursesCursor = 0;
    while (!quit) {
        ch = getch();
        if (ch == 'q')
            quit = true;
        if (ch == 's') {
            endwin();
            this->runSfml(width, height);
            return;
        }
        if (ch == 'r')
            this->reloadDashboards();
        if (ch == KEY_RIGHT && !this->ncursesModules.empty())
            this->ncursesCursor = (this->ncursesCursor + 1) % this->ncursesModules.size();
        if (ch == KEY_LEFT && !this->ncursesModules.empty())
            this->ncursesCursor = (this->ncursesCursor - 1 + this->ncursesModules.size()) %
                                  this->ncursesModules.size();
        if ((ch == KEY_DC || ch == 'x') && !this->ncursesModules.empty()) {
            this->ncursesModules.erase(this->ncursesModules.begin() + this->ncursesCursor);
            if (this->ncursesCursor >= (int)this->ncursesModules.size())
                this->ncursesCursor = std::max(0, (int)this->ncursesModules.size() - 1);
        }
        erase();
        apply_modules(this->ncursesModules, {getmaxx(stdscr), getmaxy(stdscr)}, false,
                      this->ncursesCursor);
        refresh();
        napms(this->ms);
    }
    endwin();
}

void Krell::Engine::runSfml(int width, int height) {
    this->initSfml();
    this->sfmlCursor = 0;

    while (this->window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::N) {
                    window.close();
                    this->runNcurses(width, height);
                    return;
                }
                if (event.key.code == sf::Keyboard::R)
                    this->reloadDashboards();
                if (event.key.code == sf::Keyboard::Right && !this->sfmlModules.empty())
                    this->sfmlCursor = (this->sfmlCursor + 1) % this->sfmlModules.size();
                if (event.key.code == sf::Keyboard::Left && !this->sfmlModules.empty())
                    this->sfmlCursor = (this->sfmlCursor - 1 + this->sfmlModules.size()) %
                                       this->sfmlModules.size();
                if ((event.key.code == sf::Keyboard::Delete || event.key.code == sf::Keyboard::X) &&
                    !this->sfmlModules.empty()) {
                    this->sfmlModules.erase(this->sfmlModules.begin() + this->sfmlCursor);
                    if (this->sfmlCursor >= (int)this->sfmlModules.size())
                        this->sfmlCursor = std::max(0, (int)this->sfmlModules.size() - 1);
                }
            }
        }
        window.clear();
        apply_modules(this->sfmlModules, {width, height}, true, this->sfmlCursor);
        window.display();
    }
}

void Krell::Engine::setMs(int ms) {
    if (ms < 1000)
        this->ms = 1000;
    else
        this->ms = ms;
}

void Krell::Engine::initSfml() {
    this->window.create(sf::VideoMode({1920, 1080}), "SFML works!");
}

void Krell::Engine::initNcurses() {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    keypad(stdscr, true);
    if (has_colors()) {
        start_color();
        use_default_colors();
        init_pair(1, COLOR_CYAN, -1);
        init_pair(2, COLOR_GREEN, -1);
        init_pair(3, COLOR_WHITE, -1);
    }
}

void Krell::Engine::addDashboardPath(const std::string& path) {
    this->dashboardPaths.push_back(path);
}

void Krell::Engine::setDefaultDashboards(const std::string& sfml, const std::string& ncurses) {
    this->defaultSfmlDashboard = sfml;
    this->defaultNcursesDashboard = ncurses;
}

void Krell::Engine::clearModules() {
    this->sfmlModules.clear();
    this->ncursesModules.clear();
}

void Krell::Engine::reloadDashboards() {
    clearModules();

    if (this->dashboardPaths.empty()) {
        if (!this->defaultSfmlDashboard.empty()) {
            auto config = parse_dashboard(this->defaultSfmlDashboard);
            if (config.has_value()) {
                for (auto& module : config.value().modules) {
                    if (!this->isRegistered(module.module_name))
                        continue;
                    this->loadWidget(module.module_name);
                    this->getWidget(module.module_name)->setCols(module.cols);
                    this->getWidget(module.module_name)->setRows(module.rows);
                    this->getWidget(module.module_name)
                        ->setPos(sf::Vector2i(module.posx, module.posy));
                }
            }
        }
        if (!this->defaultNcursesDashboard.empty()) {
            auto config = parse_dashboard(this->defaultNcursesDashboard);
            if (config.has_value()) {
                for (auto& module : config.value().modules) {
                    if (!this->isRegistered(module.module_name))
                        continue;
                    this->loadWidget(module.module_name);
                    this->getWidget(module.module_name)->setCols(module.cols);
                    this->getWidget(module.module_name)->setRows(module.rows);
                    this->getWidget(module.module_name)
                        ->setPos(sf::Vector2i(module.posx, module.posy));
                }
            }
        }
        return;
    }

    for (const auto& path : this->dashboardPaths) {
        std::ifstream file(path);
        if (!file.is_open() || file.fail()) {
            std::cerr << "cannot reload " << path << " dashboard" << std::endl;
            continue;
        }
        std::stringstream content;
        content << file.rdbuf();
        auto config = parse_dashboard(content.str());
        if (!config.has_value()) {
            std::cerr << "Invalid syntax in config file: " << path << std::endl;
            continue;
        }
        for (auto& module : config.value().modules) {
            if (!this->isRegistered(module.module_name)) {
                std::cerr << module.module_name << " is not registered" << std::endl;
                continue;
            }
            this->loadWidget(module.module_name);
            this->getWidget(module.module_name)->setCols(module.cols);
            this->getWidget(module.module_name)->setRows(module.rows);
            this->getWidget(module.module_name)->setPos(sf::Vector2i(module.posx, module.posy));
        }
    }
}
