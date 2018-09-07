/**
 * Algorithms - sorting
 * insertion_sort.cpp
 * Purpose: Performs insertion sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 07/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Sorts an integer array using Insertion Sort algorithm.
 * 
 * @param arr the integer array to sort.
 * @param size the size of the array.
*/
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int index = i - 1;
        while (arr[index] > key && index >= 0) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = key;
    }
}