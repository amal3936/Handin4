#ifndef _SET_H_
#define _SET_H_

#include "binary_search_tree.h"

#include <iostream>
#include <stdexcept>

template<typename Comparable>
class Set {
private:
    struct BinaryNode {
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;

        BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt, BinaryNode* pt) :
            element{ theElement }, left{ lt }, right{ rt }, parent{ pt } {}
    };

    BinarySearchTree<Comparable> bst;

public:
    Set() {}

    ~Set() {}

    void insert(const Comparable& x) {
    }

    bool find(const Comparable& x) const {
        return bst.contains(x);
    }

    void erase(const Comparable& x) {
        bst.remove(x);
    }
};

#endif
