#pragma once

#include <map>

#include "IOperand.hpp"
#include <string>

class OperandFactory {
    static IOperand* createInt8(const std::string& value);
    static IOperand* createInt16(const std::string& value);
    static IOperand* createInt32(const std::string& value);
    static IOperand* createInt64(const std::string& value);
    static IOperand* createFloat32(const std::string& value);
    static IOperand* createFloat64(const std::string& value);

    typedef IOperand* (*_func)(const std::string& value);
    static std::map<OperandType, _func> _createTypeOperand;

  public:
    static IOperand* createOperand(OperandType type, const std::string& value);
};
