/**
 * Algorithms - sorting
 * shell_sort.cpp
 * Purpose: Performs shell sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 08/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Sorts an array using Shell Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <class T>
void shellSort(T arr[], int size) {
    int s = 1;
    while (s < size / 3) s = 3 * s + 1; 
    while (s >= 1) {
        for (int i = s; i < size; i++) {
            for (int j = i; j >= s && arr[j] < arr[j - s]; j -= s)
                swap(arr[j], arr[j - s]);
        }
        s /= 3;
    }
}