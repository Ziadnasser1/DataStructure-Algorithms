#include <iostream>
#include "../../../Data Structure Codes/Lists/QueueLLBased/Queue.cpp"
#include "../../../Data Structure Codes/Lists/QueueLLBased/Queue.h"

template <typename elementType>
class Stack {
    Queue<elementType> q1, q2;
    int size;
public:
    Stack();
    void push(elementType element);
    elementType pop();
    elementType top();
    bool isEmpty();
    int getSize();
};

template <typename elementType>
Stack<elementType>::Stack() {
    size = 0;
}

template <typename elementType>
void Stack<elementType>::push(elementType element) {
    q2.enqueue(element);
    while (!q1.isEmpty()) {
        q2.enqueue(q1.front());
        q1.dequeue();
    }
    Queue<elementType> temp = q1;
    q1 = q2;
    q2 = temp;
    size++;
}

template <typename elementType>
elementType Stack<elementType>::pop() {
    if (isEmpty()) {
        throw "Stack is empty";
    }
    elementType element = q1.front();
    q1.dequeue();
    size--;
    return element;
}

template <typename elementType>
elementType Stack<elementType>::top() {
    if (isEmpty()) {
        throw "Stack is empty";
    }
    return q1.front();
}

template <typename elementType>
bool Stack<elementType>::isEmpty() {
    return size == 0;
}

template <typename elementType>
int Stack<elementType>::getSize() {
    return size;
}



int main() {
    Stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element of stack: " << myStack.top() << std::endl;

    myStack.pop();
    std::cout << "Top element of stack after pop operation: " << myStack.top() << std::endl;

    myStack.push(40);
    std::cout << "Top element of stack after push operation: " << myStack.top() << std::endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();

    if (myStack.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    }
    else {
        std::cout << "Stack is not empty" << std::endl;
    }

}
