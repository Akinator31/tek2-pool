/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

bool string_empty(const string_t *this)
{
    if (!this || !this->s || strlen(this->s) == 0)
        return true;
    return false;
}
