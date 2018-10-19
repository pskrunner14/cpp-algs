#include <iostream>
using namespace std;

int main() {

    // no signed bit (we get an extra bit)
    unsigned int a = 10; // if we only want to store positive numbers
    cout << a << endl;

    long b = 1342344431;
    cout << b << endl; 

    char c = 234354; // system stores the number as int and then uses the last important bits in char
    cout << c << endl;

    unsigned int d = -123; // takes the sign bit as a literal number
    cout << d << endl;

    return 0;
}

// Negative number storage logic
/**
 * ----------------------------------------------------
 * 
 * Possible ways:
 * 
 * Largest number that can be stored in n bits:
 * 2^n - 1
 * 
 * Using the first bit as the sign bit (reserved)
 * + 2^(n - 1) - 1 (largest) [sign bit - 0]
 * - 2^(n - 1) - 1 (smallest) [sign bit - 1]
 * 
 * But in this system, we get two representations for 0
 * so it is ambiguous, hence we don't use this.
 * 
 * -----------------------------------------------------
 * 
 * Actual Storage Logic (int):
 * 
 * +ve number:
 * 1. Convert to binary
 * 2. Store the result of step 1
 * 
 * -ve number:
 * 1. Forget the negative sign
 * 2. Convert to binary number
 * 3. Take 2's compliment of number (1's compliment + 1)
 * 4. Store the result of step 3
 * 
 * Using the first bit as the sign bit (reserved) the range of numbers:
 * + 2^(n - 1) - 1 (largest) [sign bit - 0]
 * - 2^(n - 1) (smallest) [sign bit - 1] 1 extra number can be stored now
 * 
 * When storing floats and doubles we don't use 2's compliment
 * 
/*/ 