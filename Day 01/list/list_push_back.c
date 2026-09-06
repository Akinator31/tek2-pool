/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

void list_push_back(list_t *this, void *value)
{
    if (!this || !this->l) {
        this->l = malloc(sizeof(void *));
        if (!this->l)
            abort();
        this->l[0] = value;
        this->length = 1;
    } else {
        this->l = realloc(this->l, sizeof(void *) * (this->length + 1));
        if (!this->l)
            abort();
        this->l[this->length] = value;
        this->length += 1;
    }
}
