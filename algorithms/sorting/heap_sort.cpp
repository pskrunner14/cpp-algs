/**
 * Algorithms - sorting
 * heap_sort.cpp
 * Purpose: Performs heap sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
*/

#include <iostream>

template <typename T>
void sink(T *arr, int k, const int &n) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && arr[j] < arr[j + 1])
            j++;
        if (!arr[k] < arr[j])
            break;
        std::swap(arr[k], arr[j]);
        k = j;
    }
}

/**
 * Sorts an array using Heap Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void heapSort(T *arr, int size) {
    for (int k = size / 2; k >= 1; k--)
        sink(arr, k, size);
    while (size > 1) {
        std::swap(arr[1], arr[size--]);
        sink(arr, 1, size);
    }
}