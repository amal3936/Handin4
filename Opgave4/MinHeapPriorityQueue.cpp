#include <iostream>
#include <vector>
#include "priority_queue.h"
#include "../Opgave3/MinHeap.cpp"

using namespace std;

template<typename T>
class MinHeapPriorityQueue : public PriorityQueue<T>, public MinHeap<T> {
public:
    MinHeapPriorityQueue(vector<T>& elements) : MinHeap<T>(elements) {}

    void push(const T& x) override {
        this->heapArray.push_back(x);
    }

    void pop() override {
        if (!this->isEmpty()) {
            MinHeap<T>::remove();
        } else {
            throw out_of_range("Priority queue is empty");
        }
    }

    T top() override {
        if (!this->isEmpty()) {
            return MinHeap<T>::peek();
        } else {
            throw out_of_range("Priority queue is empty");
        }
    }

    bool empty() const override {
        return MinHeap<T>::isEmpty();
    }
};