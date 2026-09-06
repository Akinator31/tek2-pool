/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_assign(string_t *this, const char *str)
{
    if (!this || !str)
        return;
    if (this->s)
        free(this->s);
    this->s = strdup(str);
    if (!this->s)
        abort();
}
