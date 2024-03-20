#include <vector>
#include "binary_search_tree.h"

using namespace std;

template <typename Comparable>
class Set
{
private:
    size_t theSize;
    BinarySearchTree<Comparable> tree;

public:
    Set() {}

    ~Set() { clear(); }

    Set(const Set &s) : tree(s.tree)
    {
        // TO BE IMPLEMENTED
    }

    void clear()
    {
        // TO BE IMPLEMENTED
        iterator it = this->begin();
        while (!empty()) // ADDED
        {
            it = erase(it);
        }
    }

    size_t size() const
    {
        // TO BE IMPLEMENTED
        return theSize; // ADDED
    }

    bool empty() const
    {
        // TO BE IMPLEMENTED
        return tree.isEmpty(); // ADDED
    }

    void push(const Comparable &t)
    {
        // TO BE IMPLEMENTED
        tree.insert(t); // ADDED
    }

    void print()
    {
        tree.printTree();
    }

    friend class BinarySearchTree<Comparable>;
    typedef typename BinarySearchTree<Comparable>::iterator iterator;

    iterator begin() const
    {
        // TO BE IMPLEMENTED
        return iterator(tree.findMin()); // ADDED find minimum value in tree
    }

    iterator end() const
    {
        // TO BE IMPLEMENTED
        return tree.findMax(); // ADDED find minimum value in tree
    }

    iterator insert(const Comparable &t)
    {
        // TO BE IMPLEMENTED
        return tree.insert(t); // ADDED
    }

    iterator find(const Comparable &t)
    {
        // TO BE IMPLEMENTED
        return tree.find(t); // ADDED
    }

    iterator erase(iterator &itr)
    {
        // TO BE IMPLEMENTED
        return tree.erase(itr); // ADDED
    }
};
