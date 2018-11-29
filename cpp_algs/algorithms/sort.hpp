/**
 * MIT License
 *
 * Copyright (c) 2018 Prabhsimran Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

/**
 * Algorithms - sorting
 * sort.hpp
 * Purpose: Sorting interface
 * 
 * @author Prabhsimran Singh
 * @version 2.2 29/11/18 
*/
#include <bits/stdc++.h>
#include <iostream>

namespace al {

// ---------------------------------------------- Interface ---------------------------------------------------//

// bubble sort
template <typename T>
void bubbleSort(T *, const int &);

// heap sort
template <typename T>
void sink(T *, int, const int &);

template <typename T>
void heapSort(T *, int);

// insertion sort
template <typename T>
void insertionSort(T *, const int &);

// merge sort
template <typename T>
void merge(T *, T *, const int &, const int &, const int &);

template <typename T>
void msort(T *, T *, const int &, const int &);

template <typename T>
void mergeSort(T *, const int &);

// quick sort
template <typename T>
int partition(T *, const int &, const int &);

template <typename T>
void qsort(T *, const int &, const int &);

template <typename T>
void quickSort(T *, const int &);

// selection sort
template <typename T>
void selectionSort(T *, const int &);

// shell sort
template <typename T>
void shellSort(T *, const int &);

// -------------------------------------------- Implementation --------------------------------------------------//

// bubble sort
/**
 * Sorts an array using Bubble Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void bubbleSort(T *arr, const int &size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

// heap sort
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

// insertion sort
/**
 * Sorts an array using Insertion Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void insertionSort(T *arr, const int &size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int index = i - 1;
        while (arr[index] > key && index >= 0) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = key;
    }
}

// merge sort
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

/**
 * Sorts an array using Merge Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void mergeSort(T *arr, const int &size) {
    T *aux = new T[size];
    msort(arr, aux, 0, size - 1);
    delete[] aux;
}

// quick sort
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
*/
template <typename T>
void quickSort(T *arr, const int &size) {
    // randomize the array to make
    // worst case time O(nlogn) - has
    // huge affect with very large inputs
    // i.e. ~1M elements.
    std::random_shuffle(arr, arr + size);
    qsort(arr, 0, size - 1);
}

// selection sort
/**
 * Sorts an array using Selection Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void selectionSort(T *arr, const int &size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min == i)
            continue;
        std::swap(arr[min], arr[i]);
    }
}

// shell sort
/**
 * Sorts an array using Shell Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void shellSort(T *arr, const int &size) {
    int h = 1;
    while (h < size / 3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < size; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                std::swap(arr[j], arr[j - h]);
        }
        h /= 3;
    }
}
} // namespace al