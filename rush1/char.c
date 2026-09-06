#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char value;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this || !args)
        raise("");
    this->value = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
    return;
}

static char *Char_str(Object *this)
{
    CharClass *character = NULL;
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    character = (CharClass *)this;
    size = snprintf(NULL, 0, "<Char (%c)>", character->value) + 1;
    str = malloc(sizeof(char) * size);
    sprintf(str, "<Char (%c)>", character->value);
    return str;
}

static CharClass *Char_add(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return new(Char, ((CharClass *)this)->value + ((CharClass *)other)->value);
}

static CharClass *Char_sub(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return new(Char, ((CharClass *)this)->value - ((CharClass *)other)->value);
}

static CharClass *Char_mul(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return new(Char, ((CharClass *)this)->value * ((CharClass *)other)->value);
}

static CharClass *Char_div(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return new(Char, ((CharClass *)this)->value / ((CharClass *)other)->value);
}

static bool Char_eq(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return ((CharClass *)this)->value == ((CharClass *)other)->value;
}

static bool Char_gt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return ((CharClass *)this)->value > ((CharClass *)other)->value;
}

static bool Char_lt(const Object *this, const Object *other)
{
    if (this == NULL || other == NULL)
        raise("");
    return ((CharClass *)this)->value < ((CharClass *)other)->value;
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Char_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .value = 0,
};

const Class *Char = (const Class *)&_description;