/**
 * Algorithms - searching
 * linear_search.cpp
 * Purpose: Performs linear search on an array
 * 
 * @author Prabhsimran Singh
 * @version 2.0 08/09/18 
*/

/**
 * Searches for a key in an array using Linear Search algorithm.
 * 
 * @param arr the array to search from (type T).
 * @param size the size of the array.
 * @param key the element to search for (type T).
 * @returns The index of the key element (default: -1)
*/
template <class T>
int linearSearch(T *arr, const int &size, const T &key) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}
