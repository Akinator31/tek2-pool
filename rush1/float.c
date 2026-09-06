/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class   base;
    float   value;
}   FloatClass;

static char *float_str(Object *this)
{
    FloatClass *float_obj = (FloatClass *)this;
    int size = snprintf(NULL, 0, "<Float (%f)>", float_obj->value) + 1;
    char *str = malloc(sizeof(char) * size);

    sprintf(str, "<Float (%f)>", float_obj->value);
    return str;
}

static Object *float_add(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;
    Object *c = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    c = new(Float, a->value + b->value);
    return c;
}

static Object *float_sub(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;
    Object *c = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    c = new(Float, a->value - b->value);
    return c;
}

static Object *float_mult(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;
    Object *c = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    c = new(Float, a->value * b->value);
    return c;
}

static Object *float_div(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;
    Object *c = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    if (a->value == 0 || b->value == 0)
        raise("Maths error !");
    c = new(Float, a->value / b->value);
    return c;
}

static bool float_eq(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return a->value == b->value;
}

static bool float_gt(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return a->value > b->value;
}

static bool float_lt(const Object *this, const Object *other)
{
    FloatClass *a = NULL;
    FloatClass *b = NULL;

    if (!this || !other)
        raise("Object missing !");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return a->value < b->value;
}

static void float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        return;
    this->value = (float)va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    (void)this;
    return;
}

// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&float_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&float_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&float_mult,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .value = 0.0,
};

const Class   *Float = (const Class *)&_description;
