#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main()
{
    SingleLinkedList<int> list;

    // insert elements
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(50);
    list.insertAtTail(30);
    list.insertAt(40, 2);

    // print the list
    cout << "List contents: ";
    list.print();
    cout<<endl;

    // remove elements
    list.removeAtHead();
    list.removeAtTail();
    list.removeAt(1);

    // print the list
    cout << "List contents after removing elements: ";
    list.print();
    cout<<endl;

    // retrieve and replace elements
    int elem1 = list.retrieveAt(5);
    int elem2 = list.retrieveAt(1);
    list.replaceAt(50, 0);
    list.replaceAt(60, 1);

    // print the list
    cout << "List contents after retrieving and replacing elements: ";
    list.print();
    cout<<endl;

    // check if elements exist in the list
    bool elem3Exists = list.isExist(30);
    bool elem4Exists = list.isExist(50);

    // print the existence of elements
    cout << "Does 30 exist in the list? " << (elem3Exists ? "Yes" : "No") << endl;
    cout << "Does 50 exist in the list? " << (elem4Exists ? "Yes" : "No") << endl;

//    // swap elements
//    list.swap(0, 1);
//
//    // print the list
//    cout << "List contents after swapping elements: ";
//    list.print();


    // print whether the list is empty
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    // get the size of the list
    int size = list.SinglelinkedListSize();

    // print the size of the list
    cout << "Size of the list: " << size << endl;

    // clear the list
    list.clear();

    // print the list after clearing it
    cout << "List contents after clearing it: ";
    list.print();
    cout<<endl;
    // print whether the list is empty
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
