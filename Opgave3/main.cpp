#include "MinHeap1.cpp"
#include <iostream>
using namespace std;

int main()
{
    // Testprogram
    MinHeap<int> heap;
    heap.insert(59);
    heap.insert(44);
    heap.insert(79);
    heap.insert(17);
    heap.insert(54);
    heap.insert(32);
    heap.insert(31);
    heap.insert(12);
    heap.insert(7);
    heap.insert(4);
    heap.insert(1);

    cout << "Heap after insertion: " << endl;
    heap.printHeap();

    heap.remove();
    cout << "Heap after remove: " << endl;
    heap.printHeap();
}