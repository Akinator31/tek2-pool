/*
** EPITECH PROJECT, 2026
** Array
** File description:
** Array
*/

#pragma once

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename Type, std::size_t s> class Array {
    std::array<Type, s> _array = {};

  public:
    Array<Type, s>(void) = default;

    const Type& operator[](size_t index) const {
        if (index >= this->_array.size())
            throw std::out_of_range("Out of range");
        return this->_array[index];
    }

    Type& operator[](size_t index) {
        if (index >= this->_array.size())
            throw std::out_of_range("Out of range");
        return this->_array[index];
    }

    size_t size(void) const {
        return this->_array.size();
    }

    void forEach(const std::function<void(const Type&)>& task) const {
        for (size_t i = 0; i < this->size(); i++) {
            task(this->_array[i]);
        }
    }

    template <typename U>
    Array<U, s> convert(const std::function<U(const Type&)>& converter) const {
        Array<U, s> converted_array;

        for (size_t i = 0; i < this->size(); i++) {
            const Type& temp = this->_array[i];
            converted_array[i] = converter(temp);
        }
        return converted_array;
    }
};

template <typename Type, std::size_t size>
std::ostream& operator<<(std::ostream& stream, const Array<Type, size>& array) {
    size_t i = 0;

    stream << "[";
    for (; i < array.size(); i++) {
        stream << array[i];
        if (i < array.size() - 1)
            stream << ", ";
    }
    return stream << "]";
}
