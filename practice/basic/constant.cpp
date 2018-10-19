#include <iostream>
using namespace std;

void g(const int& a) {
    //(*a)++; // error
}

void f(const int* p) { // copy of the pointer is const
    //(*p)++; // error
}

int main() {

    // const int
    const int AGE = 21; // cannot be changed
    cout << AGE << endl;

    // constant reference of a non const int
    int j = 12; // path can be changed
    const int& k = j; // ca'nt be changed through k as readonly (costant path)

    j++; // will change k
    cout << k << endl;

    // constant reference of a const int
    const int l = 123;
    const int& m = l;

    int i = 10;
    int *p = &i;

    f(p);

    // TRICKY PART
    int const *p = &i; // pointer to a constant
    int* const p = &i; // constant pointer to int
    int const* const p = &i; // constant pointer to constant int

    // can't make normal ref from const int
    return 0;
}