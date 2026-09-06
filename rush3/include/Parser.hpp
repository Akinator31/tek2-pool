#pragma once

#include "AbstractVM.hpp"
#include <functional>

class Parser {
    AbstractVM _vm;
    size_t _line = 1;
    void setCommentOnLine(std::string& line);
    void handleLine(std::string& line);
    void isValidLine(std::string& line);
    void isValidInstr(std::string& str);
    void isValidType(std::string& str);

  public:
    Parser(AbstractVM vm);

    void loop(void);
};

class ValueValidator {
    using CheckFunc = std::function<bool(const std::string&)>;

  private:
    std::map<std::string, CheckFunc> checks;

  public:
    ValueValidator();
    void isInBounds(const std::string& type, const std::string& value, size_t line);
};
