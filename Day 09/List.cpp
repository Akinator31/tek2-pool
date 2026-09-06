/*
** EPITECH PROJECT, 2026
** List
** File description:
** List
*/

#include "List.hpp"
#include "IObject.hpp"
#include <cstddef>
#include <deque>

template <typename INSANE_OBJECT> void my_insane_delete(INSANE_OBJECT* insane_object) {
    if (insane_object)
        delete insane_object;
}

List::~List(void) {
    this->forEach(&my_insane_delete<IObject>);
}

bool List::empty(void) const {
    return this->_list.empty();
}

size_t List::size(void) const {
    return this->_list.size();
}

IObject*& List::front(void) {
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.front();
}

IObject* List::front(void) const {
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.front();
}

IObject*& List::back(void) {
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.back();
}

IObject* List::back(void) const {
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.back();
}

void List::pushBack(IObject* obj) {
    this->_list.push_back(obj);
}

void List::pushFront(IObject* obj) {
    this->_list.push_front(obj);
}

void List::popFront(void) {
    if (this->empty())
        throw InvalidOperationException();
    IObject* temp = this->_list.front();
    if (temp)
        delete temp;
    this->_list.pop_front();
}

void List::popBack(void) {
    if (this->empty())
        throw InvalidOperationException();
    IObject* temp = this->_list.back();
    if (temp)
        delete temp;
    this->_list.pop_back();
}

void List::clear(void) {
    this->forEach(my_insane_delete<IObject>);
    this->_list.clear();
}

void List::forEach(void (*function)(IObject*)) {
    for (IObject* object : this->_list)
        function(object);
}

List::Iterator::Iterator(std::deque<IObject*>::iterator iterator, std::deque<IObject*>* list) {
    this->_iterator = iterator;
    this->_originList = list;
}

std::deque<IObject*>* List::Iterator::get_origin_list(void) {
    return this->_originList;
}

IObject* List::Iterator::operator*() const {
    if (this->_iterator == this->_originList->end())
        throw OutOfRangeException();
    return *this->_iterator;
}

List::Iterator& List::Iterator::operator++() {
    if (this->_iterator == this->_originList->end())
        throw OutOfRangeException();
    this->_iterator++;
    return *this;
}

bool List::Iterator::operator==(const Iterator& it) const {
    return this->_iterator == it._iterator;
}

bool List::Iterator::operator!=(const Iterator& it) const {
    return this->_iterator != it._iterator;
}

List::Iterator List::begin(void) const {
    std::deque<IObject*>& temp = const_cast<std::deque<IObject*>&>(this->_list);
    return List::Iterator(temp.begin(), &temp);
}

List::Iterator List::end(void) const {
    std::deque<IObject*>& temp = const_cast<std::deque<IObject*>&>(this->_list);
    return List::Iterator(temp.end(), &temp);
}

std::deque<IObject*>::iterator& List::Iterator::get_iterator(void) {
    return this->_iterator;
}

List::Iterator List::erase(List::Iterator it) {
    if (it.get_origin_list() != &this->_list)
        throw InvalidIteratorException();
    if (it.get_iterator() == this->end().get_iterator())
        throw InvalidIteratorException();
    IObject* temp = *it;
    if (temp)
        delete temp;
    return List::Iterator(this->_list.erase(it.get_iterator()), &this->_list);
}

List::Iterator List::insert(List::Iterator it, IObject* obj) {
    if (it.get_origin_list() != &this->_list)
        throw InvalidIteratorException();
    return List::Iterator(this->_list.insert(it.get_iterator(), obj), &this->_list);
}
