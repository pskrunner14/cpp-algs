/**
 * Algorithms - sorting
 * selection_sort.cpp
 * Purpose: Performs selection sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 07/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Sorts an integer array using Selection Sort algorithm.
 * 
 * @param arr the integer array to sort.
 * @param size the size of the array.
*/
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int start = i;
        int min = start;
        for (int j = start + 1; j < size; j++) {
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        int swap = arr[min];
        arr[min] = arr[start];
        arr[start] = swap;
    }
}