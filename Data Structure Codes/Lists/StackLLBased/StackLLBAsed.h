//
// Created by Ziad Nasser on 2023-04-27.
//

#ifndef STACKLLBASED_STACKLLBASED_H
#define STACKLLBASED_STACKLLBASED_H
#include <iostream>

using namespace std;

template <typename elementType>
class Stack{
    struct StackNode{
        elementType item;
        StackNode* next;
    };
    int size;
    StackNode* topPtr;
public:
    Stack();
    bool isEmpty();
    void push(elementType newItem);
    elementType pop();
    elementType top();
    int stackSize();
    void clear();
    void print();
};

template<typename elementType>
Stack<elementType>::Stack() {
        size = 0;
        topPtr= nullptr;
}


#endif //STACKLLBASED_STACKLLBASED_H
