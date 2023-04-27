//
// Created by Ziad Nasser on 2023-04-27.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#include <iostream>

using namespace std;
template <typename elementType>
class DoublyLinkedList{
private:
    struct Node{
        elementType item;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
    int length;
public:
    DoublyLinkedList();
    void insertAtHead (elementType element);

    void insertAtTail (elementType element);

    void insertAt (elementType element, int index);

    void insertAfter (Node* prev_node, elementType element);

    void removeAtHead ();

    void removeAtTail();

    void removeAt (int index);

    elementType retrieveAt (int index) ;

    void replaceAt (elementType newElement, int index);

    bool isExist (elementType element);

    bool isItemAtEqual (elementType element, int index);

//    void swap (int firstItemIdx, int secondItemIdx){}

    void reverse ();

    bool isEmpty ();

    int doubleLinkedListSize ();

    void clear ();

    void forwardTraversal ();

    void backwardTraversal ();
};


#endif //DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
