#include "WidgetFactory.hpp"
#include "../Module/Module.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cassert>
#include <map>
#include <string>

void WidgetFactory::registerWidget(std::string name, Krell::IModule* widget) {
    assert(!this->_modules.contains(name) && "widget already registered");
    this->_modules[name] = widget;
}

Krell::IModule* WidgetFactory::loadWidget(std::string name) {
    if (this->_modules.contains(name)) {
        return this->_modules[name];
    }
    return nullptr;
}

bool WidgetFactory::isRegistered(std::string name) {
    return this->_modules.contains(name);
}
