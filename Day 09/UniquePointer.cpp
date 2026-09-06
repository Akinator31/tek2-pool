/*
** EPITECH PROJECT, 2026
** UniquePointer
** File description:
** UniquePointer
*/

#include "UniquePointer.hpp"
#include "IObject.hpp"

UniquePointer::UniquePointer(IObject* object) : _pointer(object) {
}

UniquePointer::~UniquePointer(void) {
    if (this->_pointer)
        delete this->_pointer;
}

void UniquePointer::operator=(IObject* object) {
    if (this->_pointer)
        delete this->_pointer;
    this->_pointer = object;
}

void UniquePointer::reset(void) {
    if (this->_pointer)
        delete this->_pointer;
    this->_pointer = NULL;
}

void UniquePointer::reset(IObject* object) {
    this->operator=(object);
}

IObject* UniquePointer::operator->(void) const {
    return this->_pointer;
}

IObject& UniquePointer::operator*(void) const {
    return *this->_pointer;
}

void UniquePointer::swap(UniquePointer& ptr) {
    IObject* temp = this->_pointer;

    this->_pointer = ptr._pointer;
    ptr._pointer = temp;
}
