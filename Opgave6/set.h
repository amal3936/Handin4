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

    //Efterladt tom da det sker i binary_search_tree
    Set(const Set &s) : tree(s.tree)
    {
    }

    void clear()
    {
        iterator it = this->begin();
        while (!empty())
        {
            it = erase(it);
        }
    }

    size_t size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return tree.isEmpty();
    }

    void push(const Comparable &t)
    {
        tree.insert(t);
    }

    void print()
    {
        tree.printTree();
    }

    friend class BinarySearchTree<Comparable>;
    typedef typename BinarySearchTree<Comparable>::iterator iterator;

    //Anvender minimum da denne er start
    iterator begin() const
    {
        return iterator(tree.findMin());
    }

    //Anvender maksimum da denne er slut
    iterator end() const
    {
        return tree.findMax(); 
    }

    iterator insert(const Comparable &t)
    {
        return tree.insert(t);
    }

    iterator find(const Comparable &t)
    {
        return tree.find(t);
    }

    iterator erase(iterator &itr)
    {
        return tree.erase(itr);
    }
};
