#pragma once

#include "Module/Module.hpp"
#include "Widgets/WidgetFactory.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <ncurses.h>
#include <string>
#include <type_traits>
#include <vector>

template <typename T> std::string type_name() {
    std::string func = __PRETTY_FUNCTION__;
    func.erase(0, 29);
    func.erase(func.length() - 1, 1);
    return func;
}

namespace Krell {

template <typename T> consteval bool IsSfml() {
    return std::is_same<typename T::Renderer, sf::RenderWindow&>();
}

class Engine {
    int cols = 10;
    int rows = 10;
    sf::Clock clock = sf::Clock();
    sf::RenderWindow window;
    std::vector<Krell::IModule*> sfmlModules;
    std::vector<Krell::IModule*> ncursesModules;
    sf::RectangleShape shape = sf::RectangleShape();
    int ms = 100;
    WidgetFactory factory;
    WINDOW** ncursesStdscr = &stdscr;
    std::vector<std::string> dashboardPaths;
    std::string defaultSfmlDashboard;
    std::string defaultNcursesDashboard;
    int ncursesCursor = 0;
    int sfmlCursor = 0;

    void apply_modules(std::vector<Krell::IModule*>& modules, sf::Vector2i size, bool isSfml,
                       int cursor = -1);

  public:
    Engine();
    ~Engine() = default;
    void runSfml(int width, int height);
    void runNcurses(int width, int height);
    void initSfml();
    void initNcurses();
    void setMs(int ms);
    void addDashboardPath(const std::string& path);
    void setDefaultDashboards(const std::string& sfml, const std::string& ncurses);
    void reloadDashboards();
    void clearModules();

    template <typename T> void registerWidget() {
        if constexpr (IsSfml<T>()) {
            this->factory.registerWidget(type_name<T>(), new T(this->window));
        } else {
            this->factory.registerWidget(type_name<T>(), new T(this->ncursesStdscr));
        }
    }

    template <typename T> T* getWidget() {
        std::string name = type_name<T>();

        return dynamic_cast<T*>(this->factory.loadWidget(name));
    }

    Krell::IModule* getWidget(std::string name) {
        return this->factory.loadWidget(name);
    }

    bool isRegistered(std::string name) {
        return this->factory.isRegistered(name);
    }

    template <typename T> void loadWidget() {
        std::string name = type_name<T>();
        if constexpr (IsSfml<T>()) {
            this->sfmlModules.push_back(this->factory.loadWidget(name));
        } else {
            this->ncursesModules.push_back(this->factory.loadWidget(name));
        }
    }

    void loadWidget(std::string name) {
        if (name.starts_with("Sfml")) {
            this->sfmlModules.push_back(this->factory.loadWidget(name));
        } else {
            this->ncursesModules.push_back(this->factory.loadWidget(name));
        }
    }
};

} // namespace Krell
