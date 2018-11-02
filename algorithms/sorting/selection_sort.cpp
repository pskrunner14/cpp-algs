/**
 * Algorithms - sorting
 * selection_sort.cpp
 * Purpose: Performs selection sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 2.1 08/09/18 
*/

#include <iostream>

/**
 * Sorts an array using Selection Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <class T>
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