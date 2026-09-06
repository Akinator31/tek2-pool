/*
** EPITECH PROJECT, 2026
** string
** File description:
** string
*/

#ifndef STRING_H
    #define STRING_H
    #include <stdbool.h>
    #include <sys/types.h>

typedef struct string_s string_t;

struct string_s {
    char *s;
    bool (*empty)(const string_t *this);
    size_t (*length)(const string_t *this);
    char (*at)(const string_t *this, size_t pos);
    void (*print)(const string_t *this);
    const char *(*data)(const string_t *this);
    void (*clear)(string_t *this);
    void (*assign)(string_t *this, const char *str);
    void (*append)(string_t *this, const char *str);
};

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

bool string_empty(const string_t *this);
size_t string_length(const string_t *this);
char string_at(const string_t *this, size_t pos);
void string_print(const string_t *this);
const char *string_data(const string_t *this);
void string_clear(string_t *this);
void string_assign(string_t *this, const char *str);
void string_append(string_t *this, const char *);

#endif
