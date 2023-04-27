//
// Created by Ziad Nasser on 2023-04-27.
//

#include "ArrayBasedList.h"

template<typename T>
ArrayBasedList<T>::ArrayBasedList(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->arr = new T[capacity];
}

template<typename T>
ArrayBasedList<T>::~ArrayBasedList() {
    delete[] arr;
}

template<typename T>
void ArrayBasedList<T>::insert(T element) {
    if(size==capacity){
        cout<<"list is full!"<<endl;
        return;
    }
    arr[size] = element;
    size++;
}

template<typename T>
void ArrayBasedList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) {
        cout << "Index out of range!" << endl;
        return;
    }
    if (size == capacity) {
        capacity *=2;
        T* tempArr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            tempArr[i] = arr[i];
        }
        delete[] arr;
        arr = tempArr;
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = element;
    size++;
}



template<typename T>
void ArrayBasedList<T>::print() {
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

template<typename T>
void ArrayBasedList<T>::clear() {
    size=0;
}

template<typename T>
int ArrayBasedList<T>::maxListSize() {
    return capacity;
}

template<typename T>
int ArrayBasedList<T>::listSize() {
    return size;
}

template<typename T>
bool ArrayBasedList<T>::isFull() {
    return size==capacity;
}

template<typename T>
bool ArrayBasedList<T>::isEmpty() {
    return size==0;
}

template<typename T>
bool ArrayBasedList<T>::isItemAtEqual(T element, int index) {
    if(index < 0 || index >= size){
        cout<<"out of range!"<<endl;
        return false;
    }
    else{
        return arr[index] == element;
    }
}

template<typename T>
void ArrayBasedList<T>::replaceAt(T newElement, int index) {
    if(index < 0 || index > size){
        cout<<"out of range!"<<endl;
        return;
    }
    else{
        arr[index] = newElement;
    }


}

template<typename T>
void ArrayBasedList<T>::removeAt(int index) {

    if(index < 0 || index > size){
        cout<<"out of range!"<<endl;
        return;
    }
    for(int i =index; i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;

}

template<typename T>
T ArrayBasedList<T>::retrieveAt(int index) {
    if(index < 0 || index >= size){
        cout<<"out of range!"<<endl;
        return T();
    }
    return arr[index];
    cout<<"asdsad";
}
template class ArrayBasedList<int>;
