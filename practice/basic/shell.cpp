#include <iostream>
using namespace std;

template <class T>
void print_array(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

template <class T>
void shellSort(T arr[], int size) {
    int s = 1;
    while (s < size / 3) s = 3 * s + 1; 
    while (s >= 1) {
        for (int i = s; i < size; i++) {
            for (int j = i; j >= s && arr[j] < arr[j - s]; j -= s)
                swap(arr[j], arr[j - s]);
        }
        s /= 3;
    }
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
    
    shellSort<int>(arr, n);
    return 0;
}