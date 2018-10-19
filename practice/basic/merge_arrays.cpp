#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

// Reverse of binary search 
// repeatedly move the smallest element to the front of the array

void bubbleSort(int arr1[], int size1, int arr2[], int size2) {
    int arr[size1 + size2];
    int li = 0, ri = 0;
    for (int i = 0; i < (size1 + size2); i++) {
        if (li >= size1) {
            arr[i] = arr2[ri];
            ri++;
        } else if (ri >= size2) {
            arr[i] = arr1[li];
            li++;
        } else {
            if (arr1[li] < arr2[ri]) {
                arr[i] = arr1[li];
                li++;
            } else if (arr1[li] > arr2[ri]) {
                arr[i] = arr2[ri];
                ri++;
            } else {
                arr[i] = arr1[li];
                li++;
            }
        }
    }
    print_array(arr, size1 + size2);
}

int main() {

    int n, m;
    
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    bubbleSort(arr1, n, arr2, m);

    return 0;
}