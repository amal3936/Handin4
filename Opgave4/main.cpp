#include "MinHeapPriorityQueue.cpp"

int main() {
    vector<int> elements = {25, 5, 15, 10, 20};
    MinHeapPriorityQueue<int> pq(elements);

    cout << "Elements:" << endl;
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;

    cout << endl<< "New elements: 30, 0" << endl;
    pq.push(30);
    pq.push(0);

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
