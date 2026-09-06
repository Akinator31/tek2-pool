/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

static void *shift_everything_by_one_to_right(list_t *this)
{
    for (int i = this->length - 1; i >= 0; i--)
        this->l[i + 1] = this->l[i];
    return this->l;
}

void list_push_front(list_t *this, void *value)
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
        this->l = shift_everything_by_one_to_right(this);
        this->l[0] = value;
        this->length += 1;
    }
}
