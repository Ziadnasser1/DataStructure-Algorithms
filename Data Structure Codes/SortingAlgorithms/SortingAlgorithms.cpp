//
// Created by Ziad Nasser on 2023-04-27.
//

#include "SortingAlgorithms.h"
#include "bits/stdc++.h"
using namespace std;



template<typename T>
void SortingAlgorithms<T>::printArr(T *arr, int n) {
    for(int i =0;i<n;i++)
        cout<<arr[i]<<"  ";
}

template<typename T>
void SortingAlgorithms<T>::insertionSort(T arr[], int n) {
    for (int i = 1, j; i < n; i++) {
        T tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

template<typename T>
void SortingAlgorithms<T>::selectionSort(T arr[], int n) {
    for(int i=0, j, least; i<n-1; i++){
        for(j=i+1, least=i; j<n ; j++){
            if(arr[j]<arr[least])
                least = j;
        }
        swap(arr[least],arr[i]);
    }
}


template<typename T>
void SortingAlgorithms<T>::bubbleSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

template<typename T>
void SortingAlgorithms<T>::merge(T arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    T left[n1];
    T right[n2];

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

template<typename T>
void SortingAlgorithms<T>::mergeSort(T arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

template<typename T>
int SortingAlgorithms<T>::partition(T arr[], int start, int end) {
    int pivot = arr[start];
    int pivotIndex = start;
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < pivot) {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
    }
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

template<typename T>
void SortingAlgorithms<T>::quickSort(T arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

template<typename T>
void SortingAlgorithms<T>::shellSort(T arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T tmp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
    }
}


template<class T>
void SortingAlgorithms<T>::countSort(T arr[], int size) {
    T mx = arr[0];
    for (int i = 0; i < size; ++i) {
        if(arr[i]>mx)
            mx=arr[i];
    }
    vector<T> count(mx + 1,0);
    for (int i = 0; i < size; ++i) {
        ++count[arr[i]];
    }
    for (int i = 1; i <= mx; ++i) {
        count[i] += count[i - 1];
    }
    T sortedArr[size];
    for (int i = size - 1; i >= 0; --i) {
        sortedArr[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    memcpy(arr,sortedArr,sizeof(sortedArr));
}
template class SortingAlgorithms<int>;
template class SortingAlgorithms<char>;

