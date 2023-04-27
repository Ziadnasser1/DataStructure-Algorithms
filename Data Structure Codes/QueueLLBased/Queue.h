//
// Created by Ziad Nasser on 2023-04-27.
//

#ifndef QUEUELLBASED_QUEUE_H
#define QUEUELLBASED_QUEUE_H
#include <iostream>

using namespace std;

template <typename elementType>
class Queue{
    struct QueueNode{
        elementType item;
        QueueNode* next;
    };
    int size;
    QueueNode *frontPtr, *rearPtr;
public:
    Queue();
    bool isEmpty();
    void enqueue(elementType element);
    elementType dequeue();

    elementType front();
    elementType rear();

    void print();
    void clear();
    int Size();
};



#endif //QUEUELLBASED_QUEUE_H
