#pragma once

#include "Module/Module.hpp"
#include "Widgets/HashMapSeries.hpp"

#define PATH_HOSTNAME "/proc/sys/kernel/hostname"
#define PATH_OS_RELEASE "/etc/os-release"

class SystemInfoFetcher {
    HashMapSerie serie = {};

  public:
    HashMapSerie& get();
    void update();
    std::string get_hostname(void);
    std::string get_username(void);
    std::string get_operating_system(void);
    std::string get_kernel(void);
};

Widget(SfmlSystemInfo, HashMapSerie, SfmlHaspMapDisplay, SystemInfoFetcher);
Widget(NcursesSystemInfo, HashMapSerie, NcursesHaspMapDisplay, SystemInfoFetcher);
