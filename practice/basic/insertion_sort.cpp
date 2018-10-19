#include <iostream>
using namespace std;

template <class T>
void print_array(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int length(char arr[]) {
    int len = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        len++;
    }
    return len;
}

template <class T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int index = i - 1;
        while (arr[index] > key && index >= 0) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = key;
    }
    print_array(arr, size);
}

int main() {

    // int n;
    // cin >> n;

    // char arr[n];

    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    
    // insertionSort<int>(arr, n);
    
    char name[100];
    cin >> name;

    int len = length(name);
    insertionSort<char>(name, len);

    return 0;
}