/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

const char *string_data(const string_t *this)
{
    if (!this)
        return NULL;
    return this->s;
}
