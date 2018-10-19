#include <iostream>
using namespace std;

// arr -> stored in symbol table at compile time
// *ptr(arr) -> explicitly stored in memory and is assigned 8 bytes

// you can write a[] as *a
int sum(int* a, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {

    int arr[10];
    cout << arr << endl;
    cout << &arr[0] << endl;

    // only pass part of an array
    cout << sum(arr + 3, 7) << endl;

    arr[0] = 5;
    arr[1] = 12;

    // arr[i] and i[arr] are the same thing
    cout << *arr << endl;
    cout << *(arr + 1) << endl;

    int * p_arr = &arr[0];

    cout << p_arr[0] << endl;

    // differences 
    cout << sizeof(arr) << endl; // no explicit memory assigned
    cout << sizeof(p_arr) << endl; // pointer is assigned 8 bytes explicitly
    
    // adress of arr is same as the address the pointer of arr is pointing to 
    cout << &arr << endl;
    cout << p_arr << endl;
    cout << &p_arr << endl;

    // we can change the address the pointer of arr is pointing to
    // but we cannot change the address the arr pointer is pointing to 
    // since it is not explicitly stored in memory
    // values once stored in the symbol table can't be changed or reassigned
    p_arr = &arr[3];

    return 0;
}