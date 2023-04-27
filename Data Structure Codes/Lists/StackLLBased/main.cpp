#include <iostream>
#include "StackLLBAsed.h" // include the Stack header file

using namespace std;

int main() {
    Stack<int> s; // create a Stack object
    cout << "Is stack empty? " << boolalpha << s.isEmpty() << endl; // should print true

    // add elements to the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack size: " << s.stackSize() << endl; // should print 3

    cout << "Top element: " << s.top() << endl; // should print 30

    cout << "Popped element: " << s.pop() << endl; // should print 30

    cout << "Stack size: " << s.stackSize() << endl; // should print 2

    s.print(); // should print the elements [20, 10]

    s.clear(); // remove all elements from the stack

    cout << "Is stack empty? " << boolalpha << s.isEmpty() << endl; // should print true

    return 0;
}
