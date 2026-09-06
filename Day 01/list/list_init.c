/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#include <stdlib.h>
#include "list.h"

void list_init(list_t *this)
{
    if (!this)
        return;
    this->length = 0;
    this->l = NULL;
    this->empty = &list_empty;
    this->size = &list_size;
    this->get = &list_get;
    this->set = &list_set;
    this->push_front = &list_push_front;
    this->push_back = &list_push_back;
    this->pop_front = &list_pop_front;
    this->pop_back = &list_pop_back;
    this->clear = &list_clear;
    this->apply = &list_apply;
}
