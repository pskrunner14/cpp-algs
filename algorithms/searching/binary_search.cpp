/**
 * Algorithms - searching
 * binary_search.cpp
 * Purpose: Performs binary search on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 07/09/18 
*/

#include <iostream>
using namespace std;

/**
 * Searches for a key in an array using Binary Search algorithm.
 * 
 * @param arr the integer array to sort.
 * @param size the size of the array.
 * @param val the element to search for.
 * @returns The index of the key element (default: -1)
*/
int binarySearch(int arr[], int n, int val){	
  	int start = 0;
  	int end = n - 1;
  	while (start <= end) {
      	int mid = (start + end) / 2;
      	if (arr[mid] == val)
          	return mid;
        else if (arr[mid] > val)
          	end = mid - 1;
        else
          	start = mid + 1;
    }
  	return -1;
}