#include <iostream>
#include "circularLinkedList.h"

using namespace std;

int main() {
    CircularLinkedList<int> myList;

    // Test insertAtHead function
    myList.insertAtHead(5);
    myList.insertAtHead(10);
    myList.print(); // expected output: 10 5

    // Test insertAtEnd function
    myList.insertAtTail(20);
    myList.insertAtTail(15);
    myList.print(); // expected output: 10 5 20 15

    // Test insertAt function
    myList.insertAt(25, 2);
    myList.insertAt(30, 4);
    myList.print(); // expected output: 10 5 25 20 30 15

    // Test removeAtHead function
    myList.removeAtHead();
    myList.print(); // expected output: 5 25 20 30 15

    // Test removeAtEnd function
    myList.removeAtTail();
    myList.print(); // expected output: 5 25 20 30

    // Test removeAt function
    myList.removeAt(1);
    myList.print(); // expected output: 5 20 30

    // Test retrieveAt function
    int retrieved = myList.retrieveAt(1);
    cout << "Retrieved element: " << retrieved << endl; // expected output: 20

    // Test replaceAt function
    myList.replaceAt(35, 2);
    myList.print(); // expected output: 5 20 35

    // Test isExist function
    bool exists = myList.isExist(30);
    cout << "30 exists: " << exists << endl; // expected output: 1 (true)

    // Test isItemAtEqual function
    bool isEqual = myList.isItemAtEqual(35, 2);
    cout << "Item at index 1 is equal to 35: " << isEqual << endl; // expected output: 1 (true)

    // Test swap function
//    myList.swap(0, 2);
//    myList.print(); // expected output: 30 35 5

    // Test isEmpty function
    bool empty = myList.isEmpty();
    cout << "List is empty: " << empty << endl; // expected output: 0 (false)

    // Test circularLinkedListSize function
    int size = myList.CircularlinkedListSize();
    cout << "List size: " << size << endl; // expected output: 3

    // Test clear function
    myList.clear();
    myList.print(); // expected output: (List is empty)

    return 0;
}
