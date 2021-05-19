//
// Created by Jerry on 2021/5/12.
//

#ifndef DATASTRUCTURE_BINARYNODE_H
#define DATASTRUCTURE_BINARYNODE_H

#define BiNode(T) BinaryNode<T>*
#define getHeight(p) ((p) ? (p)->height : -1)

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (& (x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (& (x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasTwoChildren(x) (HasLChild(x) && HasRChild(x))
#define isLeaf(x) (!HasTwoChildren(x))
#define siblingOf(p) (IsLChild(*(p)) ? (p)->parent->rChild : (p)->parent->lChild)
#define uncleOf(p) (IsLChild(*(p->parent)) ? (p)->parent->parnent->rChild : (p)->parent->parnent->lChild)

typedef enum {
    RBT_RED, RBT_BLACK
} RBTColor;

template<typename T>
class BinaryTree;

template<typename T>
class BinaryNode {
    friend class BinaryTree<T>;

private:
    BinaryNode<T> *parent, *lChild, *rChild;
    T data;
    int height;
    int npl;
    RBTColor color;
public:

    BinaryNode();

    BinaryNode(const T &, BiNode(T), BiNode(T), BiNode(T), int, int, RBTColor);

    int size();

    BiNode(T)insertAsLC(T const &);

    BiNode(T)insertAsRC(T const &);

    BiNode(T)successor();

    template<typename VST>
    void preOrderTraverse(VST &);

    template<typename VST>
    void inOrderTraverse(VST &);

    template<typename VST>
    void postOrderTraverse(VST &);

    template<typename VST>
    void levelTraverse(VST &);

    bool operator<(const BinaryNode<T> &);

    bool operator<=(const BinaryNode<T> &);

    bool operator>(const BinaryNode<T> &);

    bool operator>=(const BinaryNode<T> &);

    bool operator==(const BinaryNode<T> &);

};

template<typename T>
BinaryNode<T>::BinaryNode():parent(nullptr), lChild(nullptr), rChild(nullptr), height(0), npl(1), color(RBT_RED) {}

template<typename T>
BinaryNode<T>::BinaryNode(const T &data, BiNode(T)parent, BiNode(T)lChild,
                          BiNode(T)rChild, int height, int npl, RBTColor color):data(data), parent(parent),
                                                                                lChild(lChild), rChild(rChild),
                                                                                height(height), npl(npl), color(color) {
}

template<typename T>
int BinaryNode<T>::size() {
    int s = 1;
    if (lChild) s += lChild->size();
    if (rChild) s += rChild->size();
    return s;
}

template<typename T>
BiNode(T)BinaryNode<T>::insertAsLC(const T &lcData) {
    return lChild = new BinaryNode<T>(this, lcData);
}

template<typename T>
BiNode(T)BinaryNode<T>::insertAsRC(const T &rcData) {
    return rChild = new BinaryNode<T>(this, rcData);
}

template<typename T>
BiNode(T)BinaryNode<T>::successor() {

}


template<typename T>
template<typename VST>
void BinaryNode<T>::preOrderTraverse(VST &) {

}

template<typename T>
template<typename VST>
void BinaryNode<T>::inOrderTraverse(VST &vst) {

}

template<typename T>
template<typename VST>
void BinaryNode<T>::postOrderTraverse(VST &) {

}

template<typename T>
template<typename VST>
void BinaryNode<T>::levelTraverse(VST &) {
}


template<typename T>
bool BinaryNode<T>::operator<(const BinaryNode<T> &another) {
    return data < another.data;
}

template<typename T>
bool BinaryNode<T>::operator<=(const BinaryNode<T> &another) {
    return data <= another.data;
}

template<typename T>
bool BinaryNode<T>::operator>(const BinaryNode<T> &another) {
    return data > another.data;
}

template<typename T>
bool BinaryNode<T>::operator>=(const BinaryNode<T> &another) {
    return data >= another.data;
}

template<typename T>
bool BinaryNode<T>::operator==(const BinaryNode<T> &another) {
    return data == another.data;
}


#endif //DATASTRUCTURE_BINARYNODE_H
