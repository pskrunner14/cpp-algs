#include <iostream>
using namespace std;

int main() {

    // bitwise AND (&)
    int r_and = 2 & 3;
    cout << r_and << endl;

    // bitwise OR (|)
    int r_or = 2 | 4;
    cout << r_or << endl;

    // bitwise NOT (~)
    int r_not = ~15;
    cout << r_not << endl;

    // bitwise XOR (^)
    int r_xor = 15 ^ 30;
    cout << r_xor << endl;

    // shift left op (<<) [shifts bits towards the left]
    int r_ls = 15 << 2;
    cout << r_ls << endl;

    // shift right op (<<) [shifts bits towards the right]
    int r_rs = 15 >> 2;
    cout << r_rs << endl;

    // NOTE: BE CAREFUL ABOUT THE SIGN BIT

    return 0;
}

// Bitwise Operators
/*
 * 
 * Bitwise operators let you manage a number at the bit level.
 * 
 */ 