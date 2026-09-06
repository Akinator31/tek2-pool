/*
** EPITECH PROJECT, 2026
** List
** File description:
** List
*/

#pragma once

#include "IObject.hpp"
#include <cstddef>
#include <deque>
#include <exception>
class List {
    std::deque<IObject*> _list;

  public:
    List(void) = default;
    ~List(void);
    void operator=(List& list) = delete;
    List(List* list) = delete;

    bool empty(void) const;
    std::size_t size(void) const;
    IObject*& front(void);
    IObject* front(void) const;
    IObject*& back(void);
    IObject* back(void) const;
    void pushBack(IObject* obj);
    void pushFront(IObject* obj);
    void popFront(void);
    void popBack(void);
    void clear(void);
    void forEach(void (*function)(IObject*));

    class InvalidOperationException : public std::exception {
      public:
        InvalidOperationException(void) = default;
    };

    class InvalidIteratorException : public std::exception {
      public:
        InvalidIteratorException() = default;
    };

    class Iterator {
        std::deque<IObject*>* _originList;
        std::deque<IObject*>::iterator _iterator;

      public:
        Iterator(std::deque<IObject*>::iterator iterator, std::deque<IObject*>* list);
        IObject* operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
        std::deque<IObject*>::iterator& get_iterator(void);
        std::deque<IObject*>* get_origin_list(void);

        class OutOfRangeException : public std::exception {
          public:
            OutOfRangeException() = default;
        };
    };

    Iterator begin(void) const;
    Iterator end(void) const;
    Iterator erase(Iterator it);
    Iterator insert(List::Iterator it, IObject* obj);
};
