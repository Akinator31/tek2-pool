#pragma once



#include "../Widgets/charts/TextChart.hpp"
#include "../Widgets/fetcher/Username.hpp"
#include "./Module.hpp"
#include <string>

using SfmlUsernameWidget = Module<std::string, SfmlTextChartDisplay, UsernameFetcher>;
