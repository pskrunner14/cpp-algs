/**
 * Algorithms - searching
 * binary_search.cpp
 * Purpose: Performs binary search on an array
 * 
 * @author Prabhsimran Singh
 * @version 2.0 08/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Searches for a key in an array using Binary Search algorithm.
 * 
 * @param arr the array to search from (type T).
 * @param size the size of the array.
 * @param key the element to search for (type T).
 * @returns The index of the key element (default: -1)
*/
template <class T>
int binarySearch(T arr[], int n, T key){
  	int start = 0;
  	int end = n - 1;
  	while (start <= end) {
      	int mid = (start + end) / 2;
      	if (arr[mid] == key)
          	return mid;
        else if (arr[mid] > key)
          	end = mid - 1;
        else
          	start = mid + 1;
    }
  	return -1;
}