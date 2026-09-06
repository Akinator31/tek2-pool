#pragma once

#include "../Module/Module.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cassert>
#include <map>
#include <string>

class WidgetFactory {
    std::map<std::string, Krell::IModule*> _modules;

  public:
    ~WidgetFactory() {
        for (auto& [name, module] : _modules)
            delete module;
    }
    void registerWidget(std::string name, Krell::IModule* widget);
    Krell::IModule* loadWidget(std::string name);
    bool isRegistered(std::string name);
};
