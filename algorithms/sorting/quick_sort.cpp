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
using namespace std;

template <class T>
int partition(T *arr, int lo, int hi) {
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
        swap(arr[i], arr[j]);
    }
    swap(arr[lo], arr[j]);
    return j;
}

template <class T>
void sort(T *arr, int lo, int hi) {
    if (hi <= lo)
        return;
    int p = partition(arr, lo, hi);
    sort(arr, lo, p - 1);
    sort(arr, p + 1, hi);
}

/**
 * Sorts an array using Quick Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <class T>
void quickSort(T *arr, int size) {
    // randomize the array to make
    // worst case time O(nlogn) - has
    // huge affect with very large inputs
    // i.e. ~1M elements.
    random_shuffle(arr, arr + size);
    sort(arr, 0, size - 1);
}