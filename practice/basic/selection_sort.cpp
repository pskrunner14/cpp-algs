#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

// Reverse of binary search 
// repeatedly move the smallest element to the front of the array

void selectionSort(int arr[], int size) {
    int min = 0, start, swap;
    for (int i = 0; i < size - 1; i++) {
        start = i;
        min = start;
        for (int j = start + 1; j < size; j++) {
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap = arr[min];
        arr[min] = arr[start];
        arr[start] = swap;
    }
    print_array(arr, size);
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, n);

    return 0;
}