#include <iostream>
#include <vector>
#include "priority_queue.h"
#include "../Opgave2/MinHeap1.cpp"

using namespace std;

template <typename T>
class MinHeapPriorityQueue : public PriorityQueue<T>
{
    MinHeap<int> heap;

public:
    MinHeapPriorityQueue()
    {
    }
    void push(const T &x) override
    {
        heap.insert(x);
    }
    void pop() override
    {
        heap.remove();
    }
    T top() override
    {
        return heap.peek();
    }
    bool empty() override
    {
        return heap.isEmpty();
    }
};