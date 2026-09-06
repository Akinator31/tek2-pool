#pragma once


#include <string>

class UsernameFetcher {
    std::string username = "suleyman";
  public:
    std::string& get() {
        return this->username;
    }
    void update() {
        return;
    }
};
