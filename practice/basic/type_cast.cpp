/**
 * Type Casting in C++
 * 
/*/

#include <iostream>
using namespace std;

int main() {

    int a;
    char c;

    a = 100;
    c = a;  // the char gets assigned the ascii 100 ('d')

    cout << c << endl;   // prints 'd'

    int b;
    char d;

    b = 199210;   // int that takes up 2 bytes atleast
    d = b;   // gets assigned just the last byte of the int as char is only 1 byte
    
    cout << d << endl;   // prints useless char or garbage value

    int e;
    char f;

    f = 'y';
    e = f;   // gets assigned the ascii value of y
    
    cout << e << endl;   // prints 121 ('y' in ascii)

    // Implicit Typecasting
    float g = 11.2;
    int h = g;  // gets assigned only the integer value of the float (11)

    cout << h << endl;  // prints 11

    int i = 10;
    char j = 'a';

    cout << i + j << endl;  // prints the sum of int with ascii of char

    int k = 10;
    char l = 'a';

    char m = k + l;

    cout << m << endl;

    cout << ('a' + 1) << endl;

    char n = 74;

    cout << n << endl;

    return 0;
}