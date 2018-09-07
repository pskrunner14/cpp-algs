/**
 * Algorithms - searching
 * linear_search.cpp
 * Purpose: Performs linear search on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 07/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Searches for a key in an array using Linear Search algorithm.
 * 
 * @param arr the integer array to sort.
 * @param size the size of the array.
 * @param key the element to search for.
 * @returns The index of the key element (default: -1)
*/
int linearSearch(int arr[], int size, int key) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}
