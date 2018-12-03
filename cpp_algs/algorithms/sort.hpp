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
 * @version 2.3 03/12/18 
*/
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

namespace al {

// ---------------------------------------------- Interface ---------------------------------------------------//

// bubble sort
template <typename T>
void bubbleSort(std::vector<T> &);

// heap sort
template <typename T>
bool __less(std::vector<T> &, const int &, const int &);

template <typename T>
void __exch(std::vector<T> &, const int &, const int &);

template <typename T>
void _sink(std::vector<T> &, int, const int &);

template <typename T>
void heapSort(std::vector<T> &);

// insertion sort
template <typename T>
void insertionSort(std::vector<T> &);

// merge sort
template <typename T>
void __merge(std::vector<T> &, std::vector<T> &, const int &, const int &, const int &);

template <typename T>
void _msort(std::vector<T> &, std::vector<T> &, const int &, const int &);

template <typename T>
void mergeSort(std::vector<T> &);

// quick sort
template <typename T>
int __partition(std::vector<T> &, const int &, const int &);

template <typename T>
void _qsort(std::vector<T> &, const int &, const int &);

template <typename T>
void quickSort(std::vector<T> &, bool = false);

// selection sort
template <typename T>
void selectionSort(std::vector<T> &);

// shell sort
template <typename T>
void shellSort(std::vector<T> &);

// -------------------------------------------- Implementation --------------------------------------------------//

// bubble sort
/**
 * Sorts an array using Bubble Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void bubbleSort(std::vector<T> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

// heap sort
template <typename T>
bool __less(vector<T> &arr, const int &i, const int &j) {
    return (arr[i - 1] < arr[j - 1]);
}

template <typename T>
void __exch(vector<T> &arr, const int &i, const int &j) {
    T swap = arr[i - 1];
    arr[i - 1] = arr[j - 1];
    arr[j - 1] = swap;
}

template <typename T>
void _sink(vector<T> &arr, int k, const int &n) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && __less(arr, j, j + 1))
            j++;
        if (!__less(arr, k, j))
            break;
        __exch(arr, k, j);
        k = j;
    }
}

/**
 * Sorts an array using Heap Sort algorithm.
 * 
 * @param arr the array to sort (type T).
*/
template <typename T>
void heapSort(std::vector<T> &arr) {
    int n = arr.size();
    for (int k = n / 2; k >= 1; k--)
        _sink(arr, k, n);
    while (n > 1) {
        __exch(arr, 1, n--);
        _sink(arr, 1, n);
    }
}

// insertion sort
/**
 * Sorts an array using Insertion Sort algorithm.
 * 
 * @param arr the array to sort (type T).
*/
template <typename T>
void insertionSort(std::vector<T> &arr) {
    for (int i = 1; i < arr.size(); i++) {
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
void __merge(std::vector<T> &arr, std::vector<T> &aux, const int &lo, const int &mid, const int &hi) {
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
void _msort(std::vector<T> &arr, std::vector<T> &aux, const int &lo, const int &hi) {
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    _msort(arr, aux, lo, mid);
    _msort(arr, aux, mid + 1, hi);
    __merge(arr, aux, lo, mid, hi);
}

/**
 * Sorts an array using Merge Sort algorithm.
 * 
 * @param arr the array to sort (type T).
*/
template <typename T>
void mergeSort(std::vector<T> &arr) {
    std::vector<T> aux(arr.size());
    _msort(arr, aux, 0, arr.size() - 1);
}

// quick sort
template <typename T>
int __partition(std::vector<T> &arr, const int &lo, const int &hi) {
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
void _qsort(std::vector<T> &arr, const int &lo, const int &hi) {
    if (hi <= lo)
        return;
    int p = __partition(arr, lo, hi);
    _qsort(arr, lo, p - 1);
    _qsort(arr, p + 1, hi);
}

/**
 * Sorts an array using Quick Sort algorithm.
 * 
 * @param arr the array to sort (type T).
*/
template <typename T>
void quickSort(std::vector<T> &arr, bool shuffle) {
    if (shuffle) {
        // randomize the array to make
        // worst case time O(nlogn) - has
        // huge affect with very large inputs
        // i.e. ~1M elements.
        auto rng = std::default_random_engine{};
        std::shuffle(std::begin(arr), std::end(arr), rng);
    }
    _qsort(arr, 0, arr.size() - 1);
}

// selection sort
/**
 * Sorts an array using Selection Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void selectionSort(std::vector<T> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
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
*/
template <typename T>
void shellSort(std::vector<T> &arr) {
    int h = 1;
    while (h < arr.size() / 3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < arr.size(); i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                std::swap(arr[j], arr[j - h]);
        }
        h /= 3;
    }
}
} // namespace al