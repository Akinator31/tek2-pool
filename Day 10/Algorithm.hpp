/*
** EPITECH PROJECT, 2026
** Algorithm
** File description:
** Algorithm
*/

#pragma once

template <typename T> void swap(T& first, T& second) {
    T temp = first;
    first = second;
    second = temp;
}

template <typename T> T min(T first, T second) {
    if (first < second)
        return first;
    return second;
}

template <typename T> T max(T first, T second) {
    if (second < first)
        return first;
    return second;
}

template <typename T> T clamp(T value, T min, T max) {
    if (max < value)
        return max;
    if (value < min)
        return min;
    return value;
}
