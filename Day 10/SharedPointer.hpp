/*
** EPITECH PROJECT, 2026
** SharedPointer
** File description:
** SharedPointer
*/

#pragma once

#include <cstddef>

class UseCount {
    int _use_count = 0;

  public:
    int get_count(void) {
        if (!this->_use_count)
            return 0;
        return this->_use_count;
    }

    void add_instance(void) {
        this->_use_count += 1;
    }

    void remove_instance(void) {
        this->_use_count -= 1;
    }

    void operator=(UseCount use_count) {
        this->_use_count = use_count._use_count;
    }
};

template <typename T> class SharedPointer {
    T* _pointer = NULL;
    UseCount* _use_count = new UseCount;

  public:
    SharedPointer(void) = default;

    SharedPointer(T* object) {
        this->_pointer = object;
        this->_use_count->add_instance();
    }

    SharedPointer(const SharedPointer& sharedptr) {
        this->_pointer = sharedptr._pointer;
        this->_use_count = sharedptr._use_count;
        this->_use_count->add_instance();
    }

    SharedPointer(SharedPointer* sharedptr) {
        this->_pointer = sharedptr->_pointer;
        this->_use_count = sharedptr->_use_count;
        this->_use_count->add_instance();
    }

    ~SharedPointer(void) {
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

    void operator=(T* object) {
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

    void operator=(SharedPointer& object) {
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

    void reset(void) {
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

    void reset(T* object) {
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

    void swap(SharedPointer& ptr) {
        T* temp = this->_pointer;
        UseCount* temp_use_count = this->_use_count;

        this->_pointer = ptr._pointer;
        this->_use_count = ptr._use_count;
        ptr._pointer = temp;
        ptr._use_count = temp_use_count;
    }

    T* operator->(void) const {
        return this->_pointer;
    }

    T& operator*(void) const {
        return *this->_pointer;
    }

    int use_count(void) {
        if (!this->_use_count)
            return 0;
        return this->_use_count->get_count();
    }

    T* get(void) {
        return this->_pointer;
    }
};
