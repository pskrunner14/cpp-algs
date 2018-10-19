#include <iostream>
using namespace std;

// DYNAMIC MEMORY ALLOCATION
// usually we get the size of input at runtime
// so if allocate a large size array at compile time
// it is added onto the stack (small memory that can't be changed) 
// which is bad practice as the program can run out of stack memory
// so it is better to allocate memory dynamically onto the 
// heap memory which is large and can be changed at runtime
// we can do that with `new` keyword
int main() {

    int* p = new int; // pointer memory on stack (8 bytes), int object on heap (4 bytes)
    *p = 10;
    cout << *p + 5 << endl;
    delete p; // single element deletion (not pointer but the memory it is pointing to)
    // p stays in the stack memory and hence the symbol table

    int n;
    cin >> n;
    int* arr = new int[n]; // heap memory (n*4 bytes) stack memory (8 bytes)

    for (int i = 0; i < n; i++)
        cin >> *(arr + i); // or arr[i]

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl; // or *(arr + i) this is what the system converts it to

    delete [] arr; // array elements deletion

    // experiment RAM usage
    // while (true) {
    //     int* p = new int;
    // }

    return 0;
}

/*
RELEASE OF MEMORY
Static Allocation (automatically deallocated after scope execution)
while (true) { // Automatic release of memory
    int i = 10; // no problem (i is deleted every loop)
}

dynamic allocation (no scope so it'll keep waiting in the heap memory)
while (true) { // Manual release of memory
    int *p = new int; // will alloc 4 bytes every loop until system runs out of memory and crashes
}

*/