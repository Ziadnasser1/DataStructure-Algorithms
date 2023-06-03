//
// Created by Ziad Nasser on 2023-04-27.
//

#include "CircularLinkedList.h"

template<typename elementType>
CircularLinkedList<elementType>::CircularLinkedList() {
    first = last = nullptr;
    length = 0;
}

template<typename elementType>
void CircularLinkedList<elementType>::insertAtHead(elementType element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (isEmpty()) {
        first = last = newNode;
        newNode->next = first;
    }
    else {
        newNode->next = first;
        first = newNode;
        last->next = first;
    }
    length++;
}

template<typename elementType>
void CircularLinkedList<elementType>::insertAtTail(elementType element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (isEmpty()) {
        first = last = newNode;
        newNode->next = first;
    }
    else {
        last->next = newNode;
        newNode->next = first;
        last = newNode;
    }
    length++;
}

template<typename elementType>
void CircularLinkedList<elementType>::insertAt(elementType element, int index) {
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
            for (size_t i = 1; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            length++;
        }
    }
}

template<typename elementType>
void CircularLinkedList<elementType>::removeAtHead() {
    if (length == 0)
        return;
    else if (length == 1) {
        delete first;
        first = last = nullptr;
        length--;
    }
    else {
        Node* current = first;
        first = first->next;
        delete current;
        last->next = first;
        length--;
    }
}

template<typename elementType>
void CircularLinkedList<elementType>::removeAtTail() {
    if (length == 0)
        return;
    else if (length == 1) {
        delete first;
        first = last = nullptr;
        length--;
    }
    else {
        Node* current = first->next;
        Node* previous = first;
        while (current != last) {
            previous = current;
            current = current->next;
        }
        delete current;
        previous->next = first;
        last = previous;
        length--;
    }
}

template<typename elementType>
void CircularLinkedList<elementType>::removeAt(int index) {
    if (index < 0 || index > length) {
        cout << "out of range!";
    }
    else if (index == 0) {
        removeAtHead();
    }
    else if (index == length - 1) {
        removeAtTail();
    }
    else {
        Node* current = first;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        length--;
    }
}

template<typename elementType>
void CircularLinkedList<elementType>::print() {
    if (first == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = first;
    do {
        cout << current->item << " ";
        current = current->next;
    } while (current != first);
    cout<<endl;
}

template<typename elementType>
void CircularLinkedList<elementType>::clear() {
    if (first == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node *current = first->next;
    while (current != first) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete first;
    first = last = nullptr;
    length = 0;
}

template<typename elementType>
int CircularLinkedList<elementType>::CircularlinkedListSize() {
    return length;
}

template<typename elementType>
bool CircularLinkedList<elementType>::isEmpty() {
    return length ==0;
}

template<typename elementType>
bool CircularLinkedList<elementType>::isItemAtEqual(elementType element, int index) {
    if(index <0 || index>=length){
        cout<<"out of range!";
        return false;
    }else{
        Node* current = first;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->item == element;
    }
}

template<typename elementType>
bool CircularLinkedList<elementType>::isExist(elementType element) {
    Node* current = first;
    int cnt=0;
    while(current != nullptr){
        cnt++;
        if(current->item == element)
            return true;
        current = current-> next;
        if(cnt>length)
            return false;
    }
    return false;
}

template<typename elementType>
void CircularLinkedList<elementType>::replaceAt(elementType newElement, int index) {
    if(index <0 || index>=length){
        cout<<"out of range!";
    }else{
        Node* current = first;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->item = newElement;
    }
}

template<typename elementType>
elementType CircularLinkedList<elementType>::retrieveAt(int index) {
    if(index <0 || index>=length){
        cout<<"out of range!";
        return elementType();
    }else{
        Node* current = first;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->item;
    }
}
template class CircularLinkedList<int>;
template class CircularLinkedList<double>;
template class CircularLinkedList<string>;