#include <iostream>
using namespace std;

void increment(int a) {
    a = a + 1;
}

// pass by value
int main() {
    int n = 10;
    increment(n);
    cout << n << endl; // prints 10
    return 0;
}