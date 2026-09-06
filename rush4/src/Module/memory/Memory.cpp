#include "Memory.hpp"
#include "Exceptions.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Memory::loadMemInfo() {
    std::ifstream memInfos(PATH_MEM);
    std::string word;

    if (!memInfos) {
        throw LoadException(PATH_MEM);
        return;
    }
    this->_mem_infos.clear();
    if (memInfos.is_open()) {
        while (memInfos >> word)
            this->_mem_infos.push_back(word);
    }
    memInfos.close();
}

void Mem::update() {
    loadMemInfo();
    if (this->_mem_infos.size() < 77) {
        throw MemoryException();
        return;
    }
    this->_total = (std::atof(this->_mem_infos[1].c_str()) / 1024.0) / 1000.0;
    this->_free = (std::atof(this->_mem_infos[4].c_str()) / 1024.0) / 1000.0;
    this->_used = this->_total - ((std::atof(this->_mem_infos[7].c_str()) / 1024.0) / 1000.0);
    this->_buff_cache = (atof(this->_mem_infos[10].c_str()) + atof(this->_mem_infos[13].c_str()) +
                         atof(this->_mem_infos[76].c_str())) /
                        1024.0 / 1000.0;
}

void MemSwap::update() {
    loadMemInfo();
    if (this->_mem_infos.size() < 75) {
        throw MemoryException();
        return;
    }
    this->_total = (std::atof(this->_mem_infos[43].c_str()) / 1024.0) / 1000.0;
    this->_free = (std::atof(this->_mem_infos[46].c_str()) / 1024.0) / 1000.0;
    this->_used = this->_total - this->_free;
    this->_availabe = (std::atof(this->_mem_infos[7].c_str()) / 1024.0);
}
