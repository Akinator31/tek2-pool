/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_destroy(string_t *this)
{
    if (!this)
        return;
    if (this->s)
        free(this->s);
}
