#include <iostream>
#include "../../../Data Structure Codes/Lists/QueueLLBased/Queue.cpp"
#include "../../../Data Structure Codes/Lists/QueueLLBased/Queue.h"

template <typename T>
void Queue<T>::sortQueue() {
    if (size < 2) {
        return;
    }

    Queue<T> smaller, larger;

    T pivot = dequeue();
    while (!isEmpty()) {
        T current = dequeue();
        if (current < pivot) {
            smaller.enqueue(current);
        } else {
            larger.enqueue(current);
        }
    }

    smaller.sortQueue();
    larger.sortQueue();

    while (!smaller.isEmpty()) {
        enqueue(smaller.dequeue());
    }

    enqueue(pivot);

    while (!larger.isEmpty()) {
        enqueue(larger.dequeue());
    }
}



int main() {
    Queue<int> q;
    q.enqueue(2);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);

    q.sortQueue();

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}

