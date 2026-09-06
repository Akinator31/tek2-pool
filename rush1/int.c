/*
** EPITECH PROJECT, 2026
** int
** File description:
** int
*/

#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     value;
}   IntClass;

char *print_int(Object *this)
{
    IntClass *integer = NULL;
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    integer = (IntClass *)this;
    size = snprintf(NULL, 0, "<Int (%d)>", integer->value) + 1;
    str = malloc(sizeof(char) * size);
    sprintf(str, "<Int (%d)>", integer->value);
    return str;
}

Object *add_integer(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    return new(Int, int1->value + int2->value);
}

Object *substract_integer(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    return new(Int, int1->value - int2->value);
}

Object *multiply_integer(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    return new(Int, int1->value * int2->value);
}

Object *divide_integer(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    if (int2->value == 0)
        raise("Cannot divide by zero!");
    return new(Int, int1->value / int2->value);
}

bool is_integer_equal(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    return int1->value == int2->value;
}

bool is_integer_greater_than(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    return int1->value > int2->value;
}

bool is_integer_less_than(const Object *this, const Object *other)
{
    IntClass *int1 = NULL;
    IntClass *int2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    int1 = (IntClass *)this;
    int2 = (IntClass *)other;
    return int1->value < int2->value;
}

static void Int_ctor(IntClass *this, va_list *args)
{
    int value = (int)va_arg(*args, int);

    this->value = value;
}

static void Int_dtor(IntClass *this)
{
    (void)this;
    return;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(_description),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&print_int,
        .__add__ = (binary_operator_t)&add_integer,
        .__sub__ = (binary_operator_t)&substract_integer,
        .__mul__ = (binary_operator_t)&multiply_integer,
        .__div__ = (binary_operator_t)&divide_integer,
        .__eq__ = (binary_comparator_t)&is_integer_equal,
        .__gt__ = (binary_comparator_t)&is_integer_greater_than,
        .__lt__ = (binary_comparator_t)&is_integer_less_than,
    },
    .value = 0
};

const Class   *Int = (const Class *)&_description;
