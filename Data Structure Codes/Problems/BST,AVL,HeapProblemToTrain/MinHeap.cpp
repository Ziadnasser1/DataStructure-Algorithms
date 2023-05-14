#include "MinHeap.h"

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new student*[capacity];
}

MinHeap::~MinHeap() {
    delete[] arr;
}

void MinHeap::swap(student*& a, student*& b) {
    student* temp = a;
    a = b;
    b = temp;
}

void MinHeap::heapify(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left]->gpa < arr[smallest]->gpa) {
        smallest = left;
    }

    if (right < size && arr[right]->gpa < arr[smallest]->gpa) {
        smallest = right;
    }

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapify(smallest);
    }
}

void MinHeap::buildHeap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

int MinHeap::parent(int i) {
    return (i - 1) / 2;
}

void MinHeap::insertStudent(int id, const string& name, double gpa, const string& department) {
    if (size == capacity) {

        int newCapacity = capacity * 2;
        auto** newArr = new student*[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        capacity = newCapacity;
        arr = newArr;
    }

    auto* student = new struct student(id, name, gpa, department);
    arr[size] = student;
    size++;

    departmentCounts[department]++;

    int i = size - 1;
    while (i > 0 && arr[i]->gpa < arr[parent(i)]->gpa) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

student* MinHeap::extractMin() {
    if (size <= 0) {
        cout << "Error: Heap is empty. No students to extract." << endl;
        return nullptr;
    }

    student* minStudent = arr[0];
    swap(arr[0], arr[size - 1]);
    size--;

    departmentCounts[minStudent->department]--;

    heapify(0);

    return minStudent;
}

float MinHeap::minimum() {
    if (size <= 0) {
        cout << "Error: Heap is empty. No minimum element." << endl;
        return 0.0f;
    }

    return arr[0]->gpa;
}

void MinHeap::printHeap() {
    if (size <= 0) {
        cout << "Heap is empty. No students to print." << endl;
        return;
    }

    cout << "Heap contents:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "ID: " << arr[i]->id << ", Name: " << arr[i]->name << ", GPA: " << arr[i]->gpa
             << ", Department: " << arr[i]->department << endl;
    }
}

void MinHeap::printDepartmentReport() {
    if (size <= 0) {
        cout << "Heap is empty. No students to report." << endl;
        return;
    }

    unordered_map<string, int> departmentCounts;

    // Count the number of students per department
    for (int i = 0; i < size; i++) {
        departmentCounts[arr[i]->department]++;
    }

    // Print the department report
    for (const auto& pair : departmentCounts) {
        cout << "Department: " << pair.first << ", Count: " << pair.second << endl;
    }
}

void MinHeap::loadDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename <<endl;
        return;
    }

    int numStudents;
    file >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        int id;
        string name;
        double GPA;
        string department;

        file >> id;
        file.ignore();
        getline(file, name);
        file >> GPA;
        file.ignore();
        getline(file, department);
        insertStudent(id, name, GPA, department);
    }

    file.close();
}

void MinHeap::heapSort() {
    buildHeap();
    int tmpSize = size;
    for (int i = size - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        size--;
        heapify(0);
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
