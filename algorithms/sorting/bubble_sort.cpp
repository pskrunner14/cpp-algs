/**
 * Algorithms - sorting
 * bubble_sort.cpp
 * Purpose: Performs bubble sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 07/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Sorts an integer array using Bubble Sort algorithm.
 * 
 * @param arr the integer array to sort.
 * @param size the size of the array.
*/
void bubbleSort(int arr[], int size) {
    int swap;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swap;       
            }
        }
    }
}