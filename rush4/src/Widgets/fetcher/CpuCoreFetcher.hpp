#pragma once

#include "CpuFetcher.hpp"
#include "Module/Module.hpp"
#include "Widgets/HashMapSeries.hpp"
#include <format>
#include <map>
#include <string>
#include <sys/types.h>
#include <thread>

class CpuCoreFetcher {
    float cpuCount = std::thread::hardware_concurrency();

  public:
    float& get() {
        return this->cpuCount;
    }
    void update() {
        return;
    }
};

class CpuInfoFetcher {
    CpuCoreFetcher core;
    CpuUsage usage;
    std::map<std::string, std::string> value;

  public:
    std::map<std::string, std::string>& get() {
        return this->value;
    }
    void update() {
        this->core.update();
        this->usage.update();
        std::string core = std::format("{}", this->core.get());
        std::string usage = std::format("{}", this->usage.get());

        this->value["threads"] = core;
        this->value["usage"] = usage;
        return;
    }
};

Widget(SfmlCpuInfo, HashMapSerie, SfmlHaspMapDisplay, CpuInfoFetcher);
