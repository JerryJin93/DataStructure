//
// Created by Jerry on 2021/5/14.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include "../base/DS.h"
#include "ListNode.h"
#include "../utils/StrUtils.h"
#include "../exception/IndexOutOfBoundException.h"
#include <iostream>
#include <cstring>

#define NOT_FOUND -1
#define L_BRACKET "{"
#define R_BRACKET "}"
#define NEXT_LINE "\n"
#define STR_LEN(s) (strlen(s))

using namespace std;

template<typename T>
class List : public DS {
private:
    int _size;
    Node(T)head;
    Node(T)tail;

    Node(T)firstValid() const;

    void detachNode(Node(T));

    void updateNode(Node(T));

    void removeNode(Node(T));

    void copyNodes(Node(T), int len);

    Node(T)get(int) const;

protected:
    void init();

public:
    List();

    List(initializer_list<T>);

    List(const List<T> &);

    Node(T)first() const;

    Node(T)end() const;

    Node(T)insertBefore(Node(T), const T &);

    Node(T)insertAtLast(const T &);

    void add(const T &);

    void addAll(const List<T> &);

    Node(T)find(const T &, int, Node(T)) const;

    int find(const T &) const;

    int find(const Node(T)&) const;

    bool remove(const T &);

    T removeAt(int);

    void set(int, const T &);

    int clear();

    int deduplicate();

    int size() const;

    string toString() const override;

    T operator[](int) const;

    List<T> &operator+(const List<T> &);

    List<T> &operator-(const List<T> &);

    bool operator==(const List<T> &);

    template<typename L>
    friend ostream &operator<<(ostream &, const List<L> &);

    ~List();
};

template<typename T>
Node(T)List<T>::firstValid() const {
    return first()->next;
}

template<typename T>
void List<T>::detachNode(Node(T)node) {
    if (node) {
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
    }
}

template<typename T>
void List<T>::updateNode(Node(T)node) {
    if (node) {
        if (node->prev) {
            node->prev->next = node;
        }
        if (node->next) {
            node->next->prev = node;
        }
    }
}

template<typename T>
void List<T>::removeNode(Node(T)node) {
    detachNode(node);
    node->prev = node->next = nullptr;
    delete node;
    _size--;
}

template<typename T>
void List<T>::copyNodes(Node(T)node, int len) {
    while (len-- > 0) {
        add(node->data);
        node = node->next;
    }
}

template<typename T>
Node(T)List<T>::get(int index) const {
    if (index < 0 || index >= _size) return nullptr;
    Node(T)p = first();
    for (int i = 0; i <= index; i++) {
        p = p->next;
    }
    return p;
}

template<typename T>
void List<T>::init() {
    this->head = new ListNode<T>();
    this->tail = new ListNode<T>();

    this->head->prev = nullptr;
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->tail->next = nullptr;

    this->_size = 0;
}

template<typename T>
List<T>::List() { // NOLINT(cppcoreguidelines-pro-type-member-init)
    this->init();
}

template<typename T>
List<T>::List(initializer_list<T> initializerList):List() { // NOLINT(cppcoreguidelines-pro-type-member-init)
    for (auto ele = initializerList.begin(); ele != initializerList.end(); ++ele) {
        add(*ele);
    }
}

template<typename T>
List<T>::List(const List<T> &list):List() { // NOLINT(cppcoreguidelines-pro-type-member-init)
    copyNodes(list.firstValid(), list.size());
}

template<typename T>
Node(T)List<T>::first() const {
    return this->head;
}

template<typename T>
Node(T)List<T>::end() const {
    return this->tail;
}

template<typename T>
Node(T)List<T>::insertBefore(Node(T)node, const T &data) {
    this->_size++;
    return node->insertAsPrev(data);
}

template<typename T>
Node(T)List<T>::insertAtLast(const T &data) {
    return insertBefore(tail, data);
}

template<typename T>
void List<T>::add(const T &data) {
    Node(T)p = this->tail;
    this->insertBefore(p, data);
}

template<typename T>
void List<T>::addAll(const List<T> &another) {
    Node(T)p = another.first();
    int anotherSize = another._size;
    while (anotherSize-- > 0) {
        add((p = p->next)->data);;
    }
}

template<typename T>
Node(T)List<T>::find(const T &data, int n, Node(T)node) const {
    while (n-- > 0) {
        if (data == (node = node->prev)->data) {
            return node;
        }
    }
    return nullptr;
}

template<typename T>
int List<T>::find(const T &data) const {
    Node(T)p = firstValid();
    for (int i = 0; p && p != tail; ++i) {
        if (p->data == data) {
            return i;
        }
        p = p->next;
    }
    return NOT_FOUND;
}

template<typename T>
int List<T>::find(const Node(T)&node) const {
    return find(node->data);
}

template<typename T>
bool List<T>::remove(const T &data) {
    int result = find(data);
    if (result >= 0) {
        removeAt(result);
    }
    return result != NOT_FOUND;
}

template<typename T>
T List<T>::removeAt(int index) {
    Node(T)p;
    if ((p = get(index))) {
        T data = p->data;
        removeNode(p);
        return data;
    } else {
        throw IndexOutOfBoundException();
    }
}

template<typename T>
void List<T>::set(int index, const T &data) {
    Node(T)p = get(index);
    if (p) {
        p->data = data;
    }
}

template<typename T>
int List<T>::clear() {
    int oldSize = _size;
    Node(T)p = firstValid();
    Node(T)tmp;
    while (p && p != end()) {
        tmp = p;
        this->detachNode(p);
        p = p->next;
        tmp->prev = tmp->next = nullptr;
        delete tmp;
    }
    tmp = nullptr;
    _size = 0;
    return oldSize;
}

template<typename T>
int List<T>::deduplicate() {
    if (_size < 2) return _size;
    int oldSize = _size;
    Node(T)p = first();
    int index = 0;
    while (end() != (p = p->next)) {
        Node(T)q = find(p->data, index, p);
        if (q) {
            removeNode(q);
        }
        index++;
    }
    return oldSize - _size;
}

template<typename T>
int List<T>::size() const {
    return _size;
}

template<typename T>
string List<T>::toString() const {
    string result = L_BRACKET;
    Node(T)p = firstValid();
    for (int i = 0; p && p != end(); ++i) {
        auto data = StrUtils::toString(p->data);
        result = result + data;
        if (i < _size - 1) {
            auto comma = ", ";
            result.append(comma, STR_LEN(comma));
        }
        p = p->next;
    }
    return result.append(R_BRACKET, STR_LEN(R_BRACKET));
}

template<typename T>
T List<T>::operator[](int index) const {
    Node(T)p;
    if ((p = get(index))) {
        return p->data;
    } else {
        throw IndexOutOfBoundException();
    }
}

template<typename T>
List<T> &List<T>::operator+(const List<T> &another) {
    auto newList = new List<T>(*this);
    newList->addAll(another);
    return *newList;
}

template<typename T>
List<T> &List<T>::operator-(const List<T> &another) {
    Node(T)p = another.first();
    while (another.end() != (p = p->next)) {
        int pos;
        const Node(T)cp = p;
        if ((pos = find(cp)) != NOT_FOUND) {
            removeAt(pos);
        }
    }
    return *this;
}

template<typename T>
bool List<T>::operator==(const List<T> &another) {
    if (_size == another._size) {
        Node(T)p = head->next;
        Node(T)q = another.head->next;
        while (_size-- > 0) {
            if (p->data != q->data) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    } else {
        return false;
    }
}

template<typename T>
ostream &operator<<(ostream &os, const List<T> &list) {
    os << list.toString();
    return os;
}

template<typename T>
List<T>::~List() {
    clear();
    delete head;
    delete tail;
}

#endif //DATASTRUCTURE_LIST_H
