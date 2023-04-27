//
// Created by Ziad Nasser on 2023-04-27.
//

#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

template <typename elementType>
SingleLinkedList<elementType>::SingleLinkedList() {
    first = last = nullptr;
    length = 0;
}

template <typename elementType>
void SingleLinkedList<elementType>::insertAtHead(elementType element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (isEmpty()) {
        first = last = newNode;
        newNode->next = nullptr;
    }
    else {
        newNode->next = first;
        first = newNode;
    }
    length++;
}

template <typename elementType>
void SingleLinkedList<elementType>::insertAtTail(elementType element) {
    Node* newNode = new Node;
    newNode->item = element;
    if (isEmpty()) {
        first = last = newNode;
        newNode->next = nullptr;
    }
    else {
        last->next = newNode;
        newNode->next = nullptr;
        last = newNode;
    }
    length++;
}

template <typename elementType>
void SingleLinkedList<elementType>::insertAt(elementType element, int index) {
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

template <typename elementType>
void SingleLinkedList<elementType>::removeAtHead() {
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
        length--;
    }
}

template <typename elementType>
void SingleLinkedList<elementType>::removeAtTail() {
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
        previous->next = nullptr;
        last = previous;
        length--;
    }
}


template<typename elementType>
void SingleLinkedList<elementType>::print() {
    Node* current = first;
    while(current != nullptr){
        cout<<current->item<<" ";
        current = current->next;
    }
}

template<typename elementType>
void SingleLinkedList<elementType>::clear() {
    Node *current = first;
    length = 0;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    first = last = nullptr;

}

template<typename elementType>
int SingleLinkedList<elementType>::SinglelinkedListSize() {
    return length;
}

template<typename elementType>
bool SingleLinkedList<elementType>::isEmpty() {
    return length ==0;
}

template<typename elementType>
bool SingleLinkedList<elementType>::isItemAtEqual(elementType element, int index) {
    if(index <0 || index>length){
        cout<<"out of range!";
    }else{
        Node* current = first;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->item == element;
    }
}

template<typename elementType>
bool SingleLinkedList<elementType>::isExist(elementType element) {
    Node* current = first;
    while(current != nullptr){
        if(current->item == element)
            return true;
        current = current-> next;
    }
    return false;
}

template<typename elementType>
void SingleLinkedList<elementType>::replaceAt(elementType newElement, int index) {
    if(index <0 || index>length){
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
elementType SingleLinkedList<elementType>::retrieveAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range!"<<endl;
        return elementType();
    }

    if (isEmpty()) {
        cout << "List is empty!";
        return elementType();
    }

    Node* current = first;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->item;
}

template<typename elementType>
void SingleLinkedList<elementType>::removeAt(int index) {
    if(index <0 || index>length){
        cout<<"out of range!";
    }
    else if(index==0){
        removeAtHead();
    }else if(index == length-1){
        removeAtTail();
    }else{
        Node* current = first;
        for(int i=0;i<index-1;i++){
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        length--;
    }
}
template class SingleLinkedList<int>;
template class SingleLinkedList<double>;
template class SingleLinkedList<string>;