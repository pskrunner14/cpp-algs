#include <iostream>
using namespace std;

int main() {

    // Break down into 3 steps:
    // 1. Ask for memory
    // 2. Store the memory location for variable (symbol table)
    // 3. Assign value into the memory location
    int i = 10;
    cout << "Var `i` is stored at: " << &i << endl;

    // pointer to i 
    int * p_i = &i;
    cout << p_i << endl;

    // dereference operator (get to the value using the pointer storing the address)
    cout << *p_i << endl;

    // float f = 10.2;
    // float * p_f = &f;

    // double d = 122.32;
    // double * p_d = &d;

    return 0;
}

// Pointer Logic
/**
 * for every variable the system stores the location (pointer)
 * for it along with it's type (storage size) in the symbol table
 * at compile time.
 * 
 * Pointers are variables that store the address of other variables
 */ 