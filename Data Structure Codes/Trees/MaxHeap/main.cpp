#include <iostream>
#include "maxHeap.h"

using namespace std;

int main() {
    // Create a max-heap object
    MaxHeap maxHeap(11);

    // Insert values into the max-heap
    maxHeap.Max_heap_insert(4);
    maxHeap.Max_heap_insert(1);
    maxHeap.Max_heap_insert(3);
    maxHeap.Max_heap_insert(2);
    maxHeap.Max_heap_insert(16);
    maxHeap.Max_heap_insert(9);
    maxHeap.Max_heap_insert(10);
    maxHeap.Max_heap_insert(14);
    maxHeap.Max_heap_insert(8);
    maxHeap.Max_heap_insert(7);
    maxHeap.Max_heap_insert(6);

    cout<<"maxHeap elements: ";
    maxHeap.printHeap();

    // Extract the maximum element from the max-heap
    int max = maxHeap.heap_extract_max();
    cout << "Max element: " << max << endl;

    cout<<"maxHeap elements after deleting the max: ";
    maxHeap.printHeap();

    // Increase the value of an element in the max-heap
    maxHeap.heap_increase_key(3, 15);

    cout<<"maxHeap elements after replacing element at index 3 with (15): ";
    maxHeap.printHeap();

    // Get the maximum element in the max-heap
    int maxElement = maxHeap.heap_maximum();
    cout << "Max element: " << maxElement << endl;

    // Sort the elements in the max-heap using heap sort
    maxHeap.HeapSort();

    cout << "Sorted elements: ";
    maxHeap.printHeap();

    return 0;
}