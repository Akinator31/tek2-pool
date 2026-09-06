#pragma once

#include "Module/Module.hpp"
#include "Widgets/charts/AreaChart.hpp"
#include <ncurses.h>

#include <cstdint>
#include <cstddef>
#include <string>

inline constexpr std::size_t NET_DELTA_AVG = 5;
inline constexpr std::uint64_t NET_UPDATE_INTERVAL_MS = 1000ULL;
inline constexpr std::size_t NET_MAX_SAMPLES = 60;

struct NetworkMetric {
    std::string ip;
    AreaChartSerie inbound;
    AreaChartSerie outbound;
};

class NetworkFetcher {
    std::string iface{};
    std::uint64_t last_rx = 0;
    std::uint64_t last_tx = 0;
    long long last_time_ms = 0;
    NetworkMetric metric;

    bool read_iface_bytes(const std::string& ifn, std::uint64_t& rx, std::uint64_t& tx);
    void update_ip(const std::string& ifn);
    bool detect_iface();
    bool sample_iface(std::uint64_t& rx, std::uint64_t& tx);
    bool should_update(long long tms) const;
    void record_sample(long long tms, double avg_in, double avg_out);
    void trim_samples();
public:
    NetworkMetric& get();
    void update();
};

class SfmlNetworkDisplay {
public:
    using Renderer = sf::RenderWindow&;
    void draw(sf::RenderWindow& window, NetworkMetric& data, Position pos, Rect rect);
};

class NcursesNetworkDisplay {
    float maxIn = 1.0f;
    float maxOut = 1.0f;
public:
    using Renderer = WINDOW**;
    void draw(WINDOW** win, NetworkMetric& data, Position pos, Rect rect);
};

Widget(SfmlNetworkArea, NetworkMetric, SfmlNetworkDisplay, NetworkFetcher);
Widget(NcursesNetworkArea, NetworkMetric, NcursesNetworkDisplay, NetworkFetcher);
