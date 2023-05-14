//
// Created by Ziad Nasser on 2023-05-14.
//

#ifndef BST_AVL_HEAPPROBLEMTOTRAIN_MINHEAP_H
#define BST_AVL_HEAPPROBLEMTOTRAIN_MINHEAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct student {
    int id;
    string name;
    double gpa;
    string department;

    student(int id, const string& name, double gpa, const string& department) {
        this->id = id;
        this->name = name;
        this->department = department;
        this->gpa = gpa;
    }
};

class MinHeap {
private:
    student** arr;
    int capacity;
    int size;
    unordered_map<string, int> departmentCounts;

    void swap(student*& a, student*& b);
    void heapify(int index);
    void buildHeap();

public:
    MinHeap(int capacity);
    ~MinHeap();
    int parent(int i);
    void insertStudent(int id, const string& name, double gpa, const string& department);
    student* extractMin();
    float minimum();
    void printHeap();
    void printDepartmentReport();
    void loadDataFromFile(const string& filename);
    void heapSort();
};

#endif //BST_AVL_HEAPPROBLEMTOTRAIN_MINHEAP_H
