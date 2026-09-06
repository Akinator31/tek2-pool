#include "CpuFetcher.hpp"
#include "fwd.hpp"
#include <string>

std::array<ulong, 8> get_values(void) {
    std::array<ulong, 8> values;
    std::string content = read_file("/proc/stat");
    const char* buffer = content.c_str();

    if (sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu", values.data(), &values[1], &values[2],
               &values[3], &values[4], &values[5], &values[6], &values[7]) != 8) {
        return {};
    }
    return values;
}
