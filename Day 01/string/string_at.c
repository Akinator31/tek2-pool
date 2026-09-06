/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

char string_at(const string_t *this, size_t pos)
{
    if (!this || !this->s)
        return -1;
    if (pos > strlen(this->s) || this->s[pos] == '\0' || strlen(this->s) == 0)
        return -1;
    return this->s[pos];
}
