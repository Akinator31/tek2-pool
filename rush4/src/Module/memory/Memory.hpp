#pragma once
#include "Module/BatterieArea.hpp"
#include "Module/Module.hpp"
#include <string>
#include <vector>

#define PATH_MEM "/proc/meminfo"

class Memory {
  protected:
    float _total;
    float _free;
    float _used;
    std::vector<std::string> _mem_infos;
    void loadMemInfo();
};

class Mem : public Memory {
    unsigned char percent = 0;

  protected:
    float _buff_cache;

  public:
    unsigned char& get() {
        this->percent = (unsigned char)((this->_used / this->_total) * 100.);
        return this->percent;
    };
    void update();
};

class MemSwap : public Memory {
    unsigned char percent = 0;

  protected:
    float _availabe;

  public:
    unsigned char& get() {
        if (this->_total == 0)
            this->percent = 0;
        else
            this->percent = (unsigned char)((this->_used / this->_total) * 100.);
        return this->percent;
    };
    void update();
};

Widget(SfmlMemSwap, unsigned char, SfmlBatterieDisplay, MemSwap);
Widget(SfmlMem, unsigned char, SfmlBatterieDisplay, Mem);
Widget(NcursesMemSwap, unsigned char, NcursesBatterieDisplay, MemSwap);
Widget(NcursesMem, unsigned char, NcursesBatterieDisplay, Mem);
