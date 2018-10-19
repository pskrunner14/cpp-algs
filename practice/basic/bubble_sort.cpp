#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

// Reverse of binary search 
// repeatedly move the smallest element to the front of the array

void bubbleSort(int arr[], int size) {
    int swap;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]){
                swap = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swap;       
            }
        }
    }
    print_array(arr, size);
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);

    return 0;
}