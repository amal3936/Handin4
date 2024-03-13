#include "MinHeapPriorityQueue.cpp"

int main() {
    vector<int> elements = {25, 5, 15, 10, 30};
    MinHeapPriorityQueue<int> pq(elements);

    cout << "Elements:" << endl;
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;

    cout << endl<< "New elements 30 and 35" << endl;
    pq.push(20);
    pq.push(35);

    cout << endl<< "Top: " << pq.top() << endl;
    pq.pop();
    cout << "New top: " << pq.top() << endl;

    cout << endl<<"Updated list of elements:" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
