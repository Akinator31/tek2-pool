#include "NetworkArea.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <algorithm>
#include <arpa/inet.h>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <ifaddrs.h>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <sys/types.h>

static long long now_ms() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

bool NetworkFetcher::read_iface_bytes(const std::string& ifn, std::uint64_t& rx,
                                      std::uint64_t& tx) {
    std::ifstream file("/proc/net/dev");
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line);
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        if (!(iss >> name))
            continue;
        if (!name.empty() && name.back() == ':')
            name.pop_back();

        std::uint64_t r = 0, t = 0;
        if (!(iss >> r))
            continue;
        for (int i = 0; i < 7; ++i) {
            std::uint64_t tmp;
            if (!(iss >> tmp))
                tmp = 0;
        }
        if (!(iss >> t))
            t = 0;

        if (ifn.empty()) {
            if (name != "lo") {
                rx = r;
                tx = t;
                return true;
            }
        } else if (name == ifn) {
            rx = r;
            tx = t;
            return true;
        }
    }

    return false;
}

void NetworkFetcher::update_ip(const std::string& ifn) {
    struct ifaddrs* ifaddr;
    if (getifaddrs(&ifaddr) == -1)
        return;
    for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr)
            continue;
        if (ifn != ifa->ifa_name)
            continue;
        if (ifa->ifa_addr->sa_family == AF_INET) {
            char host[INET_ADDRSTRLEN];
            void* addr = &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, addr, host, INET_ADDRSTRLEN);
            metric.ip = std::string(host);
            break;
        }
    }
    freeifaddrs(ifaddr);
}

NetworkMetric& NetworkFetcher::get() {
    return this->metric;
}

void NetworkFetcher::update() {
    if (!detect_iface())
        return;
    std::uint64_t rx = 0, tx = 0;
    if (!sample_iface(rx, tx))
        return;
    const long long tms = now_ms();
    if (!should_update(tms))
        return;
    if (this->last_time_ms == 0) {
        this->last_rx = rx;
        this->last_tx = tx;
        this->last_time_ms = tms;
        this->metric.inbound.clear();
        this->metric.outbound.clear();
        return;
    }
    const double dt = (tms - this->last_time_ms) / 1000.0;
    if (dt <= 0.0)
        return;
    std::uint64_t drx = (rx >= this->last_rx) ? (rx - this->last_rx) : 0;
    std::uint64_t dtx = (tx >= this->last_tx) ? (tx - this->last_tx) : 0;
    const double rx_per_s = static_cast<double>(drx) / dt;
    const double tx_per_s = static_cast<double>(dtx) / dt;
    double sum_in = rx_per_s;
    int cnt_in = 1;
    for (int i = static_cast<int>(this->metric.inbound.size()) - 1;
         i >= 0 && cnt_in < static_cast<int>(NET_DELTA_AVG); --i) {
        sum_in += this->metric.inbound[i].value;
        ++cnt_in;
    }
    const double avg_in = sum_in / cnt_in;
    double sum_out = tx_per_s;
    int cnt_out = 1;
    for (int i = static_cast<int>(this->metric.outbound.size()) - 1;
         i >= 0 && cnt_out < static_cast<int>(NET_DELTA_AVG); --i) {
        sum_out += this->metric.outbound[i].value;
        ++cnt_out;
    }
    const double avg_out = sum_out / cnt_out;
    record_sample(tms, avg_in, avg_out);
    this->last_rx = rx;
    this->last_tx = tx;
    this->last_time_ms = tms;
    if (this->metric.ip.empty())
        update_ip(this->iface);
}

bool NetworkFetcher::detect_iface() {
    if (!this->iface.empty())
        return true;
    std::ifstream f("/proc/net/dev");
    if (!f.is_open())
        return false;
    std::string line;
    std::getline(f, line);
    std::getline(f, line);
    while (std::getline(f, line)) {
        std::istringstream iss(line);
        std::string name;
        if (!(iss >> name))
            continue;
        if (!name.empty() && name.back() == ':')
            name.pop_back();
        if (name != "lo") {
            this->iface = name;
            return true;
        }
    }
    return false;
}

bool NetworkFetcher::sample_iface(std::uint64_t& rx, std::uint64_t& tx) {
    return read_iface_bytes(this->iface, rx, tx);
}

bool NetworkFetcher::should_update(long long tms) const {
    if (this->last_time_ms == 0)
        return true;
    return (tms - this->last_time_ms) >= static_cast<long long>(NET_UPDATE_INTERVAL_MS);
}

void NetworkFetcher::record_sample(long long tms, double avg_in, double avg_out) {
    AreaChartSerieValue inVal{static_cast<float>(tms / 1000.0), static_cast<float>(avg_in)};
    AreaChartSerieValue outVal{static_cast<float>(tms / 1000.0), static_cast<float>(avg_out)};
    this->metric.inbound.push_back(inVal);
    this->metric.outbound.push_back(outVal);
    trim_samples();
}

void NetworkFetcher::trim_samples() {
    if (this->metric.inbound.size() > NET_MAX_SAMPLES)
        this->metric.inbound.erase(this->metric.inbound.begin(),
                                   this->metric.inbound.begin() +
                                       (this->metric.inbound.size() - NET_MAX_SAMPLES));
    if (this->metric.outbound.size() > NET_MAX_SAMPLES)
        this->metric.outbound.erase(this->metric.outbound.begin(),
                                    this->metric.outbound.begin() +
                                        (this->metric.outbound.size() - NET_MAX_SAMPLES));
}

void SfmlNetworkDisplay::draw(sf::RenderWindow& window, NetworkMetric& data, Position pos,
                              Rect rect) {
    sf::VertexArray inLine(sf::PrimitiveType::LineStrip);
    sf::VertexArray outLine(sf::PrimitiveType::LineStrip);
    float maxv = 1.0f;
    for (auto& v : data.inbound)
        maxv = std::max(maxv, v.value);
    for (auto& v : data.outbound)
        maxv = std::max(maxv, v.value);
    auto appendSeries = [&](AreaChartSerie& series, sf::VertexArray& arr, sf::Color color) {
        for (std::size_t i = 0; i < series.size(); ++i) {
            float x = pos.x + (i * (rect.width / (float)std::max<size_t>(1, series.size() - 1)));
            float normalized = series[i].value / maxv;
            float y = pos.y + rect.height - (normalized * rect.height);
            arr.append(sf::Vertex(sf::Vector2f(x, y), color));
        }
    };
    appendSeries(data.inbound, inLine, sf::Color::White);
    appendSeries(data.outbound, outLine, sf::Color::Green);
    window.draw(inLine);
    window.draw(outLine);
    static sf::Font font;
    static bool fontLoaded = false;
    if (!fontLoaded) {
        fontLoaded = font.loadFromFile("assets/unbounded.ttf");
    }
    if (fontLoaded) {
        const std::string ipstr =
            data.ip.empty() ? std::string("Interface: None") : (std::string("IP: ") + data.ip);
        const float lastIn = data.inbound.empty() ? 0.0f : data.inbound.back().value;
        const float lastOut = data.outbound.empty() ? 0.0f : data.outbound.back().value;
        char buf[128];
        std::snprintf(buf, sizeof(buf), "%s  In: %.0f B/s  Out: %.0f B/s", ipstr.c_str(), lastIn,
                      lastOut);
        sf::Text text;
        text.setFont(font);
        text.setString(buf);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);
        text.setPosition(pos.x + 4.f, pos.y + 120.f);
        window.draw(text);
    }
}

void NcursesNetworkDisplay::draw(WINDOW** winPtr, NetworkMetric& data, Position pos, Rect rect) {
    WINDOW* win = winPtr ? *winPtr : stdscr;
    int x = static_cast<int>(pos.x), y = static_cast<int>(pos.y);
    int h = static_cast<int>(rect.height) - 1, w = static_cast<int>(rect.width);
    if (w < 4 || h < 2)
        return;

    maxIn *= 0.995f;
    maxOut *= 0.995f;
    for (auto& v : data.inbound)
        maxIn = std::max(maxIn, v.value);
    for (auto& v : data.outbound)
        maxOut = std::max(maxOut, v.value);
    if (maxIn < 100)
        maxIn = 100;
    if (maxOut < 100)
        maxOut = 100;

    auto drawBars = [&](AreaChartSerie& s, int color, int ox, int bw, float mv) {
        int n = std::min((int)s.size(), bw);
        int start = (int)s.size() - n;
        if (has_colors())
            wattron(win, COLOR_PAIR(color));
        for (int i = 0; i < n; i++) {
            int col = x + ox + (bw - n) + i;
            int barH = static_cast<int>((s[start + i].value / mv) * h);
            for (int r = 0; r < barH; ++r)
                mvwaddch(win, y + h - r, col, '|');
        }
        if (has_colors())
            wattroff(win, COLOR_PAIR(color));
    };

    int half = (w - 2) / 2;
    if (!data.inbound.empty())
        drawBars(data.inbound, 1, 1, half, maxIn);
    if (!data.outbound.empty())
        drawBars(data.outbound, 2, 1 + half, half, maxOut);

    float lastIn = data.inbound.empty() ? 0 : data.inbound.back().value;
    float lastOut = data.outbound.empty() ? 0 : data.outbound.back().value;
    char buf[64];
    std::snprintf(buf, sizeof(buf), "%s I:%.0f O:%.0f", data.ip.empty() ? "?" : data.ip.c_str(),
                  lastIn, lastOut);
    if (has_colors())
        wattron(win, COLOR_PAIR(3));
    mvwprintw(win, y + h + 1, x + 1, "%.*s", w - 2, buf);
    if (has_colors())
        wattroff(win, COLOR_PAIR(3));
}
