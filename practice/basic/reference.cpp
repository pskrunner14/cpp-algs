#include <iostream>
using namespace std;

// pass by reference (&)
void increment(int& n) {
    n++;
}

// useless since scope of a is only within the func
// it will be destroyed after func call
// even return local var pointer is bad practice
int& f(int n) {
    int a = n;
    return a;
}

int main() {

    int i = 10;
    int j = i;

    i++;
    cout << j << endl; // j does'nt change (pass by value)

    // has to be init when declared
    int &k = i; // reference variable (points to the same address)

    i++;
    cout << k << endl; // changes (pass by reference)

    k = 100; // changes both i and k

    cout << i << endl;
    cout << k << endl;

    increment(k);
    cout << i << endl; // pass by reference
    cout << k << endl;

    return 0;
}