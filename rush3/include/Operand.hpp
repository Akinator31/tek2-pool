#pragma once

#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "OperandType.hpp"
#include <cmath>
#include <string>

template <typename T> class Operand : public IOperand {
  private:
    T _value;
    OperandType _type;

  public:
    Operand(T value, OperandType type) : _value(value), _type(type) {};
    virtual ~Operand() {};

    std::string toString() const override {
        return std::to_string(_value);
    }

    OperandType getType() const override {
        return _type;
    }

    IOperand* operator+(const IOperand& rhs) const override {
        OperandType result_type = std::max(this->getType(), rhs.getType());

        double val1 = static_cast<double>(this->_value);
        double val2 = std::stod(rhs.toString());

        double result = val1 + val2;

        return OperandFactory::createOperand(result_type, std::to_string(result));
    }

    IOperand* operator-(const IOperand& rhs) const override {
        OperandType result_type = std::max(this->getType(), rhs.getType());

        double val1 = static_cast<double>(this->_value);
        double val2 = std::stod(rhs.toString());

        double result = val1 - val2;

        return OperandFactory::createOperand(result_type, std::to_string(result));
    }

    IOperand* operator*(const IOperand& rhs) const override {
        OperandType result_type = std::max(this->getType(), rhs.getType());

        double val1 = static_cast<double>(this->_value);
        double val2 = std::stod(rhs.toString());

        double result = val1 * val2;

        return OperandFactory::createOperand(result_type, std::to_string(result));
    }

    IOperand* operator/(const IOperand& rhs) const override {
        OperandType result_type = std::max(this->getType(), rhs.getType());

        double val1 = static_cast<double>(this->_value);
        double val2 = std::stod(rhs.toString());

        double result = val1 / val2;

        return OperandFactory::createOperand(result_type, std::to_string(result));
    }

    IOperand* operator%(const IOperand& rhs) const override {
        OperandType result_type = std::max(this->getType(), rhs.getType());

        double val1 = static_cast<double>(this->_value);
        double val2 = std::stod(rhs.toString());

        double result = std::fmod(val1, val2);

        return OperandFactory::createOperand(result_type, std::to_string(result));
    }

    bool operator==(const IOperand& rhs) const override {
        double val1 = static_cast<double>(this->_value);
        double val2 = std::stod(rhs.toString());

        return val1 == val2;
    }

    bool operator==(const int rhs) const override {
        double val1 = static_cast<double>(this->_value);

        return val1 == rhs;
    }
};
