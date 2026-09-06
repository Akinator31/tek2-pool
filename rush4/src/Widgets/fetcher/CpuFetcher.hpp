#pragma once

#include <array>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>

std::array<ulong, 8> get_values(void);

class CpuUsage {
  private:
    float usage = 0;
    std::array<ulong, 8> oldValue = get_values();

  public:
    std::array<ulong, 8> allCpuUsage() {
        std::array<ulong, 8> new_value = get_values();
        std::array<ulong, 8> results;
        unsigned long total_diff = 0;

        for (int i = 0; i < 8; i++)
            total_diff += new_value[i] - oldValue[i];
        for (int i = 0; i < 8; i++)
            results[i] = (double)(new_value[i] - oldValue[i]) / total_diff * 100;
        oldValue = new_value;
        return results;
    }

    float cpuUsage() {
        auto values = allCpuUsage();
        float result = 0;
        for (int i = 0; i < 8; i++) {
            result += values[i];
        }
        return result / 8;
    }

    float& get() {
        return this->usage;
    }
    void update() {
        this->usage = this->cpuUsage();
        return;
    }
};
