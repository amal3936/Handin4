#include <iostream>
#include "set.h"

int main()
{
    cout << "Test 1: init set" << endl;
    Set<int> set;
    cout << "Test 2: push()" << endl;
    set.push(4);
    set.push(0);
    set.push(2);
    set.push(7);
    set.push(0);
    set.push(2);
    set.push(6);
    set.push(4);
    set.push(12);
    set.push(11);
    set.push(8);
    set.push(1);
    set.push(5);
    set.push(0);
    set.push(3);
    set.push(2);
    set.push(7);
    set.push(1);
    set.push(1);
    set.push(1);
    set.push(9);
    set.push(7);
    set.push(11);
    set.push(1);

    cout << "Test 3: init set2 = set" << endl;
    Set<int> set2 = set;

    cout << "Test 4: insert -1: ";
    Set<int>::iterator it = set2.insert(-1);
    cout << *it << endl;
    if (++it != set2.end())
        cout << *it << endl;

    cout << "Test 5: insert duplicate of 4: ";
    // Insert duplicate and print succ to prove that no new node is inserted
    it = set2.insert(4);
    cout << *it << endl;
    if (++it != set2.end())
        cout << *it << endl;
    cout << "If " << *it << " != 4, succes!" << endl;

    cout << "Test 6: insert new max: ";
    it = set2.insert(20);
    cout << *it << endl;
    if (++it != set2.end())
        cout << "++it: " << *it << endl;
    cout << "No print in test 5 = succes" << endl;

    cout << "Test 7: find(15): ";
    it = set2.find(15);
    if (it == nullptr)
    {
        cout << "no match" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    cout << "Test 8: find(12): ";
    it = set2.find(12);
    if (it == nullptr)
    {
        cout << "no match" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    cout << "Test 9: erase(it): ";
    it = set2.erase(it);
    if (it != nullptr)
        cout << "After erase, it = " << *it << endl;
    cout << "find(12): ";
    it = set2.find(12);
    if (it == nullptr)
    {
        cout << "no match" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    cout << "Test 10: find(4) = ";
    it = set2.find(4);
    cout << *it << ", erase(4):";
    it = set2.erase(it);
    if (it != set2.end())
        cout << "After erase, it = " << *it << endl;

    cout << "Test 9: print all using it: --NOT WORKING-- ";
    set2.print();
    cout << endl;
}
