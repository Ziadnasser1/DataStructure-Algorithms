//
// Created by Ziad Nasser on 2023-04-27.
//

#include "Doubly Linked List.h"

template<typename elementType>
DoublyLinkedList<elementType>::DoublyLinkedList() {
    first = last = nullptr;
    length = 0;
}

template<typename elementType>
void DoublyLinkedList<elementType>::insertAtHead(elementType element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (length == 0) {
        first = last = newNode;
        newNode->next = newNode->prev = nullptr;
    }
    else {
        newNode->next = first;
        newNode->prev = nullptr;
        first->prev = newNode;
        first = newNode;
    }
    length++;
}

template<typename elementType>
void DoublyLinkedList<elementType>::insertAtTail(elementType element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (length == 0) {
        first = last = newNode;
        newNode->next = newNode->prev = nullptr;
    }
    else {
        newNode->next = nullptr;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    length++;
}

template<typename elementType>
void DoublyLinkedList<elementType>::insertAt(elementType element, int index) {
    if (index < 0 || index > length)
        cout << "out of range!";
    else {
        Node* newNode = new Node;
        newNode->item = element;
        if (index == 0)
            insertAtHead(element);
        else if (index == length)
            insertAtTail(element);
        else {
            Node* current = first;
            for (int i = 1; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            length++;
        }
    }
}

template<typename elementType>
void DoublyLinkedList<elementType>::insertAfter(Node* prev_node, elementType element) {
    if (prev_node == nullptr) {
        cout << "The given node cannot be null" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->item = element;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;
    if (newNode->next != nullptr)
        newNode->next->prev = newNode;
    else
        last = newNode;
    length++;
}

template<typename elementType>
void DoublyLinkedList<elementType>::removeAtHead() {
    if (length == 0)
        cout << "list is empty!";
    else if (length == 1) {
        delete first;
        last = first = nullptr;
        length--;
    }
    else {
        Node* current = first;
        first = first->next;
        first->prev = nullptr;
        delete current;
    }
    length--;
}

template<typename elementType>
void DoublyLinkedList<elementType>::removeAtTail() {
    if (length == 0)
        cout << "list is empty!";
    else if (length == 1) {
        delete first;
        last = first = nullptr;
        length--;
    }
    else {
        Node* current = last;
        last = last->prev;
        last->next = nullptr;
        delete current;
    }
    length--;
}


template<typename elementType>
void DoublyLinkedList<elementType>::backwardTraversal() {
    Node* current = last;
    while (current != nullptr) {
        cout << current->item << " ";
        current = current->prev;
    }
}

template<typename elementType>
void DoublyLinkedList<elementType>::forwardTraversal() {
    Node* current = first;
    while(current != nullptr) {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
}

template<typename elementType>
void DoublyLinkedList<elementType>::clear() {
    Node *current = first;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    first = last = nullptr;
    length = 0;
}

template<typename elementType>
int DoublyLinkedList<elementType>::doubleLinkedListSize() {
    return length;
}

template<typename elementType>
bool DoublyLinkedList<elementType>::isEmpty() {
    return first== nullptr;
}

template<typename elementType>
void DoublyLinkedList<elementType>::reverse() {
    if (length <= 1) {
        return;
    }
    Node* current = first;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = first;
    first = last;
    last = temp;
}

template<typename elementType>
bool DoublyLinkedList<elementType>::isItemAtEqual(elementType element, int index) {
    if(index < 0 || index >= length){
        cout << "out of range!";
        return false;
    }
    Node* current = first;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->item == element;
}

template<typename elementType>
void DoublyLinkedList<elementType>::replaceAt(elementType newElement, int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range." << endl;
        return;
    }

    Node* current = first;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->item = newElement;
}

template<typename elementType>
bool DoublyLinkedList<elementType>::isExist(elementType element) {
    Node* current = first;
    while (current != nullptr) {
        if (current->item == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename elementType>
elementType DoublyLinkedList<elementType>::retrieveAt(int index) {
    if (index < 0 || index >= length) {
        cout << "out of range!";
        return elementType();
    }
    else{
        Node* current = first;
        for (int i = 0; i < index; ++i) {
            current = current -> next;
        }
        return current->item;
    }
}

template<typename elementType>
void DoublyLinkedList<elementType>::removeAt(int index) {
    if(index<0 || index>length)
        cout<<"out of range!";
    else if(index==0)
        removeAtHead();
    else if(index== length)
        removeAtTail();
    else{
        Node* current = first->next;
        for (int i = 1; i < index; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    length--;
}
template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<string>;