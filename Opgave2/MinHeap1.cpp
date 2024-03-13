#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief Min-Heap Class
 *
 * @tparam T
 */
template <typename T>
class MinHeap
{
    std::vector<T> heap;

public:
    /**
     * @brief Inserts an element and updates the Heap
     *
     * @param x Element to insert
     */
    void insert(const T &x)
    {
        // YOUR CODE GOES HERE
        heap.push_back(x);

        // heapify up process
        int i = heap.size() - 1;
        percolateUp(i);
    }

    /**
     * @brief Remove minimum (top) element and update Heap
     *
     */
    void remove()
    {
        if (heap.empty())
            return;

        heap[0] = std::move(heap.back());
        heap.pop_back();
        percolateDown(0);
    }

    /**
     * @brief Inspect if Heap is empty
     *
     * @return true Heap is empty
     * @return false Heap is not empty
     */
    bool isEmpty()
    {
        return heap.empty();
    }

    /**
     * @brief Access the minimum (top) element of the Heap
     *
     * @return T Minimum element in Heap
     */
    T peek()
    {
        // YOUR CODE GOES HERE
        if (!heap.empty())
            return heap[0];
        return T();
    }

    void printHeap()
    {
        for (auto &i : heap)
        {
            cout << i << " ";
        }
        cout << endl;
    }

private:
    /**
     * @brief Recursive function to percolate node up
     *
     * @param i Index for node to percolate
     */
    void percolateUp(int i)
    {
        if (i <= 0)
            return;

        int p = parent(i);
        if (heap[p] <= heap[i])
        {
            return;
        }

        std::swap(heap[p], heap[i]);
        percolateUp(p);
    }

    /**
     * @brief Recursive function to percolate node down
     *
     * @param i Index for node to percolate
     */
    void percolateDown(int i)
    {
        if (heap.size() == i)
            return;

        int smallestNr = smallest(i);
        if (heap[i] <= heap[smallestNr])
            return;

        std::swap(heap[i], heap[smallestNr]);
        percolateDown(smallestNr);
    }

    /**
     * @brief Returns index of smallest value
     *        of i and its children
     *
     * @param i Index in Heap array
     * @return int Index to smallest value
     */
    int smallest(int i) const
    {
        int small = i;

        if (left(i) < heap.size() &&
            heap[i] > heap[left(i)])
            small = left(i);

        if (right(i) < heap.size() &&
            heap[i] > heap[right(i)] &&
            heap[right(i)] < heap[left(i)])
            small = right(i);

        return small;
    }

    /**
     * @brief Swaps values in data array
     *
     * @param i1 Array index 1 to swap with 2
     * @param i2 Array index 2 to swap with 1
     */
    void swap(int i1, int i2)
    {
        T temp = heap[i1];
        heap[i1] = heap[i2];
        heap[i2] = temp;
    }

    size_t parent(int i) const { return (i - 1) / 2; }
    size_t left(int i) const { return 2 * i + 1; }
    size_t right(int i) const { return 2 * i + 2; }
};