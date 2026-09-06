#include "AbstractVM.hpp"
#include "Exceptions.hpp"
#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "OperandType.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

AbstractVM::AbstractVM() {
    this->_instructions["push"] = &AbstractVM::_push;
    this->_instructions["pop"] = &AbstractVM::_pop;
    this->_instructions["display"] = &AbstractVM::_display;
    this->_instructions["clear"] = &AbstractVM::_clear;
    this->_instructions["swap"] = &AbstractVM::_swap;
    this->_instructions["assert"] = &AbstractVM::_assert;
    this->_instructions["add"] = &AbstractVM::_add;
    this->_instructions["sub"] = &AbstractVM::_sub;
    this->_instructions["mul"] = &AbstractVM::_mul;
    this->_instructions["div"] = &AbstractVM::_div;
    this->_instructions["mod"] = &AbstractVM::_mod;
    this->_instructions["load"] = &AbstractVM::_load;
    this->_instructions["store"] = &AbstractVM::_store;
    this->_instructions["exit"] = &AbstractVM::_exit;
}

void AbstractVM::_push(__attribute((unused)) IOperand* value) {
    this->_stack.push(value);
}

void AbstractVM::_pop(__attribute((unused)) IOperand* value) {
    if (this->_stack.empty()) {
        throw PopException();
    }
    this->_stack.pop();
}

void AbstractVM::_display(__attribute((unused)) IOperand* value) {
    if (!this->_stack.empty()) {
        if (this->_stack.top()->getType() == OperandType::Float32) {
            float result = stof(this->_stack.top()->toString());
            std::cout << std::fixed << std::setprecision(7) << result << std::endl;
            return;
        }
        if (this->_stack.top()->getType() == OperandType::Float64) {
            double result = stod(this->_stack.top()->toString());
            std::cout << std::fixed << std::setprecision(15) << result << std::endl;
            return;
        }
        std::cout << this->_stack.top()->toString() << std::endl;
    }
}

void AbstractVM::_clear(__attribute((unused)) IOperand* value) {
    while (!this->_stack.empty()) {
        delete this->_stack.top();
        this->_stack.pop();
    }
}

void AbstractVM::_swap(__attribute((unused)) IOperand* value) {
    if (this->_stack.size() >= 2) {
        IOperand* value1 = this->_stack.top();
        this->_stack.pop();
        IOperand* value2 = this->_stack.top();
        this->_stack.pop();

        this->_stack.push(value1);
        this->_stack.push(value2);
    } else {
        throw StackSizeException();
    }
}

void AbstractVM::_assert(IOperand* value) {
    if (this->_stack.empty())
        throw AssertException();

    if (*this->_stack.top() != *value)
        throw AssertException();

    if (this->_stack.top()->getType() != value->getType())
        throw AssertException();
}

void AbstractVM::_add(__attribute((unused)) IOperand* value) {
    if (this->_stack.size() < 2)
        throw StackSizeException();
    IOperand* value1 = this->_stack.top();
    this->_stack.pop();
    IOperand* value2 = this->_stack.top();
    this->_stack.pop();

    this->_stack.push(*value1 + *value2);
}

void AbstractVM::_sub(__attribute((unused)) IOperand* value) {
    if (this->_stack.size() < 2)
        throw StackSizeException();
    IOperand* value1 = this->_stack.top();
    this->_stack.pop();
    IOperand* value2 = this->_stack.top();
    this->_stack.pop();

    this->_stack.push(*value2 - *value1);
}

void AbstractVM::_mul(__attribute((unused)) IOperand* value) {
    if (this->_stack.size() < 2)
        throw StackSizeException();
    IOperand* value1 = this->_stack.top();
    this->_stack.pop();
    IOperand* value2 = this->_stack.top();
    this->_stack.pop();

    this->_stack.push(*value1 * *value2);
}

void AbstractVM::_div(__attribute((unused)) IOperand* value) {
    if (this->_stack.size() < 2)
        throw StackSizeException();
    IOperand* value1 = this->_stack.top();
    this->_stack.pop();
    IOperand* value2 = this->_stack.top();
    this->_stack.pop();

    if (*value1 == 0) {
        throw DivisionException();
    }

    this->_stack.push(*value2 / *value1);
}

void AbstractVM::_mod(__attribute((unused)) IOperand* value) {
    if (this->_stack.size() < 2)
        throw StackSizeException();
    IOperand* value1 = this->_stack.top();
    this->_stack.pop();
    IOperand* value2 = this->_stack.top();
    this->_stack.pop();

    if (*value1 == 0) {
        throw DivisionException();
    }

    this->_stack.push(*value2 % *value1);
}

void AbstractVM::_load(IOperand* value) {
    int index = std::stoi(value->toString());

    if (!this->_registers[index])
        throw LoadException();
    this->_stack.push(this->_registers[index]);
    this->_registers[index] = NULL;
}

void AbstractVM::_store(IOperand* value) {
    if (!this->_stack.empty()) {
        int index = std::stoi(value->toString());
        IOperand* value_to_store = this->_stack.top();

        this->_stack.pop();
        this->_registers[index] = value_to_store;
    } else {
        throw StackSizeException();
    }
}

void AbstractVM::_exit(__attribute((unused)) IOperand* value) {
    while (!this->_stack.empty()) {
        delete this->_stack.top();
        this->_stack.pop();
    }
    exit(0);
}

OperandType AbstractVM::getTypeFromString(std::string type) {
    if (type == "int8")
        return OperandType::Int8;
    if (type == "int16")
        return OperandType::Int16;
    if (type == "int32")
        return OperandType::Int32;
    if (type == "int64")
        return OperandType::Int64;
    if (type == "float32")
        return OperandType::Float32;
    return OperandType::Float64;
}

void AbstractVM::execute(std::string instruction, std::string type, std::string value) {
    IOperand* operand_type = NULL;

    if (!type.empty()) {
        operand_type = OperandFactory::createOperand(this->getTypeFromString(type), value);

        (this->*_instructions[instruction])(operand_type);
    } else {
        (this->*_instructions[instruction])(NULL);
    }
}
