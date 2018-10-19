#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

template <class T>
void print_array(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

template <class T>
int partition(T arr[], int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    T v = arr[lo];
    while (true) { 
        while (arr[++i] < v)
            if (i == hi) break;
        while (v < arr[--j])
            if (j == lo) break;
        if (i >= j) 
            break;
        swap(arr[i], arr[j]);
    }
    swap(arr[lo], arr[j]);
    return j;
}

template <class T>
void sort(T arr[], int lo, int hi) { 
    if (hi <= lo) 
        return;
    int p = partition(arr, lo, hi);
    sort(arr, lo, p - 1);
    sort(arr, p + 1, hi);
}

template <class T>
void quickSort(T arr[], int size) {
    random_shuffle(arr, arr + size);
    sort(arr, 0, size - 1);
    print_array(arr, size);
}

int length(char arr[]) {
    int len = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    quickSort<int>(arr, n);
    return 0;
}