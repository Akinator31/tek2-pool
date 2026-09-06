/*
** EPITECH PROJECT, 2026
** G-PDG-300-TLS-3-1-PDGRUSH1-4
** File description:
** new
*/

#include "new.h"

Object *new(const Class *class, ...)
{
    Object *my_obj = NULL;
    va_list my_list = {0};

    va_start(my_list, class);
    my_obj = va_new(class, &my_list);
    va_end(my_list);
    return (my_obj);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *my_obj = NULL;

    if (!class)
        raise("Class missing !");
    my_obj = malloc(class->__size__);
    if (!my_obj)
        raise("Out of memory");
    memcpy(my_obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(my_obj, ap);
    if (!my_obj)
        raise("Out of memory");
    return my_obj;
}

void delete(Object *ptr)
{
    Class *temp_obj = ptr;

    if (!ptr)
        raise("Object missing !");
    if (temp_obj->__dtor__)
        temp_obj->__dtor__(ptr);
    free(ptr);
}
