//
// Created by Ziad Nasser on 2023-05-11.
//

#include "minHeap.h"
#include <algorithm>

int minHeap::parent(int index) {
    return (index-1) /2;
}

int minHeap::left_child(int index) {
    return 2 * index +1;
}

int minHeap::right_child(int index) {
    return 2 * index + 2;
}

void minHeap::swap(int &a, int &b) {
    int tmp = a;
    a = b ;
    b = tmp;
}

minHeap::minHeap() {
    capacity = 0;
    size = 0;
    arr = new int[capacity];
}

minHeap::minHeap(int cap) {
    capacity = cap;
    size = 0;
    arr = new int[capacity];
}

minHeap::~minHeap() {
    delete [] arr;
}

void minHeap::min_heapify(int index) {

    int smallest = index;
    int left = left_child(index);
    int right = right_child(index);

    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        min_heapify(smallest);
    }
}

void minHeap::build_min_heap() {
    for(int i = size/2 -1; i>=0; i--)
        min_heapify(i);
}
void minHeap::heapSort() {
    build_min_heap();
    int tmpSize = size;
    for (int i = size - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        size--;
        min_heapify(0);
    }
    size = tmpSize;
    int start = 0;
    int end = tmpSize - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}




void minHeap::min_heap_insert(int val) {
    if (size == capacity) {
        cout << "Error: heap overflow" << endl;
        return;
    }
    size++;
    arr[size-1] = val;
    int i = size-1;
    while(i>0 && arr[parent(i)] >  arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

int minHeap::heap_extract_min() {
    if (size == 0) {
        cout << "Error: heap underflow" << endl;
        return -1;
    }

    int min = arr[0];
    arr[0] = arr[size - 1];
    size--;
    min_heapify(0);
    return min;
}

void minHeap::heap_decrease_key(int index, int new_val) {
    if (new_val > arr[index]) {
        cout << "Error: new key is greater than current key" << endl;
        return;
    }
    arr[index] = new_val;
    while(index > 0 && arr[parent(index)] > arr[index]){
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}

int minHeap::heap_minimum() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return -1;
    }

    return arr[0];
}

void minHeap::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}
