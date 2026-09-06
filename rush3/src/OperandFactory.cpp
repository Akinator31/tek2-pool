#include "OperandFactory.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"

std::map<OperandType, OperandFactory::_func> OperandFactory::_createTypeOperand = {
    {Int8, &OperandFactory::createInt8},       {Int16, &OperandFactory::createInt16},
    {Int32, &OperandFactory::createInt32},     {Int64, &OperandFactory::createInt64},
    {Float32, &OperandFactory::createFloat32}, {Float64, &OperandFactory::createFloat64}};

IOperand* OperandFactory::createOperand(OperandType type, const std::string& value) {
    return _createTypeOperand[type](value);
}

IOperand* OperandFactory::createInt8(const std::string& value) {
    return new Operand<int8_t>(static_cast<int8_t>(std::stoi(value)), Int8);
}

IOperand* OperandFactory::createInt16(const std::string& value) {
    return new Operand<int16_t>(static_cast<int16_t>(std::stoi(value)), Int16);
}

IOperand* OperandFactory::createInt32(const std::string& value) {
    return new Operand<int32_t>(std::stoi(value), Int32);
}

IOperand* OperandFactory::createInt64(const std::string& value) {
    return new Operand<int64_t>(static_cast<int64_t>(std::stol(value)), Int64);
}

IOperand* OperandFactory::createFloat32(const std::string& value) {
    return new Operand<float_t>(std::stof(value), Float32);
}

IOperand* OperandFactory::createFloat64(const std::string& value) {
    return new Operand<double_t>(std::stod(value), Float64);
}
