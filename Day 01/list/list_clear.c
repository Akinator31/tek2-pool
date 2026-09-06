/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

void list_clear(list_t *this)
{
    if (!this || !this->l)
        return;
    free(this->l);
    this->length = 0;
    this->l = NULL;
}
