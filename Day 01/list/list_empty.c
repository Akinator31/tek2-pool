/*
** EPITECH PROJECT, 2026
** empty
** File description:
** empty
*/

#include <stdbool.h>
#include "list.h"

bool list_empty(const list_t *this)
{
    if (!this || !this->length || !this->l)
        return true;
    return false;
}
