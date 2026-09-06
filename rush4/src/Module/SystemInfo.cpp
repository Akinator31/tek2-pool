#include "SystemInfo.hpp"
#include "Exceptions.hpp"
#include "Widgets/HashMapSeries.hpp"
#include "pwd.h"
#include <array>
#include <cstdio>
#include <fstream>
#include <memory>
#include <string>
#include <unistd.h>

std::string my_exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

    if (!pipe) {
        throw LoadException(cmd);
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string SystemInfoFetcher::get_hostname(void) {
    std::ifstream hostname_file(PATH_HOSTNAME);
    std::string result = "";

    if (!hostname_file)
        throw LoadException(PATH_HOSTNAME);
    if (hostname_file.is_open()) {
        hostname_file >> result;
    }
    hostname_file.close();
    return result;
}

std::string SystemInfoFetcher::get_username() {
    uid_t uid = getuid();
    struct passwd* pw = getpwuid(uid);
    if (pw)
        return std::string(pw->pw_name);
    return std::string("");
}

std::string SystemInfoFetcher::get_operating_system(void) {
    std::ifstream os_file(PATH_OS_RELEASE);
    std::string result = "";

    if (!os_file)
        throw LoadException(PATH_OS_RELEASE);
    if (os_file.is_open()) {
        os_file >> result;
    }

    size_t pos = result.find("=") + 1;

    if (pos == std::string::npos) {
        return "";
    }

    os_file.close();
    return result.substr(pos + 1);
}

std::string SystemInfoFetcher::get_kernel(void) {
    std::string result = my_exec("uname -r");
    result.erase(result.length() - 1, 1);
    return result;
}

HashMapSerie& SystemInfoFetcher::get() {
    this->serie["Username"] = this->get_username();
    this->serie["Hostname"] = this->get_hostname();
    this->serie["Op. sys."] = this->get_operating_system();
    this->serie["Kernel"] = this->get_kernel();
    return serie;
}

void SystemInfoFetcher::update() {
    return;
}
