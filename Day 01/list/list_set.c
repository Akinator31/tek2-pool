/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdbool.h>
#include "list.h"

bool list_set(list_t *this, size_t position, void *value)
{
    if (!this || !this->l || !this->length || position >= this->length)
        return false;
    this->l[position] = value;
    return true;
}
