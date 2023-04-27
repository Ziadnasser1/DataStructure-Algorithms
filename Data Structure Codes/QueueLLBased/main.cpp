#include <iostream>
#include "Queue.h" // include the Queue header file

using namespace std;

int main() {
    Queue<int> q; // create a Queue object
    cout << "Is queue empty? " <<q.isEmpty() << endl; // should print true

    // add elements to the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue size: " << q.Size()<< endl; // should print 3

    cout << "First element: " << q.front() << endl; // should print 10

    cout << "last element: " << q.rear() << endl; // should print 30

    cout << "Dequeued element: " << q.dequeue() << endl; // should print 10

    cout << "Queue size: " << q.Size() << endl; // should print 2

    q.print(); // should print the elements [20, 30]

    q.clear(); // remove all elements from the queue

    cout << "Is queue empty? " << q.isEmpty() << endl; // should print true

    return 0;
}
