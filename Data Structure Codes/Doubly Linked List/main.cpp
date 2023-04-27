#include <iostream>

#include "Doubly Linked List.h"

int main() {
    DoublyLinkedList<int> myLinkedList;

    myLinkedList.insertAtHead(5);
    myLinkedList.insertAtHead(10);
    myLinkedList.insertAtTail(20);
    myLinkedList.insertAt(15, 2);

    std::cout << "Forward Traversal: ";
    myLinkedList.forwardTraversal();
    std::cout << std::endl;

    std::cout << "Backward Traversal: ";
    myLinkedList.backwardTraversal();
    std::cout << std::endl;

    std::cout << "List size: " << myLinkedList.doubleLinkedListSize() << std::endl;

    std::cout << "Element at index 2: " << myLinkedList.retrieveAt(2) << std::endl;

    myLinkedList.replaceAt(25, 2);
    std::cout << "Element at index 2 after replacement: " << myLinkedList.retrieveAt(2) << std::endl;

    std::cout << "Is 10 in the list? " << myLinkedList.isExist(10) << std::endl;
    std::cout << "Is 30 in the list? " << myLinkedList.isExist(30) << std::endl;

    std::cout << "Removing element at head" << std::endl;
    myLinkedList.removeAtHead();

    std::cout << "Removing element at tail" << std::endl;
    myLinkedList.removeAtTail();

    std::cout << "Forward Traversal after removal: ";
    myLinkedList.forwardTraversal();
    std::cout << std::endl;

//    std::cout << "Swapping elements at index 1 and 2" << std::endl;
//    myLinkedList.swap(1, 2);
//
//    std::cout << "Forward Traversal after swapping: ";
//    myLinkedList.forwardTraversal();
//    std::cout << std::endl;

    std::cout << "Reversing the list" << std::endl;
    myLinkedList.reverse();

    std::cout << "Forward Traversal after reversing: ";
    myLinkedList.forwardTraversal();
    std::cout << std::endl;

    std::cout << "Backward Traversal after reversing: ";
    myLinkedList.backwardTraversal();
    std::cout << std::endl;

    myLinkedList.clear();

    std::cout << "Is the list empty? " << myLinkedList.isEmpty() << std::endl;

    return 0;
}
