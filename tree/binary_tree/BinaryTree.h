//
// Created by Jerry on 2021/5/12.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <cmath>
#include <stack>
#include "BinaryNode.h"

#define refFromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lChild : (x).parent->rChild))

using namespace std;

template<typename T>
class BinaryTree {
protected:
    int _size;
    BiNode(T)_root;

    virtual int updateHeight(BiNode(T));

    void updateHeightAbove(BiNode(T));

public:
    BinaryTree();

    ~BinaryTree();

    BiNode(T)root() const;

    int size() const;

    bool isEmpty() const;

    BiNode(T)insertAsRoot(const T &);

    BiNode(T)insertAsLC(BiNode(T), const T &);

    BiNode(T)insertAsRC(BiNode(T), const T &);

    BiNode(T)attachAsLc(BiNode(T), BinaryTree<T> *&);

    BiNode(T)attachAsRc(BiNode(T), BinaryTree<T> *&);

    BinaryTree<T> detach(BiNode(T));

    int remove(BiNode(T));

    template<typename VST>
    void preOrderTraverse(BiNode(T), VST &);

    template<typename VST>
    void inOrderTraverse(BiNode(T), VST &);

    template<typename VST>
    void postOrderTraverse(BiNode(T), VST &);

    template<typename VST>
    void levelTraverse(BiNode(T), VST &);

    bool operator<(const BinaryTree<T> &);

    bool operator<=(const BinaryTree<T> &);

    bool operator>(const BinaryTree<T> &);

    bool operator>=(const BinaryTree<T> &);

    bool operator==(const BinaryTree<T> &);
};

template<typename T>
int BinaryTree<T>::updateHeight(BiNode(T)node) {
    return node->height = 1 + max(getHeight(node->lChild), getHeight(node->rChild));
}

template<typename T>
void BinaryTree<T>::updateHeightAbove(BiNode(T)node) {
    while (node) {
        updateHeight(node);
        node = node->parent;
    }
}

template<typename T>
BinaryTree<T>::BinaryTree():_size(0), _root(nullptr) {
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    if (_size > 0) {
        remove(_root);
    }
}

template<typename T>
BiNode(T)BinaryTree<T>::root() const {
    return _root;
}

template<typename T>
int BinaryTree<T>::size() const {
    return _size;
}

template<typename T>
bool BinaryTree<T>::isEmpty() const {
    return _root != nullptr;
}

template<typename T>
BiNode(T)BinaryTree<T>::insertAsRoot(const T &data) {
    _size = 1;
    _root = new BinaryNode<T>(data, nullptr, nullptr, nullptr, 0, 1, RBT_RED);
}


template<typename T>
BiNode(T)BinaryTree<T>::insertAsLC(BiNode(T)node, const T &data) {
    _size++;
    node->insertAsLC(data);
    updateHeightAbove(node);
    return node->lChild;
}

template<typename T>
BiNode(T)BinaryTree<T>::insertAsRC(BiNode(T)node, const T &data) {
    _size++;
    node->insertAsRC(data);
    updateHeightAbove(node);
    return node->rChild;
}

template<typename T>
BiNode(T)BinaryTree<T>::attachAsLc(BiNode(T)node, BinaryTree<T> *&tree) {
    if ((node->lChild = tree->_root))
        node->lChild->parent = node;
    _size += tree->_size;
    updateHeightAbove(node);
    tree->_root = nullptr;
    tree->_size = 0;
    delete tree;
    tree = nullptr;
    return node;
}

template<typename T>
BiNode(T)BinaryTree<T>::attachAsRc(BiNode(T)node, BinaryTree<T> *&tree) {
    if ((node->rChild = tree->_root))
        node->rChild->parent = node;
    _size += tree->_size;
    updateHeightAbove(node);
    tree->_root = nullptr;
    tree->_size = 0;
    delete tree;
    tree = nullptr;
    return node;
}

template<typename T>
template<typename VST>
void BinaryTree<T>::preOrderTraverse(BiNode(T)node, VST &visit) {
    stack<BiNode(T)> S;
    if (node) S.push(node);
    while (!S.empty()) {
        // node = S.pop();
        visit(node->data);
        break;
    }
}

#endif //DATASTRUCTURE_BINARYTREE_H
