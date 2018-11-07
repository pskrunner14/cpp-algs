/**
 * Algorithms - sorting
 * bubble_sort.cpp
 * Purpose: Performs bubble sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 2.1 08/09/18 
*/

#include <iostream>

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