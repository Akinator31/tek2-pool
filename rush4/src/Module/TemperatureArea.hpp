#pragma once

#include "Module/Module.hpp"
#include "Widgets/charts/AreaChart.hpp"

class FakeSerieFetcher {
    AreaChartSerie series = {AreaChartSerieValue{
                                 .time = 0,
                                 .value = 10,
                             },
                             AreaChartSerieValue{.time = 1, .value = 40},
                             AreaChartSerieValue{.time = 2, .value = 30},
                             AreaChartSerieValue{.time = 3, .value = 30}};

  public:
    AreaChartSerie& get();
    void update();
};



Widget(SfmlTemperatureArea, AreaChartSerie, SfmlAreaChartDisplay, FakeSerieFetcher);
