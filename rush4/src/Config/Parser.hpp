#pragma once


#include <optional>
#include <string>
#include <vector>

struct ModuleConfig {
    std::string module_name;
    int cols;
    int rows;
    int posx;
    int posy;
};


struct DashboardConfig {
    std::vector<ModuleConfig> modules;
    int rows;
    int cols;
};

std::optional<DashboardConfig> parse_dashboard(std::string content);
