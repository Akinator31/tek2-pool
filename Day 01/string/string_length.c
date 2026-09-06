/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

size_t string_length(const string_t *this)
{
    if (!this || !this->s)
        return 0;
    return strlen(this->s);
}
