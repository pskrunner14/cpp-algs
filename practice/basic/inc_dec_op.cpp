#include <iostream>
using namespace std;

int main() {

    // a++, a-- post increment
    // ++a, --a pre increment
    int a = 1;
    int b = 1;

    cout << a++ << endl; // increment after the execution of this statement
    cout << ++b << endl; // increment before the execution of this statement

    a = 1;
    b = 1;

    cout << a-- << endl;
    cout << --b << endl;

    return 0;
}