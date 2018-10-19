/**
 * Data Types in C++
 * 
/*/

#include <iostream>
using namespace std;

int main() {

    int a = 10;  // int: 4 bytes (integer numbers in binary)
    cout << a << endl;

    char x = 'x';   // char: 1 byte (only one character in ascii as binary) '' - single quotes 
    cout << x << endl;

    float f = 1.23;   // float: 4 bytes (decimal numbers)
    double d =  3.45;   // double: 8 bytes (large decimal numbers)
    
    bool boolean = true;   // bool: 1 byte (true and false)
    
    // Get the size taken up by a varable
    int size_b = sizeof(boolean);

    cout << size_b << endl;

    return 0;
}

// Float and Double storage logic
/**
 * 
 * 2.35 ---> 10.___ (binary) ---> 1.xxxx * 2^e 
 * 100.1101 (binary) ---> 1.001101 (mantissa [after the decimal]) * 2^2 (exponent)
 * So we store mantissa and exponent separately      
 * 
 * 
/*/