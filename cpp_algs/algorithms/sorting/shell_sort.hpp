#pragma once

/**
 * Algorithms - sorting
 * shell_sort.hpp
 * Purpose: Performs shell sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.1 11/09/18 
*/
#include <iostream>

namespace al {

/**
 * Sorts an array using Shell Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void shellSort(T *, const int &);

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