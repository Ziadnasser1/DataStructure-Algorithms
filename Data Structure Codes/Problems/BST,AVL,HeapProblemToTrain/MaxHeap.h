//
// Created by Ziad Nasser on 2023-05-14.
//

#ifndef BST_AVL_HEAPPROBLEMTOTRAIN_MAXHEAP_H
#define BST_AVL_HEAPPROBLEMTOTRAIN_MAXHEAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
    string department;

    Student(int id, const string& name, double gpa, const string& department) {
        this->id = id;
        this->name = name;
        this->department = department;
        this->gpa = gpa;
    }
};

class MaxHeap {
private:
    Student** arr;
    int capacity;
    int size;
    unordered_map<string, int> departmentCounts;

    void swap(Student*& a, Student*& b);
    void heapify(int index);
    void buildHeap();


public:
    MaxHeap(int capacity);
    ~MaxHeap();
    int parent(int i);
    void insertStudentMX(int id, const string& name, double gpa, const string& department);
    Student* extractMax();
    float maximum();
    void printHeap();
    void printDepartmentReport();
    void loadDataFromFile(const string& filename);
    void heapSort();
};

#endif //BST_AVL_HEAPPROBLEMTOTRAIN_MAXHEAP_H
