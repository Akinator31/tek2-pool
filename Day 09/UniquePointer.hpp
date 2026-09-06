/*
** EPITECH PROJECT, 2026
** UniquePointer
** File description:
** UniquePointer
*/

#pragma once

#include "IObject.hpp"
#include <cstddef>

class UniquePointer {
    IObject* _pointer = NULL;

  public:
    UniquePointer(void) = default;
    UniquePointer(IObject* object);
    UniquePointer(UniquePointer& uniqueptr) = delete;
    ~UniquePointer(void);
    void operator=(IObject* object);
    void operator=(UniquePointer) = delete;
    void reset(void);
    void reset(IObject* object);
    void swap(UniquePointer& ptr);
    IObject* operator->(void) const;
    IObject& operator*(void) const;
};
