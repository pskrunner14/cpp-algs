#include <iostream>
using namespace std;

bool is_sorted(int arr[], int size) {
    if (size == 0 || size == 1)
        return true;
    return (arr[0] > arr[1]) ? false: is_sorted(arr + 1, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << is_sorted(arr, 5) << endl;
    return 0;
}