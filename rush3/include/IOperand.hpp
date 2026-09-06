#pragma once

#include "OperandType.hpp"
#include <string>

class IOperand {
  public:
    virtual std::string toString() const = 0;
    virtual OperandType getType() const = 0;

    virtual IOperand* operator+(const IOperand& rhs) const = 0;
    virtual IOperand* operator-(const IOperand& rhs) const = 0;
    virtual IOperand* operator*(const IOperand& rhs) const = 0;
    virtual IOperand* operator/(const IOperand& rhs) const = 0;
    virtual IOperand* operator%(const IOperand& rhs) const = 0;
    virtual bool operator==(const IOperand& rhs) const = 0;
    virtual bool operator==(const int rhs) const = 0;

    virtual ~IOperand() = default;
};
