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
    // Tilføjer et element til prioritetskøen
    void push(const T &x) override
    {
        heap.insert(x);
    }
    // Fjerner det øverste element fra prioritetskøen
    void pop() override
    {
        heap.remove();
    }
    // Returnerer det mindste element uden at fjerne det
    T top() override
    {
        return heap.peek();
    }
    // Undersøger om prioritetskøen er tom
    bool empty() override
    {
        return heap.isEmpty();
    }
};