#include <chrono>
#include "SortingAlgorithms.cpp"
using namespace std;

int main() {
    // Put The Number You Want To Test In [n] Variable
    // The Available Numbers Is :
    // 200 500 1000 5000 10000 20000 50000
    SortingAlgorithms<int> s;
    const int n = 15;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand();
    }


    auto start_time = std::chrono::high_resolution_clock::now();
    // UnComment The Sort You Want To Use Only!

    //s.insertionSort(arr, n);
    //s.selectionSort(arr, n);
    s.bubbleSort(arr, n);
    //s.shellSort(arr, n);
    //s.mergeSort(arr, 0, n-1);
    //s.quickSort(arr, 0, n);
//    s.countSort(arr, n);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    cout << "Time With Array Of Size " << n << " = " << duration << endl;

    // If You Print The Array --> UnComment The Next Line
    s.printArr(arr,n);
}
