//
// Created by Ziad Nasser on 2023-04-27.
//

#include "StackLLBAsed.h"
template<typename elementType>
bool Stack<elementType>::isEmpty() {
    return topPtr== nullptr;
}

template<typename elementType>
void Stack<elementType>::push(elementType newItem) {
    StackNode* newPtr = new StackNode;
    if(newPtr == nullptr)cout<<"stack can't allocate memory"<<endl;
    else{
        newPtr ->item = newItem;
        newPtr->next = topPtr;
        topPtr = newPtr;
        size++;
    }
}

template<typename elementType>
elementType Stack<elementType>::pop() {
    if(isEmpty()){
        cout<<"stack is Empty"<<endl;
        return elementType();
    }
    else{
        elementType topElementValue = topPtr->item;
        StackNode* tmp = topPtr;
        topPtr = topPtr->next ;
        tmp->next = nullptr;
        delete tmp;
        size--;
        return topElementValue;
    }
}

template<typename elementType>
elementType Stack<elementType>::top() {
    if(isEmpty())
    {
        cout<<"stack is Empty"<<endl;
        return elementType();
    }
    else{
        return topPtr->item;
    }
}

template<typename elementType>
int Stack<elementType>::stackSize() {
    return size;
}

template<typename elementType>
void Stack<elementType>::clear() {
    while(!isEmpty()){
        pop();
    }
    size = 0;
}

template<typename elementType>
void Stack<elementType>::print() {
    StackNode* current = topPtr;
    while(current != nullptr){
        cout<<current->item<<" ";
        current = current->next;
    }
    cout<<endl;
}
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;