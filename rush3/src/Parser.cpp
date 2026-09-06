#include "Parser.hpp"
#include "AbstractVM.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

const std::vector<std::string> instructions = {"push",   "pop", "display", "clear", "swap",
                                               "assert", "add", "sub",     "mul",   "div",
                                               "mod",    "mod", "load",    "store", "exit"};

const std::vector<std::string> types = {"int8", "int16", "int32", "int64", "float32", "float64"};

ValueValidator::ValueValidator() {
    checks["int8"] = [](const std::string& val) {
        long long n = std::stoll(val);
        return n >= std::numeric_limits<int8_t>::min() && n <= std::numeric_limits<int8_t>::max();
    };
    checks["int16"] = [](const std::string& val) {
        long long n = std::stoll(val);
        return n >= std::numeric_limits<int16_t>::min() && n <= std::numeric_limits<int16_t>::max();
    };
    checks["int32"] = [](const std::string& val) {
        long long n = std::stoll(val);
        return n >= std::numeric_limits<int32_t>::min() && n <= std::numeric_limits<int32_t>::max();
    };
    checks["int64"] = [](const std::string& val) {
        long long n = std::stoll(val);
        return n >= std::numeric_limits<int64_t>::min() && n <= std::numeric_limits<int64_t>::max();
    };
    checks["float32"] = [](const std::string& val) {
        double n = std::stod(val);
        return n >= std::numeric_limits<float>::lowest() && n <= std::numeric_limits<float>::max();
    };
    checks["float64"] = [](const std::string& val) {
        long double n = std::stod(val);
        return n >= std::numeric_limits<double>::lowest() &&
               n <= std::numeric_limits<double>::max();
    };
}

void ValueValidator::isInBounds(const std::string& type, const std::string& value, size_t line) {
    if (!checks.at(type)(value))
        throw ParsingErrorException(line, "\nToo big value for this type: " + type);
}

Parser::Parser(AbstractVM vm) {
    this->_vm = vm;
}

void Parser::setCommentOnLine(std::string& line) {
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == ';') {
            line.resize(i);
            return;
        }
    }
}

void Parser::isValidInstr(std::string& str) {
    size_t len = instructions.size();

    for (size_t i = 0; i < len; i++) {
        if (str == instructions[i])
            return;
    }
    throw ParsingErrorException(this->_line, "\nInvalid instruction: " + str);
}

void Parser::isValidType(std::string& str) {
    size_t len = types.size();

    for (size_t i = 0; i < len; i++) {
        if (str == types[i])
            return;
    }
    throw ParsingErrorException(this->_line, "\nInvalid type: " + str);
}

static void isValidNumber(std::string& nb, size_t line) {
    try {
        int nbConverted = std::stoi(nb);

        if (nbConverted < 0 || nbConverted > 15)
            throw ParsingErrorException(line, "\nInvalid value: " + nb);
    } catch (...) {
        throw ParsingErrorException(line, "\nInvalid value: " + nb);
    }
}

void Parser::isValidLine(std::string& line) {
    std::stringstream ss(line);
    size_t index = 0;
    std::string word;
    std::string valueType;
    bool isRegCommand = false;

    while (ss >> word) {
        if (index == 0) {
            if (word == "load" || word == "store") {
                index++;
                isRegCommand = true;
                continue;
            }
            this->isValidInstr(word);
        }
        if (index == 1) {
            if (isRegCommand) {
                isValidNumber(word, this->_line);
                index++;
                continue;
            }
            this->isValidType(word);
            valueType = word;
        }
        if (index == 2) {
            ValueValidator v;

            v.isInBounds(valueType, word, this->_line);
        }

        index++;
    }
    if (index > 3 || (isRegCommand && index != 2))
        throw ParsingErrorException(this->_line, "\nToo many arguments.");
}

void Parser::handleLine(std::string& line) {
    std::stringstream ss(line);
    std::string instr;
    std::string word;
    std::string value;

    isValidLine(line);
    ss >> instr;
    if (instr.empty())
        return;
    ss >> word;
    if (instr == "load" || instr == "store")
        this->_vm.execute(instr, "int", word);
    else if (instr == "push" || instr == "assert") {
        ss >> value;
        this->_vm.execute(instr, word, value);
    } else
        this->_vm.execute(instr, std::string(""), std::string(""));
}

void Parser::loop(void) {
    std::string line;

    while (std::getline(std::cin, line)) {
        this->setCommentOnLine(line);
        handleLine(line);
        this->_line++;
    }
}
