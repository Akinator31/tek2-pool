#pragma once

#include "IOperand.hpp"
#include "OperandType.hpp"
#include <array>
#include <map>
#include <stack>
#include <string>

class AbstractVM {
    std::stack<IOperand*> _stack;

    typedef void (AbstractVM::*func)(IOperand* operand);

    std::map<std::string, func> _instructions;

    std::array<IOperand*, 16> _registers = {};

    void _push(IOperand* value);
    void _pop(IOperand* value);
    void _display(IOperand* value);
    void _clear(IOperand* value);
    void _swap(IOperand* value);
    void _assert(IOperand* value);
    void _add(IOperand* value);
    void _sub(IOperand* value);
    void _mul(IOperand* value);
    void _div(IOperand* value);
    void _mod(IOperand* value);
    void _load(IOperand* value);
    void _store(IOperand* value);
    void _exit(IOperand* value);

  public:
    AbstractVM(void);
    void execute(std::string instruction, std::string type, std::string value);
    OperandType getTypeFromString(std::string type);
};
