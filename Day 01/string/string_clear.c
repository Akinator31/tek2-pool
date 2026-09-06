/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_clear(string_t *this)
{
    if (!this || !this->s)
        return;
    for (int i = 0; this->s[i] != '\0'; i++) {
        this->s[i] = '\0';
    }
}
