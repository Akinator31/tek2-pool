#include "Config/Parser.hpp"
#include "Engine.hpp"
#include "Module/BatterieArea.hpp"
#include "Module/NetworkArea.hpp"
#include "Module/SystemInfo.hpp"
#include "Module/TemperatureArea.hpp"
#include "Module/memory/Memory.hpp"
#include "Widgets/fetcher/CpuCoreFetcher.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <string>

static const char* defaultSfmlDashboard = "COLS=10 "
                                          "ROWS=10 "
                                          "SfmlTemperatureArea(0, 0, 4, 1) "
                                          "SfmlNetworkArea(0, 2, 3, 1) "
                                          "SfmlMemSwap(0, 1, 3, 1) "
                                          "SfmlSystemInfo(4, 0, 2, 1) "
                                          "SfmlCpuInfo(0, 4, 1, 1) ";

static const char* defaultNcursesDashboard = "COLS=10 "
                                             "ROWS=10 "
                                             "NcursesNetworkArea(0, 0, 4, 1) "
                                             "NcursesMemSwap(4, 0, 3, 1) "
                                             "NcursesBatterieArea(7, 0, 3, 1) ";

void loadDashboard(Krell::Engine& engine, DashboardConfig config) {
    for (auto module : config.modules) {
        if (!engine.isRegistered(module.module_name)) {
            std::cerr << module.module_name << " is not registered" << std::endl;
            continue;
        }
        engine.loadWidget(module.module_name);
        engine.getWidget(module.module_name)->setCols(module.cols);
        engine.getWidget(module.module_name)->setRows(module.rows);
        engine.getWidget(module.module_name)->setPos(sf::Vector2i(module.posx, module.posy));
    }
}

void loadConfig(Krell::Engine& engine, std::string path) {
    std::ifstream file(path);

    if (!file.is_open() || file.fail()) {
        std::cerr << "cannot load " << path << " dashboard" << std::endl;
        return;
    }

    std::stringstream content;
    content << file.rdbuf();

    auto config = parse_dashboard(content.str());
    if (!config.has_value()) {
        std::cerr << "Invalid syntax in config file : " << path << std::endl;
        return;
    }

    loadDashboard(engine, config.value());
}

template <typename... All> void registers(Krell::Engine& engine) {
    (engine.registerWidget<All>(), ...);
}

int main(int argc, char** argv) {
    bool runWithSfml = true;
    Krell::Engine engine;

    registers<SfmlTemperatureArea, SfmlNetworkArea, SfmlSystemInfo, SfmlBatterieArea, SfmlMemSwap,
              SfmlCpuInfo, SfmlMem, NcursesMem, NcursesMemSwap, NcursesNetworkArea,
              NcursesBatterieArea, NcursesSystemInfo>(engine);

    int i = 1;
    if (argc >= 2) {
        std::string ncurseFlag = "--ncurse";
        if (ncurseFlag.compare(argv[1]) == 0) {
            runWithSfml = false;
            i++;
        }

        for (; i < argc; i++) {
            engine.addDashboardPath(argv[i]);
            loadConfig(engine, argv[i]);
        }
    }

    engine.setDefaultDashboards(defaultSfmlDashboard, defaultNcursesDashboard);

    if (i == 1 || (i == 2 && !runWithSfml)) {
        loadDashboard(engine, parse_dashboard(defaultSfmlDashboard).value());
        loadDashboard(engine, parse_dashboard(defaultNcursesDashboard).value());
    }

    if (runWithSfml)
        engine.runSfml(1920, 1080);
    else
        engine.runNcurses(1920, 1080);

    return 0;
}
