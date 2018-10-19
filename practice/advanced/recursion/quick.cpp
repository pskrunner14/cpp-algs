#include <iostream>
using namespace std;

void printArray(int* arr, int start, int end) {
    for (int i = start; i < end; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int* arr, int lo, int hi) {
    int count = lo;
    int val = arr[lo];
    for (int i = lo + 1; i < hi; i++) {
        if (arr[i] <= val)
            count++;
    }
    for (int i = lo + 1; i <= count; i++)
        arr[i - 1] = arr[i];
    arr[count] = val;
    int li = lo;
    int ri = hi - 1;
    while (li < count and ri > count) {
        if (arr[li] <= val)
            li++;
        else if (arr[ri] > val)
            ri--;
        else {
            swap(arr[li], arr[ri]);
            li++;
            ri--;
        }
    }
    return count;
}

void quickSort(int* arr, int start, int end) {
    if (start >= (end - 1))
        return;
    int part = partition(arr, start, end);
    quickSort(arr, start, part);
    quickSort(arr, part + 1, end);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n);
    printArray(arr, 0, n);

    delete [] arr;

    return 0;
}