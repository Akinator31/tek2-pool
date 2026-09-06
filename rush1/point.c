/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

char *point_str(Object *this)
{
    PointClass *point = (PointClass *)this;
    int size = snprintf(NULL, 0, "<Point (%d, %d)>", point->x, point->y) + 1;
    char *str = malloc(sizeof(char) * size);

    sprintf(str, "<Point (%d, %d)>", point->x, point->y);
    return str;
}

static Object *point_add(const Object *this, const Object *other)
{
    PointClass *a = NULL;
    PointClass *b = NULL;
    Object *c = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (PointClass *)this;
    b = (PointClass *)other;
    c = new(Point, a->x + b->x, a->y + b->y);
    return c;
}

static Object *point_sub(const Object *this, const Object *other)
{
    PointClass *a = NULL;
    PointClass *b = NULL;
    Object *c = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (PointClass *)this;
    b = (PointClass *)other;
    c = new(Point, a->x - b->x, a->y - b->y);
    return c;
}

static void Point_ctor(PointClass *this, va_list *args)
{
    int x = (int)va_arg(*args, int);
    int y = (int)va_arg(*args, int);

    this->x = x;
    this->y = y;
}

static void Point_dtor(PointClass *this)
{
    (void)this;
    return;
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = &point_str,    /* Implement this method for exercice 02 */
        .__add__ = &point_add,    /* Implement this method for exercice 03 */
        .__sub__ = &point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
