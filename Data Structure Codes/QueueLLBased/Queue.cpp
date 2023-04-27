//
// Created by Ziad Nasser on 2023-04-27.
//

#include "Queue.h"

template<typename elementType>
Queue<elementType>::Queue() {
    size = 0;
    frontPtr = rearPtr = nullptr;
}

template<typename elementType>
bool Queue<elementType>::isEmpty() {
    return size==0;
}

template<typename elementType>
void Queue<elementType>::enqueue(elementType element) {
    auto newNode = new QueueNode;
    newNode->item = element;
    newNode->next = nullptr;
    if(isEmpty()){
        rearPtr = frontPtr = newNode;
    }
    else{
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    size++;
}

template<typename elementType>
elementType Queue<elementType>::dequeue() {
    if(isEmpty())
    {
        cout<<"queue is Empty!"<<endl;
        return elementType();
    }
    else{
        auto tmp = frontPtr;
        elementType newItem = frontPtr->item;
        frontPtr = frontPtr->next;
        delete tmp;
        size--;
        if (isEmpty()) rearPtr = nullptr;
        return newItem;
    }
}

template<typename elementType>
elementType Queue<elementType>::front() {
    if(isEmpty())
    {
        cout<<"queue is Empty!"<<endl;
        return -1;
    }
    else{
        return frontPtr->item;
    }
}

template<typename elementType>
elementType Queue<elementType>::rear() {
    if(isEmpty())
    {
        cout<<"queue is Empty!"<<endl;
        return -1;
    }
    else{
        return rearPtr->item;
    }
}

template<typename elementType>
void Queue<elementType>::print() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    QueueNode * current = frontPtr;
    while(current!= nullptr){
        cout<<current->item<<" ";
        current = current->next;
    }
    cout<<endl;
}

template<typename elementType>
void Queue<elementType>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<typename elementType>
int Queue<elementType>::Size() {
    return size;
}

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;