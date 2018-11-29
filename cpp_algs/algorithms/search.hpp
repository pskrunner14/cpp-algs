/**
 * MIT License
 *
 * Copyright (c) 2018 Prabhsimran Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

/**
 * Algorithms - searching
 * search.hpp
 * Purpose: Search interface
 * 
 * @author Prabhsimran Singh
 * @version 2.0 29/11/18 
*/

namespace al {

// ---------------------------------------------- Interface ---------------------------------------------------//

// linear search
template <typename T>
int linearSearch(T *, const int &, const T &);

// binary search
template <typename T>
int binarySearch(T *, const int &, const T &);

// ternary search
template <typename T>
int ternarySearch(T *, const int &, const T &);

// -------------------------------------------- Implementation --------------------------------------------------//

/**
 * Searches for a key in an array using Linear Search algorithm.
 * 
 * @param arr the array to search from (type T).
 * @param size the size of the array.
 * @param key the element to search for (type T).
 * @returns The index of the key element (default: -1)
*/
template <typename T>
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

/**
 * Searches for a key in an array using Binary Search algorithm.
 * 
 * @param arr the array to search from (type T).
 * @param size the size of the array.
 * @param key the element to search for (type T).
 * @returns The index of the key element (default: -1)
*/
template <typename T>
int binarySearch(T *arr, const int &n, const T &key) {
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

/**
 * Searches for a key in an array using Ternary Search algorithm.
 * 
 * @param arr the array to search from (type T).
 * @param size the size of the array.
 * @param key the element to search for (type T).
 * @returns The index of the key element (default: -1)
*/
template <typename T>
int ternarySearch(T *arr, const int &n, const T &key) {
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
} // namespace al