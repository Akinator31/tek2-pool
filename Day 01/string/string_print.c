/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "string.h"

void string_print(const string_t *this)
{
    if (!this || !this->s)
        return;
    write(1, this->s, strlen(this->s));
}
