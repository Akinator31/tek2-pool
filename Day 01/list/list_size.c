/*
** EPITECH PROJECT, 2026
** size
** File description:
** size
*/

#include <sys/types.h>
#include <stdio.h>
#include "list.h"

size_t list_size(const list_t *this)
{
    if (!this || !this->length || !this->l)
        return (size_t)0;
    return this->length;
}
