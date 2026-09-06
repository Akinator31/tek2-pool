/*
** EPITECH PROJECT, 2026
** SharedPointer
** File description:
** SharedPointer
*/

#include "SharedPointer.hpp"
#include "IObject.hpp"

void UseCount::add_instance(void) {
    this->_use_count += 1;
}

void UseCount::remove_instance(void) {
    this->_use_count -= 1;
}

int UseCount::get_count(void) {
    if (!this->_use_count)
        return 0;
    return this->_use_count;
}

void UseCount::operator=(UseCount use_count) {
    this->_use_count = use_count._use_count;
}

SharedPointer::SharedPointer(IObject* object) {
    this->_pointer = object;
    this->_use_count->add_instance();
}

int SharedPointer::use_count(void) {
    if (!this->_use_count)
        return 0;
    return this->_use_count->get_count();
}

SharedPointer::SharedPointer(const SharedPointer& sharedptr) {
    this->_pointer = sharedptr._pointer;
    this->_use_count = sharedptr._use_count;
    this->_use_count->add_instance();
}

SharedPointer::SharedPointer(SharedPointer* sharedptr) {
    this->_pointer = sharedptr->_pointer;
    this->_use_count = sharedptr->_use_count;
    this->_use_count->add_instance();
}

SharedPointer::~SharedPointer(void) {
    if (!this->_use_count)
        return;
    this->_use_count->remove_instance();
    if (this->_pointer && this->use_count() == 0) {
        if (this->_pointer) {
            delete this->_pointer;
            this->_pointer = NULL;
        }
        delete this->_use_count;
        this->_use_count = NULL;
    }
}

void SharedPointer::operator=(SharedPointer& object) {
    if (this == &object)
        return;
    if (this->_use_count) {
        this->_use_count->remove_instance();
        if (this->use_count() == 0) {
            if (this->_pointer)
                delete this->_pointer;
            delete this->_use_count;
        }
    }
    this->_pointer = object._pointer;
    this->_use_count = object._use_count;
    this->_use_count->add_instance();
}

void SharedPointer::operator=(IObject* object) {
    if (this->_use_count) {
        this->_use_count->remove_instance();
        if (this->use_count() == 0) {
            if (this->_pointer)
                delete this->_pointer;
            delete this->_use_count;
        }
    }
    this->_pointer = object;
    this->_use_count = new UseCount;
    this->_use_count->add_instance();
}

void SharedPointer::reset(void) {
    if (!this->_pointer)
        return;
    if (this->use_count() == 0) {
        delete this->_pointer;
        delete this->_use_count;
    } else {
        this->_use_count->remove_instance();
        if (this->use_count() == 0) {
            if (this->_pointer)
                delete this->_pointer;
            delete this->_use_count;
        }
    }
    this->_pointer = NULL;
    this->_use_count = NULL;
}

void SharedPointer::reset(IObject* object) {
    if (this->_use_count) {
        this->_use_count->remove_instance();
        if (this->use_count() == 0) {
            if (this->_pointer)
                delete this->_pointer;
            delete this->_use_count;
        }
    }
    this->_pointer = object;
    this->_use_count = new UseCount;
    this->_use_count->add_instance();
}

IObject* SharedPointer::operator->(void) const {
    return this->_pointer;
}

IObject& SharedPointer::operator*(void) const {
    return *this->_pointer;
}

void SharedPointer::swap(SharedPointer& ptr) {
    IObject* temp = this->_pointer;
    UseCount* temp_use_count = this->_use_count;

    this->_pointer = ptr._pointer;
    this->_use_count = ptr._use_count;
    ptr._pointer = temp;
    ptr._use_count = temp_use_count;
}
