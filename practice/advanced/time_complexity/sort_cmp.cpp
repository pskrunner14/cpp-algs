#include <iostream>
#include <sys/time.h>

#include "../../algorithms/sorting/quick_sort.cpp"
#include "../../algorithms/sorting/heap_sort.cpp"
#include "../../algorithms/sorting/selection_sort.cpp"
#include "../../algorithms/sorting/merge_sort.cpp"

long timeit() {
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void init_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main() {

    for (int n = 10; n < 1000000; n *= 10) {
        // create an array
        int *arr = new int[n];

        // init array elements
        init_array(arr, n);
        // time merge sort
        long start_merge = timeit();
        mergeSort(arr, n);
        long end_merge = timeit();

        init_array(arr, n);
        // time quick sort
        long start_quick = timeit();
        quickSort(arr, n);
        long end_quick = timeit();

        // init_array(arr, n);
        // // time heap sort
        // long start_heap = timeit();
        // heapSort(arr, n);
        // long end_heap = timeit();

        init_array(arr, n);
        // time selection sort
        long start_selec = timeit();
        selectionSort(arr, n);
        long end_selec = timeit();

        delete [] arr;
        // log info for each n
        cout << "n: " << n << endl;
        cout << "-------" << endl;
        cout << "merge sort - " << (end_merge - start_merge) << endl;
        cout << "quick sort - " << (end_quick - start_quick) << endl;
        // cout << "heap sort - " << (end_heap - start_heap) << endl;
        cout << "selection sort - " << (end_selec - start_selec) << endl << endl;
    }
    return 0;
}