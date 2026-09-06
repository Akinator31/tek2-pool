/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static void *shift_everything_by_one_to_left(list_t *this)
{
    for (int i = this->length - 1; i != 1; i--)
        this->l[i - 1] = this->l[i];
    return this->l;
}

void list_pop_front(list_t *this)
{
    if (!this || !this->l)
        return;
    if (this->length == 1) {
        free(this->l);
        this->l = NULL;
        this->length -= 1;
        return;
    }
    this->l = shift_everything_by_one_to_left(this);
    this->l = realloc(this->l, sizeof(void *) * (this->length - 1));
    if (!this->l)
        abort();
    this->length -= 1;
}
