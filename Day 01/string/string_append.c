/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_append(string_t *this, const char *str)
{
    int len = 0;

    if (!this || !this->s || !str)
        return;
    len = strlen(this->s);
    this->s = realloc(this->s, sizeof(char) * (len + strlen(str) + 1));
    if (!this->s)
        abort();
    strcat(this->s, str);
}
