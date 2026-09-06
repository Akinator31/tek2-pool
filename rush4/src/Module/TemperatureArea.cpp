#include "TemperatureArea.hpp"
#include "Widgets/charts/AreaChart.hpp"

AreaChartSerie& FakeSerieFetcher::get() {
    return series;
}

void FakeSerieFetcher::update() {
    return;
}
