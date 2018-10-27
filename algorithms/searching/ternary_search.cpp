/**
 * Algorithms - searching
 * ternary_search.cpp
 * Purpose: Performs ternary search on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18 
*/

#include <iostream>
using namespace std;

/**
 * Searches for a key in an array using Ternary Search algorithm.
 * 
 * @param arr the array to search from (type T).
 * @param size the size of the array.
 * @param key the element to search for (type T).
 * @returns The index of the key element (default: -1)
*/
template <class T>
int ternarySearch(T *arr, int n, T key) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid1 = start + (end - start) / 3;
        int mid2 = end - (end - start) / 3;
        if (arr[mid1] == key)
            return mid1;
        if (arr[mid2] == key)
            return mid2;
        else if (arr[mid1] > key)
            end = mid1 - 1;
        else if (arr[mid2] < key)
            start = mid2 + 1;
        else {
            start = mid1 + 1;
            end = mid2 - 1;
        }
    }
    return -1;
}