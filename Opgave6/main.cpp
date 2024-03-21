//////////////////////////////////////
// copy of the given 6_set_template //
//////////////////////////////////////

#include <iostream>
#include "set.h"

int main()
{
    cout << endl << "____________________________" << endl << "Test 1: int set" << endl << "____________________________" << endl;
    Set<int> set;
    cout << "Set: ";
    set.print();

    cout << endl << "____________________________" << endl <<"Test 2: push()" << endl << "____________________________" << endl;
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

    cout << "Set: "<<endl;
    set.print();

    cout << endl << "____________________________" << endl << "Test 3: Copy of set" << endl << "____________________________" << endl;
    Set<int> set2 = set;
    cout << "Copy of the set: " << endl;
    set2.print();

    cout << endl << "________________________________________" << endl << "Test 4: inserting a negative number -1: "<< endl << "________________________________________" << endl;
    Set<int>::iterator it = set2.insert(-1);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;

    cout << endl << "____________________________________" << endl << "Test 5: inserting a duplicate of 4: "<< endl << "____________________________________" << endl;
    // Insert duplicate and print succ to prove that no new node is inserted
    it = set2.insert(4);
    cout << *it << endl;
    if (++it != set2.end())
        cout << *it << endl;
    cout << "If " << *it << " != 4, succes!";

    cout << endl << "____________________________" << endl << "Test 6: insert new max: "<< endl << "____________________________" << endl;
    it = set2.insert(20);
    cout << *it << endl;
    if (++it != set2.end())
        cout << "++it: " << *it << endl;
    cout << "No print in test 5 = succes" << endl;

    cout << endl << "____________________________" << endl <<  "Test 7: find(15): "<< endl << "____________________________" << endl;
    it = set2.find(15);
    if (it == nullptr)
    {
        cout << "no match" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    cout << endl << "____________________________" << endl << "Test 8: find(12): "<< endl << "____________________________" << endl;
    it = set2.find(12);
    if (it == nullptr)
    {
        cout << "no match" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    cout << endl << "____________________________" << endl << "Test 9: erase(it): "<< endl << "____________________________" << endl;
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

    cout << endl << "_________________________________" << endl <<  "Test 10: find(4) = "<< endl << "_________________________________" << endl;
    it = set2.find(4);
    cout << *it << ", erase(4):";
    it = set2.erase(it);
    if (it != set2.end())
        cout << "After erase, it = " << *it << endl;

    cout << endl << "____________________________" << endl <<  "Test 11: print all" << endl << "____________________________" << endl;
    set2.print();
}
