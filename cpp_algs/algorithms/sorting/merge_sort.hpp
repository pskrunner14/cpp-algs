#pragma once

/**
 * Algorithms - sorting
 * merge_sort.hpp
 * Purpose: Performs merge sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
*/
namespace al {

template <typename T>
void merge(T *, T *, const int &, const int &, const int &);

template <typename T>
void msort(T *, T *, const int &, const int &);

/**
 * Sorts an array using Merge Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void mergeSort(T *, const int &);

template <typename T>
void merge(T *arr, T *aux, const int &lo, const int &mid, const int &hi) {
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

template <typename T>
void msort(T *arr, T *aux, const int &lo, const int &hi) {
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    msort(arr, aux, lo, mid);
    msort(arr, aux, mid + 1, hi);
    merge(arr, aux, lo, mid, hi);
}

template <typename T>
void mergeSort(T *arr, const int &size) {
    T *aux = new T[size];
    msort(arr, aux, 0, size - 1);
}
} // namespace al