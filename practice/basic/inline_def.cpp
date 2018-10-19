#include <iostream>
using namespace std;

inline int minNum(int a, int b) { // replaces the line where it is called
    return (a < b) ? a : b; // can leave out return
}

// default args (only right most can be default)
int sum(int arr[], int size, int start=0) {
    int sum = 0;
    for (int i = start; i < size; i++)
        sum += arr[i];
    return sum;
}

int sum2(int a, int b, int c=0, int d=0) {
    return a + b + c + d;
}

int main() {

    int a, b;
    cin >> a >> b;
    int max = (a > b) ? a : b; // inline op using tertiary operator
    cout << "Max: " << max << endl;

    int min = minNum(a, b);
    cout << "Min: " << min << endl;

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << sum(arr, n) << endl; // will assume start = 0 by default
    delete [] arr;

    cout << sum2(10, 20, 30) << endl;

    return 0;
}