//
// Created by Ziad Nasser on 2023-04-27.
//

#ifndef SORTINGALGORITHMS_SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_SORTINGALGORITHMS_H
#include <iostream>
#include <algorithm>


template<typename T>
class SortingAlgorithms {

public:
    void printArr(T arr[], int n);

    void insertionSort(T arr[], int n) ;

    void selectionSort(T arr[], int n);

    void bubbleSort(T arr[], int n);

    void merge(T arr[], int l, int m, int r) ;

    void mergeSort(T arr[], int l, int r);

    int partition(T arr[], int start, int end) ;

    void quickSort(T arr[], int start, int end) ;

    void shellSort(T arr[], int n) ;


    void countSort(T arr[], int size);

};


#endif //SORTINGALGORITHMS_SORTINGALGORITHMS_H
