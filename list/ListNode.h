//
// Created by Jerry on 2021/5/14.
//

#ifndef DATASTRUCTURE_LISTNODE_H
#define DATASTRUCTURE_LISTNODE_H

#include "../base/DS.h"

#define Node(T)  ListNode<T>*

template<typename T>
class List;

template<typename T>
class ListNode : public DS {
    friend class List<T>;

private:
    T data;
    Node(T)prev;
    Node(T)next;
public:
    ListNode();

    explicit ListNode(const Node(T)&);

    ListNode(const T &, Node(T), Node(T));

    Node(T)insertAsPrev(const T &);

    Node(T)insertAsNext(const T &);


    bool operator==(const ListNode<T> &);
};


template<typename T>
ListNode<T>::ListNode(): prev(nullptr), next(nullptr) {
}

template<typename T>
ListNode<T>::ListNode(const Node(T)&from):data(from->data) {
    cout << "拷贝";
}

template<typename T>
ListNode<T>::ListNode(const T &nData, Node(T)prev, Node(T)next):data(nData), prev(prev), next(next) {
}

template<typename T>
Node(T)ListNode<T>::insertAsPrev(const T &nData) {
    Node(T)x = new ListNode<T>(nData, this->prev, this);
    this->prev->next = x;
    this->prev = x;
    return x;
}

template<typename T>
Node(T)ListNode<T>::insertAsNext(const T &nData) {
    Node(T)x = new ListNode<T>(nData, this, this->next);
    this->next->prev = x;
    this->next = x;
    return x;
}

template<typename T>
bool ListNode<T>::operator==(const ListNode<T> &another) {
    return this->data == another.data;
}

#endif //DATASTRUCTURE_LISTNODE_H
