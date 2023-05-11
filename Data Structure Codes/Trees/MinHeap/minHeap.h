//
// Created by Ziad Nasser on 2023-05-11.
//

#ifndef MINHEAP_MINHEAP_H
#define MINHEAP_MINHEAP_H
#include <iostream>
using namespace std;
class minHeap{
private:
    int *arr;
    int capacity;
    int size;

    int parent(int index);
    int left_child(int index);
    int right_child(int index);
    void swap(int &a, int &b);
public:
    minHeap();
    minHeap(int cap);
    ~minHeap();

    void min_heapify(int index);
    void build_min_heap();
    void heapSort();
    void min_heap_insert(int val);
    int heap_extract_min();
    void heap_decrease_key(int index, int new_val);
    int heap_minimum();
    void print();
};


#endif //MINHEAP_MINHEAP_H
