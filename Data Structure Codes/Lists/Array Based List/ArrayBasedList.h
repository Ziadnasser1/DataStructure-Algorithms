//
// Created by Ziad Nasser on 2023-04-27.
//

#ifndef ARRAY_BASED_LIST_ARRAYBASEDLIST_H
#define ARRAY_BASED_LIST_ARRAYBASEDLIST_H
using namespace std;
#include <iostream>

template<typename T>
class ArrayBasedList{
private:
    T *arr;
    int size;
    int capacity;
public:

    ArrayBasedList(int capacity);
    ~ArrayBasedList();

    void insert(T element);

    void insertAt(T element, int index);

    T retrieveAt(int index);

    void removeAt(int index);

    void replaceAt(T newElement,int index);

    bool isItemAtEqual(T element, int index);

    bool isEmpty();

    bool isFull();

    int listSize();

    int maxListSize();

    void clear();

    void print();
};


#endif //ARRAY_BASED_LIST_ARRAYBASEDLIST_H
