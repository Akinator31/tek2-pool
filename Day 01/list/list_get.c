/*
** EPITECH PROJECT, 2026
** get
** File description:
** get
*/

#include <sys/types.h>
#include <stdlib.h>
#include "list.h"

void *list_get(const list_t *this, size_t position)
{
    if (!this || !this->l || !this->length)
        return NULL;
    if (position >= this->length)
        return NULL;
    return this->l[position];
}
