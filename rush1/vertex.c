/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

Object *add_vectors(const Object *this, const Object *other)
{
    VertexClass *vertex1 = NULL;
    VertexClass *vertex2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    vertex1 = (VertexClass *)this;
    vertex2 = (VertexClass *)other;
    return new(Vertex, vertex1->x + vertex2->x, vertex1->y + vertex2->y, vertex1->z + vertex2->z);
}

Object *substract_vectors(const Object *this, const Object *other)
{
    VertexClass *vertex1 = NULL;
    VertexClass *vertex2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");
    vertex1 = (VertexClass *)this;
    vertex2 = (VertexClass *)other;
    return new(Vertex, vertex1->x - vertex2->x, vertex1->y - vertex2->y, vertex1->z - vertex2->z);
}

char *print_vertex(Object *this)
{
    VertexClass *vertex = NULL;
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    vertex = (VertexClass *)this;
    size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", vertex->x, vertex->y, vertex->z) + 1;
    str = malloc(sizeof(char) * size);
    sprintf(str, "<Vertex (%d, %d, %d)>", vertex->x, vertex->y, vertex->z);
    return str;
}

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    int x = (int)va_arg(*args, int);
    int y = (int)va_arg(*args, int);
    int z = (int)va_arg(*args, int);

    this->x = x;
    this->y = y;
    this->z = z;
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
    return;
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&print_vertex,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&add_vectors,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&substract_vectors,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
