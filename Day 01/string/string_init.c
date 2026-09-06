/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (!this)
        return;
    if (s) {
        this->s = strdup(s);
        if (!this->s)
            abort();
    } else {
        this->s = NULL;
    }
    this->empty = &string_empty;
    this->length = &string_length;
    this->at = &string_at;
    this->print = &string_print;
    this->data = &string_data;
    this->clear = &string_clear;
    this->assign = &string_assign;
    this->append = &string_append;
}
