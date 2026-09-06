#include "fwd.hpp"
#include <fstream>
#include <sstream>
#include <string>

std::string read_file(std::string fileName) {
    std::ifstream file(fileName);

    std::stringstream content;
    content << file.rdbuf();
    return content.str();
}
