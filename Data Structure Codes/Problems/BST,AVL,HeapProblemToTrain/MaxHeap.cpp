#include "MaxHeap.h"

MaxHeap::MaxHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new Student*[capacity];
}

MaxHeap::~MaxHeap() {
    delete[] arr;
}

void MaxHeap::swap(Student*& a, Student*& b) {
    Student* temp = a;
    a = b;
    b = temp;
}

void MaxHeap::heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left]->gpa > arr[largest]->gpa) {
        largest = left;
    }

    if (right < size && arr[right]->gpa > arr[largest]->gpa) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(largest);
    }
}
void MaxHeap::buildHeap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}
int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

void MaxHeap::insertStudentMX(int id, const string& name, double gpa, const string& department) {
    if (size == capacity) {
        int newCapacity = capacity * 2;
        auto** newArr = new Student*[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;

        capacity = newCapacity;
        arr = newArr;
    }

    auto* student = new Student(id, name, gpa, department);
    arr[size] = student;
    size++;

    departmentCounts[department]++;

    int i = size - 1;
    while (i > 0 && arr[i]->gpa > arr[parent(i)]->gpa) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

Student* MaxHeap::extractMax() {
    if (size <= 0) {
        cout << "Error: Heap is empty. No students to extract." << endl;
        return nullptr;
    }

    Student* maxStudent = arr[0];

    swap(arr[0], arr[size - 1]);
    size--;

    departmentCounts[maxStudent->department]--;

    heapify(0);

    return maxStudent;
}

float MaxHeap::maximum() {
    if (size <= 0) {
        cout << "Error: Heap is empty. No maximum element." << endl;
        return 0.0f;
    }

    return arr[0]->gpa;
}

void MaxHeap::printHeap() {
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
void MaxHeap::printDepartmentReport() {
    if (size <= 0) {
        cout << "Heap is empty. No students to report." << endl;
        return;
    }

    unordered_map<string, int> departmentCounts;

    for (int i = 0; i < size; i++) {
        departmentCounts[arr[i]->department]++;
    }
    for (const auto& pair : departmentCounts) {
        cout << "Department: " << pair.first << ", Count: " << pair.second << endl;
    }
}

void MaxHeap::loadDataFromFile(const string& filename) {
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
        insertStudentMX(id, name, GPA, department);
    }

    file.close();
}

void MaxHeap::heapSort() {
    buildHeap();

    int heapSize = size;

    for (int i = size - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        size--;
        heapify(0);
    }
    size = heapSize;
}
