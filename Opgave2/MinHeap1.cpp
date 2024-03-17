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
    std::vector<T> heap; // Vektor til at gemme heap-elementer

public:
    /**
     * @brief Indsætter et element og opdaterer heap'en
     *
     * @param x Elementet der skal indsættes
     */
    void insert(const T &x)
    {
        // Tilføj det nye element til slutningen af vektoren
        heap.push_back(x);

        // // Opdaterer heap'en opad
        int i = heap.size() - 1;
        percolateUp(i);
    }

    /**
     * @brief Fjerner minimum (øverste) element og opdaterer heap'en
     *
     */
    void remove()
    {
        if (heap.empty())
            return;
        // Erstat det øverste element med det sidste element i vektoren
        heap[0] = std::move(heap.back());
        heap.pop_back();
        // Opdater heap'en nedad
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
        // Returner det øverste element i heap'en, hvis den ikke er tom
        if (!heap.empty())
            return heap[0];
        return T(); // Returner en standardværdi for typen T, hvis heap'en er tom
    }

    // Udskriver hele heap'en
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
            // Hvis indeks er 0 eller mindre, er det allerede roden, og ingen yderligere handling er nødvendig

        int p = parent(i);// Finder indekset for forældrenoden
        if (heap[p] <= heap[i])// Hvis forældrenoden er mindre end eller lig med den aktuelle node, er heap-egenskaben opretholdt
        {
            return; // Vi ikke behøver at foretage nogen yderligere ændringer
        }
        }

        std::swap(heap[p], heap[i]);// Hvis forældrenoden er større end den aktuelle node, skal vi bytte dem for at genoprette heap-egenskaben
        percolateUp(p); // Rekursivt kald til percolateUp på forældrenoden for at fortsætte percolating opad
    }

    /**
     * @brief Recursive function to percolate node down
     *
     * @param i Index for node to percolate
     */
    void percolateDown(int i)
    {
        // Base Case 1: Hvis indeks er lig med størrelsen af heap'en, er der ingen yderligere børn at percolate med, så vi afslutter rekursionen
        if (heap.size() == i)
            return;

        // Finder indekset for det mindste barn
        int smallestNr = smallest(i);
        // Hvis den aktuelle node er mindre end eller lig med det mindste barn, er heap-egenskaben opretholdt, så afslut rekursionen
        if (heap[i] <= heap[smallestNr])
            return;
        // Hvis den aktuelle node er større end det mindste barn, skal vi bytte dem for at genoprette heap-egenskaben
        std::swap(heap[i], heap[smallestNr]);
        // Rekursivt kald til percolateDown på det mindste barn for at fortsætte percolating nedad
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

    size_t parent(int i) const { return (i - 1) / 2; } // Finder indeks for forældrenoden
    size_t left(int i) const { return 2 * i + 1; } // Finder indeks for venstre barn
    size_t right(int i) const { return 2 * i + 2; }  // Finder indeks for højre barn
};