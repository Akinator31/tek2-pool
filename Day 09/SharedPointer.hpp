/*
** EPITECH PROJECT, 2026
** SharedPointer
** File description:
** SharedPointer
*/

#pragma once

#include "IObject.hpp"
#include <cstddef>

class UseCount {
    int _use_count = 0;

  public:
    int get_count(void);
    void add_instance(void);
    void remove_instance(void);

    void operator=(UseCount use_count);
};

class SharedPointer {
    IObject* _pointer = NULL;
    UseCount* _use_count = new UseCount;

  public:
    SharedPointer(void) = default;
    SharedPointer(IObject* object);
    SharedPointer(const SharedPointer& sharedptr);
    SharedPointer(SharedPointer* sharedptr);
    ~SharedPointer(void);
    void operator=(IObject* object);
    void operator=(SharedPointer& shared_pointer);
    void reset(void);
    void reset(IObject* object);
    void swap(SharedPointer& ptr);
    IObject* operator->(void) const;
    IObject& operator*(void) const;
    int use_count(void);
};
