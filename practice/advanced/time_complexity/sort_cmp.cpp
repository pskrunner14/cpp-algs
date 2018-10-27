#include <iostream>
#include <sys/time.h>

// algorithms
#include "../../../algorithms/sorting/bubble_sort.cpp"
#include "../../../algorithms/sorting/heap_sort.cpp"
#include "../../../algorithms/sorting/insertion_sort.cpp"
#include "../../../algorithms/sorting/merge_sort.cpp"
#include "../../../algorithms/sorting/quick_sort.cpp"
#include "../../../algorithms/sorting/selection_sort.cpp"
#include "../../../algorithms/sorting/shell_sort.cpp"

using namespace std;

long timeit() {
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void init_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main() {

    for (int n = 10; n < 100000000; n *= 10) {
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

        init_array(arr, n);
        // time heap sort
        long start_heap = timeit();
        heapSort(arr, n);
        long end_heap = timeit();

        init_array(arr, n);
        // time selection sort
        long start_shell = timeit();
        shellSort(arr, n);
        long end_shell = timeit();

        delete[] arr;
        // log info for each n
        cout << "n: " << n << endl;
        cout << "-------" << endl;
        cout << "merge sort - " << (end_merge - start_merge) << endl;
        cout << "quick sort - " << (end_quick - start_quick) << endl;
        cout << "heap sort - " << (end_heap - start_heap) << endl;
        cout << "shell sort - " << (end_shell - start_shell) << endl;
        cout << endl;
    }
    return 0;
}

/**
 * Problems with experimental analysis:
 * 1. You may get different results for the same input on 
 *    running program again (system specific resource allocation).
 * 2. Test case generation i.e. some test cases may favour 
 *    some algorithms and may not others so it tampers with 
 *    our results (ussually we focus on worst case).
 * 3. We have to code each solution (there's alot of manua work involved).
 * 4. Very time consuming as some algorithms perform very poorly
 *    at worst cases.
 * 
 * We want a function F(n) given an algorithm A that gives a 
 * clear estimate of the algorithm's performance w.r.t. to the 
 * size of the input n.
 * 
 * Big O notation (worst case analysis):
 * We can never compute the exact time required for an algorithm 
 * to work on a particular input, we can only estimate the no. of 
 * operations (dominating term i.e. with highest power) that 
 * are required by the algorithm to get to the solution so it is 
 * system and input independent. We don't care about the co-efficient
 * or the smaller power terms along with the most significant one.
 * 
 * ex. f(n) = 5n^2 + 7n + 1000
 *     O(f(n)) = n^2
 * 
 * For any A, O(f(n)) if time taken by A for input size n is <= K * f(n)
 * i.e. the upper bound for the algorithm's performance.
 * 
 * ex. Insertion Sort has O(n^2) worst case time complexity.
 */