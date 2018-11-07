/**
 * Algorithms - sorting
 * quick_sort.cpp
 * Purpose: Performs quick sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
*/

#include <bits/stdc++.h>
#include <iostream>

template <typename T>
int partition(T *arr, const int &lo, const int &hi) {
    int i = lo;
    int j = hi + 1;
    T v = arr[lo];
    while (true) {
        while (arr[++i] < v)
            if (i == hi)
                break;
        while (v < arr[--j])
            if (j == lo)
                break;
        if (i >= j)
            break;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[lo], arr[j]);
    return j;
}

template <typename T>
void qsort(T *arr, const int &lo, const int &hi) {
    if (hi <= lo)
        return;
    int p = partition(arr, lo, hi);
    qsort(arr, lo, p - 1);
    qsort(arr, p + 1, hi);
}

/**
 * Sorts an array using Quick Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
 * @param randomize the flag that specifies whether to randomly shuffly the data array before sorting in order to ensure average case.
*/
template <typename T>
void quickSort(T *arr, const int &size, bool randomize = true) {
    // randomize the array to make
    // worst case time O(nlogn) - has
    // huge affect with very large inputs
    // i.e. ~1M elements.
    if (randomize) {
        std::random_shuffle(arr, arr + size);
    }
    qsort(arr, 0, size - 1);
}