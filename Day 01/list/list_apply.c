/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

void list_apply(list_t *this, void *(*function)(void *))
{
    if (!this || !this->l)
        return;
    for (size_t i = 0; i < this->length; i++)
        this->l[i] = function(this->l[i]);
}
