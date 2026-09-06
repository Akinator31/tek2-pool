/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

void list_pop_back(list_t *this)
{
    if (!this || !this->l)
        return;
    if (this->length == 1) {
        free(this->l);
        this->length -= 1;
        return;
    }
    this->l = realloc(this->l, sizeof(void *) * (this->length - 1));
    if (!this->l)
        abort();
    this->length -= 1;
}
