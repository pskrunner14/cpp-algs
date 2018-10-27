/**
 * Algorithms - sorting
 * merge_sort.cpp
 * Purpose: Performs merge sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
*/

#include <iostream>
using namespace std;

template <class T>
void merge(T *arr, T *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        aux[k] = arr[k];
    }
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid)
            arr[k] = aux[j++];
        else if (j > hi)
            arr[k] = aux[i++];
        else if (aux[j] < aux[i])
            arr[k] = aux[j++];
        else
            arr[k] = aux[i++];
    }
}

template <class T>
void sort(T *arr, T *aux, int lo, int hi) {
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    sort(arr, aux, lo, mid);
    sort(arr, aux, mid + 1, hi);
    merge(arr, aux, lo, mid, hi);
}

/**
 * Sorts an array using Merge Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <class T>
void mergeSort(T *arr, int size) {
    T *aux = new T[size];
    sort(arr, aux, 0, size - 1);
}