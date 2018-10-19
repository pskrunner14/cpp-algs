#include <iostream>
using namespace std;

void print(int* p) {
    cout << *p << endl;
}

void increment(int* p) {
    (*p)++;
}

// PASS BY VALUE
void incrementPointer(int* p) {
    p++;
}

int* incrementPointerReturn(int* p) {
    return ++p;
}

int main() {

    int i = 10;
    int* p = &i;

    print(p);
    incrementPointer(p); // pointer won't be affected bec we're sending a copy to the func
    print(p);
    increment(p); // changes the value the pointer points to
    print(p);

    cout << p << endl;
    p = incrementPointerReturn(p); // pointer will change
    cout << p << endl;
    print(p);
    return 0;
}