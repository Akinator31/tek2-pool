#include "Scanner.hpp"
#include <cctype>
#include <cstring>
#include <functional>
#include <string>

Scanner::Scanner(const char* content) : _content(content), _pos(0), _len(strlen(content)) {
}

bool Scanner::isDone() const {
    return this->_pos >= this->_len;
}

void Scanner::advance() {
    this->_pos += 1;
}

char Scanner::pop() {
    char c = this->_content[this->_pos];
    this->_pos += 1;
    return c;
}

char Scanner::peek() const {
    return this->_content[this->_pos];
}

void Scanner::skip_while(std::function<bool(char)> cmp) {
    while (!this->isDone() && cmp(this->peek())) {
        this->advance();
    }
}

void Scanner::skip_whitespace() {
    return this->skip_while(static_cast<int (*)(int)>(std::isspace));
}

std::string Scanner::take_while(std::function<bool(char)> cmp) {
    std::string str;
    while (!this->isDone() && cmp(this->peek())) {
        str.push_back(this->peek());
        this->advance();
    }
    return str;
}

bool Scanner::expect(char c) const {
    return this->peek() == c;
}

void Scanner::save() {
    this->_save = this->_pos;
}

void Scanner::restore() {
    this->_pos = this->_save;
}

bool Scanner::expect(const std::string& str) {
    this->save();
    for (char c : str) {
        if (this->expect(c)) {
            this->advance();
            continue;
        } else {
            this->restore();
            return false;
        }
    }
    return true;
}
