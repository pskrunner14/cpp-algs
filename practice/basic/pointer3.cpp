#include <iostream>
using namespace std;

int main() {

    // usually size of pointers for any datatype is same
    int i = 10;
    int * p_i = &i;

    cout << p_i << endl;
    p_i = p_i + 1; // will jump to the next int (depends on datatype)
    cout << p_i << endl; // adds 4 bytes to the address (int takes up 4 bytes of memory)

    // this increment and decrement of 
    // pointer only makes sense when we 
    // have contiguous memory locations 
    // for ex. an array
    return 0;
}