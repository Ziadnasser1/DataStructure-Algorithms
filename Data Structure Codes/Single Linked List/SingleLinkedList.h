//
// Created by Ziad Nasser on 2023-04-27.
//

#ifndef SINGLE_LINKED_LIST_SINGLELINKEDLIST_H
#define SINGLE_LINKED_LIST_SINGLELINKEDLIST_H
#include <iostream>

using namespace std;
template <typename elementType>
class SingleLinkedList {
private:
    struct Node {
        elementType item;
        Node* next;
    };
    Node* first;
    Node* last;
    int length;
public:
    SingleLinkedList();
    void insertAtHead(elementType element);
    void insertAtTail(elementType element);
    void insertAt(elementType element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    elementType retrieveAt(int index);
    void replaceAt(elementType newElement, int index);
    bool isExist(elementType element);
    bool isItemAtEqual(elementType element, int index);
//    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int SinglelinkedListSize();
    void clear();
    void print();
};


#endif //SINGLE_LINKED_LIST_SINGLELINKEDLIST_H
