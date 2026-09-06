#pragma once

#include "fwd.hpp"
#include <SFML/System/Vector2.hpp>
#include <concepts>

#define Widget(name, metric, display, fetcher)                                                     \
    struct name : public Krell::Module<metric, display, fetcher> {                                 \
        using Krell::Module<metric, display, fetcher>::Module;                                     \
    }

namespace Krell {

template <typename T, typename Metric>
concept Drawable = requires(T& a, Metric& b, Rect rect, Position pos, T::Renderer renderer) {
    typename T::Renderer;
    { a.draw(renderer, b, pos, rect) };
};

template <typename T, typename Metric>
concept DataFetcher = requires(T a, Metric b) {
    { a.get() } -> std::same_as<Metric&>;
    { a.update() };
};

class IModule {
  public:
    virtual ~IModule() = default;
    virtual void draw(Position pos, Rect rect) = 0;
    virtual int cols() const = 0;
    virtual int rows() const = 0;
    virtual void setCols(int cols) = 0;
    virtual void setRows(int rows) = 0;
    virtual sf::Vector2i pos() const = 0;
    virtual void setPos(sf::Vector2i pos) = 0;
    virtual void update() = 0;
};

template <typename Metric, Drawable<Metric> IDisplay, DataFetcher<Metric> DataFetcher>
class Module : public IModule {
    DataFetcher fetcher = DataFetcher();
    IDisplay display = IDisplay();
    IDisplay::Renderer renderer;
    int nbCols = 1;
    int nbRows = 1;
    sf::Vector2i position = {0, 0};

  public:
    using Renderer = IDisplay::Renderer;

    Module(IDisplay::Renderer& renderer) : renderer(renderer) {
    }
    void draw(Position pos, Rect rect) override {
        Metric& metric = this->fetcher.get();
        this->display.draw(this->renderer, metric, pos, rect);
    };
    int cols() const override {
        return this->nbCols;
    };
    int rows() const override {
        return this->nbRows;
    };
    void setCols(int cols) override {
        this->nbCols = cols;
    };
    void setRows(int rows) override {
        this->nbRows = rows;
    };
    sf::Vector2i pos() const override {
        return this->position;
    };
    void setPos(sf::Vector2i pos) override {
        this->position = pos;
    };
    void update() override {
        this->fetcher.update();
    }
};

} // namespace Krell
