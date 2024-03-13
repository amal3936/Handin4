#include "MinHeapPriorityQueue.cpp"

int main()
{
    MinHeapPriorityQueue<int> pq;
    pq.push(59);
    pq.push(44);
    pq.push(79);
    pq.push(17);
    pq.push(54);
    pq.push(32);
    pq.push(31);
    pq.push(12);
    pq.push(7);
    pq.push(4);
    pq.push(1);

    cout << "Top " << pq.top() << endl;

    pq.pop();
    cout << "Top " << pq.top() << endl;

    return 0;
}
