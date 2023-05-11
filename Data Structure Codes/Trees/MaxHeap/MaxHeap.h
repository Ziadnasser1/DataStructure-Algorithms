//
// Created by Ziad Nasser on 2023-05-08.
//

#ifndef MAXHEAP_MAXHEAP_H
#define MAXHEAP_MAXHEAP_H
#include <iostream>
using namespace std;

class MaxHeap {
private:
    int capacity;
    int* arr;
    int size;
    void swap(int& a, int& b);
    int parent(int i);
    int left_child(int i);
    int right_child(int i);
public:
    MaxHeap();
    MaxHeap(int cap);
    ~MaxHeap();
    void Max_heapify(int index);
    void Build_Max_heap();
    void HeapSort();
    void Max_heap_insert(int val);
    int heap_extract_max();
    void heap_increase_key(int index, int new_val);
    int heap_maximum();
    void printHeap();
};


#endif //MAXHEAP_MAXHEAP_H
