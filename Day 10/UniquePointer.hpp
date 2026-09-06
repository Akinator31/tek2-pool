/*
** EPITECH PROJECT, 2026
** UniquePointer
** File description:
** UniquePointer
*/

#pragma once

#include <cstddef>

template <typename T> class UniquePointer {
    T* _pointer = NULL;

  public:
    UniquePointer(void) = default;

    UniquePointer(T* object) : _pointer(object) {};

    UniquePointer(UniquePointer& uniqueptr) = delete;

    ~UniquePointer(void) {
        if (this->_pointer)
            delete this->_pointer;
    }

    void operator=(T* object) {
        if (this->_pointer)
            delete this->_pointer;
        this->_pointer = object;
    }

    void operator=(UniquePointer) = delete;

    void reset(void) {
        if (this->_pointer)
            delete this->_pointer;
        this->_pointer = NULL;
    }

    void reset(T* object) {
        this->operator=(object);
    }

    T* get() const {
        return this->_pointer;
    }

    void swap(UniquePointer& ptr) {
        T* temp = this->_pointer;

        this->_pointer = ptr._pointer;
        ptr._pointer = temp;
    }

    T* operator->(void) const {
        return this->_pointer;
    }

    T& operator*(void) const {
        return *this->_pointer;
    }
};
