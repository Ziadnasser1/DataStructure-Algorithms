#include <iostream>
#include "MinHeap.h"

int main() {
    // Create a MinHeap object
    minHeap minHeap(10);

    // Insert elements into the heap
    minHeap.min_heap_insert(4);
    minHeap.min_heap_insert(8);
    minHeap.min_heap_insert(2);
    minHeap.min_heap_insert(6);
    minHeap.min_heap_insert(1);
    minHeap.min_heap_insert(9);
    minHeap.min_heap_insert(3);
    minHeap.min_heap_insert(7);
    minHeap.min_heap_insert(5);

    // Print the heap
    minHeap.print();

    // Extract the minimum element
    int min = minHeap.heap_extract_min();
    cout << "Extracted minimum element: " << min << std::endl;

    // Print the updated heap
    minHeap.print();

    // Decrease the key of an element
    minHeap.heap_decrease_key(5, 0);
    std::cout << "Decreased key at index 5" << std::endl;

    // Print the updated heap
    minHeap.print();

    // Get the minimum element
    int minimum = minHeap.heap_minimum();
    std::cout << "Minimum element: " << minimum << std::endl;
    minHeap.print();
    // Perform heap sort
    minHeap.heapSort();

    // Print the sorted array
    cout << "Sorted array: ";
    minHeap.print();



    return 0;
}
