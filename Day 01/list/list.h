/*
** EPITECH PROJECT, 2026
** list
** File description:
** list
*/

#ifndef LIST_H
    #define LIST_H
    #include <sys/types.h>
    #include <stdbool.h>

typedef struct list_s list_t;

struct list_s {
    void **l;
    size_t length;
    bool (*empty)(const list_t *);
    size_t (*size)(const list_t *);
    void *(*get)(const list_t *, size_t);
    bool (*set)(list_t *, size_t, void *);
    void (*push_front)(list_t *, void *);
    void (*push_back)(list_t *, void *);
    void (*pop_front)(list_t *);
    void (*pop_back)(list_t *);
    void (*clear)(list_t *);
    void (*apply)(list_t *, void *(*)(void *));
};

void list_init(list_t *this);
void list_destroy(list_t *this);

bool list_empty(const list_t *this);
size_t list_size(const list_t *this);
void *list_get(const list_t *this, size_t position);
bool list_set(list_t *this, size_t position, void *value);
void list_push_front(list_t *this, void *value);
void list_push_back(list_t *this, void *value);
void list_pop_front(list_t *this);
void list_pop_back(list_t *this);
void list_clear(list_t *this);
void list_apply(list_t *this, void *(*function)(void *));

#endif
