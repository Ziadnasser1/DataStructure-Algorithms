#include <iostream>
#include "ArrayBasedList.h"

int main() {
    // create a list with capacity of 5
    ArrayBasedList<int> list(5);

    // test insert function
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);  // should print "list is full!"

    cout<<"list contain: ";
    list.print();
    cout<<endl;

    // test insertAt function
    list.insertAt(25, 2);  // insert 25 at index 2
    list.insertAt(15, 1);  // insert 15 at index 1
    list.insertAt(5, 0);   // insert 5 at index 0
    list.insertAt(70, 7);  // insert 70 at index 7

    cout<<"list contain: ";
    list.print();
    cout<<endl;

    // test retrieveAt function
    cout << list.retrieveAt(2) << endl;  // should print 15
    cout << list.retrieveAt(11) << endl;  // should print "out of range!" and 0

    // test removeAt function
    list.removeAt(4);  // remove element at index 4
    list.removeAt(0);  // remove element at index 0
    list.removeAt(11);  // should print "out of range!"

    cout<<"list contain: ";
    list.print();
    cout<<endl;

    // test replaceAt function
    list.replaceAt(35, 2);  // replace element at index 2 with 35
    list.replaceAt(45, 4);  // replace element at index 4 with 45
    list.replaceAt(55, 11);  // should print "out of range!"

    cout<<"list contain: ";
    list.print();
    cout<<endl;

    // test isItemAtEqual function
    cout << list.isItemAtEqual(35, 2) << endl;  // should print true
    cout << list.isItemAtEqual(45, 4) << endl;  // should print true
    cout << list.isItemAtEqual(55, 11) << endl;  // should print "out of range!" and false

    // test other functions
    cout << list.isEmpty() << endl;  // should print false
    cout << list.isFull() << endl;   // should print false
    cout << list.listSize() << endl; // should print 7
    cout << list.maxListSize() << endl;  // should print 10

    //test clear function
    list.clear();
    cout << list.isEmpty() << endl;  // should print true

    return 0;
}
