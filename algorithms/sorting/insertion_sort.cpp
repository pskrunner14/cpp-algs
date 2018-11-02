/**
 * Algorithms - sorting
 * insertion_sort.cpp
 * Purpose: Performs insertion sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 2.0 08/09/18 
*/

/**
 * Sorts an array using Insertion Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <class T>
void insertionSort(T *arr, const int &size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int index = i - 1;
        while (arr[index] > key && index >= 0) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = key;
    }
}