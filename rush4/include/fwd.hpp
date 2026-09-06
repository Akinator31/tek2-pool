#pragma once

#include <string>
struct Position {
    float x, y;
};

struct Rect {
    float width, height;
};

std::string read_file(std::string fileName);
