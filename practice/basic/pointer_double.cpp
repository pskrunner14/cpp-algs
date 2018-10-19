#include <iostream>
using namespace std;

// wont reflect any changes
// since it is a copy pointer
void increment1(int** p) {
    p++;
}

// will change the value at address
// stored by the pointer (which itself is a pointer)
void increment2(int** p) {
    (*p)++; // increment the value of address at pointer inside pointer
}

// will change the value at address
// stored by the pointer inside this pointer 
// so the actual variable value
void increment3(int** p) {
    (**p)++; // increment the value of var at address at pointer inside pointer
}

void printValues(int** p) {
    cout << "" << endl;
    cout << **p << endl;
    cout << *p << endl;
    cout << p << endl;
    cout << "" << endl;
}

// A BIT TRICKY
// pointer of pointer of pointer....
int main() {

    int i = 10;
    int* p = &i;
    int** pp = &p;

    cout << "i and dereferencing p and pp: \n" << endl;
    cout << i << endl; // value of var i
    cout << *p << endl; // value at address pointed by p
    cout << **pp << endl; // value at address stored in p that is stored in pp

    cout << "\naddress of i and value of p and dereferencing pp: \n" << endl;

    cout << &i << endl; // address of i
    cout << p << endl; // pointer pointing to i
    cout << *pp << endl; // value at address pointed by pp - p

    cout << "\naddress of p and value of pp: \n" << endl;

    cout << &p << endl; // address of p
    cout << pp << endl; // address of p in pp

    cout << "\naddress of pp: \n" << endl;

    cout << &pp << endl; // address of pp

    cout << "\nchanges reflected test: \n" << endl;
    printValues(pp);
    increment1(pp);
    printValues(pp);
    increment2(pp);
    printValues(pp);
    increment3(pp);
    printValues(pp);

    int b = 10;
    int *bp = &b;
    increment3(&bp);
    cout << b << endl;

    return 0;
}