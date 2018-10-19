#include <iostream>
using namespace std;

int main() {

    int i = 10;
    int * p_i = &i;

    cout << sizeof(p_i) << endl;
    cout << i << endl;
    cout << *p_i << endl;

    i++;

    // changes reflected in both as 
    // i and *p_i mean the same thing essentially
    // pointing to the same address
    cout << i << endl;
    cout << *p_i << endl;

    i = 12;
    cout << i << endl;
    cout << *p_i << endl;

    *p_i = 23;
    cout << i << endl;
    cout << *p_i << endl;
    
    (*p_i)++;
    cout << i << endl;
    cout << *p_i << endl;

    int * q_i = p_i;
    (*q_i) += 3;
    cout << i << endl;
    cout << *p_i << endl;
    cout << *q_i << endl;

    int * garbage_ptr;
    cout << garbage_ptr << endl; // pointer with a garbage address
    cout << *garbage_ptr << endl;
    // DANGEROUS - Can modify any random address in the system storage
    (*garbage_ptr)++;  // modifying the value that the garbage ptr is pointing to 
    cout << *garbage_ptr << endl;

    int * null_ptr = 0; // not pointing anywhere
    // if you do'nt want to initialize with an existing 
    // varable's address or garbage value, assign zero to it 
    // so it will error at compile time.
    return 0;
}