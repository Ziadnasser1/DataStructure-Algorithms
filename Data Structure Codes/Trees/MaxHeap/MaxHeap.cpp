//
// Created by Ziad Nasser on 2023-05-08.
//

#include "MaxHeap.h"

MaxHeap::MaxHeap() {
    capacity = 10;
    arr = new int[capacity];
    size = 0;
}

MaxHeap::MaxHeap(int cap) {
    capacity = cap;
    arr = new int[capacity];
    size = 0;
}

MaxHeap::~MaxHeap() {
    delete[] arr;
}

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

int MaxHeap::left_child(int i) {
    return 2 * i + 1;
}

int MaxHeap::right_child(int i) {
    return 2 * i + 2;
}

void MaxHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void MaxHeap::Max_heapify(int index) {
    int largest = index;
    int left = left_child(index);
    int right = right_child(index);

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        Max_heapify(largest);
    }
}

void MaxHeap::Build_Max_heap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        Max_heapify(i);
    }
}

void MaxHeap::HeapSort() {
    Build_Max_heap();
    int tmpSize = size;
    for (int i = size - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        size--;
        Max_heapify(0);
    }
    size = tmpSize;
}
void MaxHeap::Max_heap_insert(int val) {
    if (size == capacity) {
        std::cout << "Error: heap overflow" << std::endl;
        return;
    }

    size++;
    arr[size - 1] = val;
    int i = size - 1;
    while (i > 0 && arr[parent(i)] < arr[i]) {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

int MaxHeap::heap_extract_max() {
    if (size == 0) {
        std::cout << "Error: heap underflow" << std::endl;
        return -1;
    }

    int max = arr[0];
    arr[0] = arr[size - 1];
    size--;
    Max_heapify(0);
    return max;
}

void MaxHeap::heap_increase_key(int index, int new_val) {
    if (new_val < arr[index]) {
        std::cout << "Error: new key is smaller than current key" << std::endl;
        return;
    }

    arr[index] = new_val;
    while (index > 0 && arr[parent(index)] < arr[index]) {
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}


int MaxHeap::heap_maximum() {
    if (size == 0) {
        std::cout << "Error: heap is empty" << std::endl;
        return -1;
    }

    return arr[0];
}

void MaxHeap::printHeap() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}