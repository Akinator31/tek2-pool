/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** list
*/

#include "list.h"
#include "new.h"
#include "container.h"
#include "object.h"
#include "raise.h"
#include <stdarg.h>
#include <stdlib.h>

typedef struct Node_s {
    Object *data;
    struct Node_s *next;
} Node;

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    Node *_head;
} ListClass;

typedef struct {
    Iterator base;
    ListClass *_list;
    Node *_current;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args) {
    this->_list = va_arg(*args, ListClass *);
    this->_current = va_arg(*args, Node *);
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other) {
    return (this->_current == other->_current);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other) {
    Node *node = this->_list->_head;

    while (node) {
        if (node == other->_current)
        	return true;
        if (node == this->_current)
        	return false;
        node = node->next;
    }
    return false;
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other) {
    Node *node = this->_list->_head;

    while (node) {
        if (node == this->_current)
        	return true;
        if (node == other->_current)
        	return false;
        node = node->next;
    }
    return false;
}

static void ListIterator_incr(ListIteratorClass *this) {
    if (this->_current)
        this->_current = this->_current->next;
}

static Object *ListIterator_getval(ListIteratorClass *this) {
    if (!this->_current)
        raise("Out of range");
    return (this->_current->data);
}

static void ListIterator_setval(ListIteratorClass *this, ...) {
    va_list args;

    if (!this)
        raise("Missing Iterator !");
    if (!this->_current)
        raise("Out of range");
    va_start(args, this);
    delete(this->_current->data);
    this->_current->data = va_new(this->_list->_type, &args);
    va_end(args);
}

static const ListIteratorClass _iteratorDescription = {
    {
        /* Iterator struct */
        {
            /* Class struct */
            .__size__ = sizeof(_iteratorDescription),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._current = NULL
};

static const Class *ListIterator = (const Class *)&_iteratorDescription;

static void List_ctor(ListClass *this, va_list *args) {
    size_t size = va_arg(*args, size_t);
    Class *type = (Class *)va_arg(*args, void *);
    va_list args_cpy;
    Node *current = NULL;

    this->_size = 0;
    this->_type = type;
    this->_head = NULL;

    for (size_t i = 0; i < size; i++) {
        Node *new_node = malloc(sizeof(Node));
        if (!new_node)
        	raise("Memory Allocation Error");
        va_copy(args_cpy, *args);
        new_node->data = va_new(type, &args_cpy);
        new_node->next = NULL;

        if (!this->_head) {
			this->_head = new_node;
			current = new_node;
        } else {
			current->next = new_node;
			current = new_node;
        }
        this->_size++;
    }
}

static void List_dtor(ListClass *this) {
    Node *current = this->_head;
    Node *next = NULL;

    while (current) {
        next = current->next;
        delete(current->data);
        free(current);
        current = next;
    }
}

static size_t List_len(ListClass *this) { return (this->_size); }

static Iterator *List_begin(ListClass *this) {
    return (new(ListIterator, this, this->_head));
}

static Iterator *List_end(ListClass *this) {
    return (new(ListIterator, this, NULL));
}

static Object *List_getitem(ListClass *this, ...) {
    va_list args;
    size_t index = 0;
    Node *current = this->_head;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);

    if (index >= this->_size)
        raise("Index out of range");
    for (size_t i = 0; i < index; i++) {
        if (!current)
        	raise("Index out of range");
        current = current->next;
    }
    return (Object *)current->data;
}

static void List_setitem(ListClass *this, ...) {
    va_list args;
    size_t index = 0;
    Node *current = this->_head;

    va_start(args, this);
    index = va_arg(args, size_t);

    if (index >= this->_size) {
        va_end(args);
        raise("Index out of range");
    }

    for (size_t i = 0; i < index; i++) {
        if (!current) {
        	va_end(args);
        	raise("Index out of range");
        }
        current = current->next;
    }

    delete(current->data);
    current->data = va_new(this->_type, &args);
    va_end(args);
}

static Object *List_add(const Object *this, const Object *other) {
    ListClass *list1 = (ListClass *)this;
    ListClass *list2 = (ListClass *)other;
    ListClass *result = NULL;
    Node *current = NULL;
    Node *result_current = NULL;

    if (!this || !other)
        raise("Classes are missing!");

    result = (ListClass *)new(Array, 0, list1->_type);

    current = list1->_head;
    while (current) {
        Node *new_node = malloc(sizeof(Node));
        if (!new_node)
        	raise("Memory Allocation Error");
        new_node->data = new(list1->_type);
        memcpy(new_node->data, current->data, ((Class *)list1->_type)->__size__);
        new_node->next = NULL;

        if (!result->_head) {
			result->_head = new_node;
			result_current = new_node;
        } else {
			result_current->next = new_node;
			result_current = new_node;
        }
        result->_size++;
        current = current->next;
    }

    current = list2->_head;
    while (current) {
        Node *new_node = malloc(sizeof(Node));
        if (!new_node)
        	raise("Memory Allocation Error");
        new_node->data = new(list2->_type);
        memcpy(new_node->data, current->data, ((Class *)list2->_type)->__size__);
        new_node->next = NULL;

        if (!result->_head) {
			result->_head = new_node;
			result_current = new_node;
        } else {
			result_current->next = new_node;
			result_current = new_node;
        }
        result->_size++;
        current = current->next;
    }
    return (Object *)result;
}

static bool List_eq(const Object *this, const Object *other) {
    ListClass *list1 = (ListClass *)this;
    ListClass *list2 = (ListClass *)other;
    Node *node1 = NULL;
    Node *node2 = NULL;

    if (!this || !other)
        raise("Classes are missing!");

    if (list1->_size != list2->_size)
        return false;

    node1 = list1->_head;
    node2 = list2->_head;

    while (node1 && node2) {
        if (((Class *)list1->_type)->__eq__) {
			if (!((Class *)list1->_type)->__eq__(node1->data, node2->data))
				return false;
		} else {
			if (memcmp(node1->data, node2->data, ((Class *)list1->_type)->__size__) != 0)
				return false;
		}
        node1 = node1->next;
        node2 = node2->next;
    }

    return true;
}

static const ListClass _description = {
    {
        /* Container struct */
        {
            /* Class struct */
            .__size__ = sizeof(_description),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = (binary_operator_t)&List_add,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&List_eq,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._head = NULL
};

const Class *Array = (const Class *)&_description;
