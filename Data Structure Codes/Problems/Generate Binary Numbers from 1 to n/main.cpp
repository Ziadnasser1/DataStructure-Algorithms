#include <iostream>
#include "../../../Data Structure Codes/Lists/QueueLLBased/Queue.cpp"
#include "../../../Data Structure Codes/Lists/QueueLLBased/Queue.h"

template<typename elementType>
void Queue<elementType>::generateBinaryNumbers(int n) {
    Queue<string> q;

    q.enqueue("1");

    for (int i = 1; i <= n; i++) {
        string binary = q.front();
        q.dequeue();

        cout << binary << " ";

        q.enqueue(binary + "0");
        q.enqueue(binary + "1");
    }
}

int main() {
    Queue<string> q;
    q.generateBinaryNumbers(10);
    return 0;
}
