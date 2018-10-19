#include <iostream>
using namespace std;

template <class T>
void print_array(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

template <class T>
void merge(T arr[], T aux[], int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        aux[k] = arr[k]; 
    }
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid)              
            arr[k] = aux[j++];
        else if (j > hi)               
            arr[k] = aux[i++];
        else if (aux[j] < aux[i]) 
            arr[k] = aux[j++];
        else                           
            arr[k] = aux[i++];
    }
}

template <class T>
void sort(T arr[], T aux[], int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(arr, aux, lo, mid);
    sort(arr, aux, mid + 1, hi);
    merge(arr, aux, lo, mid, hi);
}

template <class T>
void mergeSort(T arr[], int size) {
    T aux[size];
    sort(arr, aux, 0, size - 1);
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
    
    mergeSort<int>(arr, n);
    return 0;
}