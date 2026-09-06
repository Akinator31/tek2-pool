#pragma once

#include <cstdint>
#include <functional>
#include <optional>
#include <sstream>
#include <string>

class Scanner {
    const char* _content;
    uint64_t _save;
    uint64_t _pos;
    uint64_t _len;

  public:
    Scanner(const char* content);

    char pop();
    char peek() const;
    void save();
    void restore();
    bool expect(char c) const;
    bool expect(const std::string& str);
    void advance();
    std::string take_while(std::function<bool(char)> cmp);

    std::string take_rest() {
        return std::string(&this->_content[this->_pos]);
    }
    void skip_while(std::function<bool(char)> cmp);
    void skip_whitespace();
    template <typename T> std::optional<T> take_value() {
        std::string content =
            this->take_while([](char c) { return std::isdigit(c) || c == '-' || c == '.'; });
        if (content.empty()) {
            return std::nullopt;
        }
        std::stringstream stream(content);
        T result;
        stream >> result;
        if (stream.fail()) {
            return std::nullopt;
        }
        return std::make_optional(result);
    }

    bool isDone() const;
};
