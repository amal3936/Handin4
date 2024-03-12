#include <iostream>
#include <vector>
#include <algorithm>

// Hjælpefunktioner til beregning af child indeks
inline size_t leftChild(size_t i) { return 2 * i + 1; }
inline size_t rightChild(size_t i) { return 2 * i + 2; }

template<typename T>
class MinHeap {
public:
    // Constructor, der bygger min-heap, svarende til Slide 30
   public:
    // Constructor, minHeapify, isEmpty, peek, remove
    MinHeap(std::vector<T>& array) : heapArray(array) {
        for (int i = heapArray.size() / 2 - 1; i >= 0; --i)
            minHeapify(heapArray, i, heapArray.size());
    }

    // MinHeapify-metoden, som svarer til Slide 30
    void minHeapify(std::vector<T>& array, int node, int n) {
        int child;
        T tmp = std::move(array[node]);
        for (; leftChild(node) < n; node = child) {
            child = leftChild(node);
            if (child != n - 1 && array[rightChild(node)] < array[child])
                child = rightChild(node);
            if (array[child] < tmp)
                array[node] = std::move(array[child]);
            else
                break;
        }
        array[node] = std::move(tmp);
    }

    // Tjekker om min-heap er tom, svarende til Slide 29
    bool isEmpty() const {
        return heapArray.empty();
    }

    // Returnerer det mindste element uden at fjerne det, svarende til Slide 29
    T peek() const {
        if (!isEmpty()) {
            return heapArray[0];
        }
        return T(); // Returnerer en standardværdi, hvis heapen er tom
    }

    // Fjerner det mindste element fra min-heapen, svarende til Slide 29
    void remove() {
        if (!isEmpty()) {
            heapArray[0] = std::move(heapArray.back());
            heapArray.pop_back();
            minHeapify(heapArray, 0, heapArray.size());
        }
    }

protected:
    std::vector<T>& heapArray;
};

// Funktion til at anvende heapsort, som svarer til Slide 29
template<typename T>
std::vector<T> heapsort(std::vector<T>& array) {
    MinHeap<T> heap(array); // Bygger min-heap
    std::vector<T> sortedArray;

    // Indsætter det mindste element fra min-heapen i det oprindelige array
    while (!heap.isEmpty()) {
        T smallest = heap.peek(); // tjekker mindste værdi
        heap.remove(); // Fjern det fra min-heapen
        sortedArray.push_back(smallest); // Tilføj det til det sorterende array
    }

    return sortedArray;
}
