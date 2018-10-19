#include <iostream>
using namespace std;

int main() {

    /* Arithmetic Operators */

    int c, f;

    cout << "Enter the Fahrenheit value: " << endl;
    cin >> f;

    c = (5.0 / 9) * (f - 32);  // the int only stores the whole number part before the decimal
    cout << "Temperature in Celcius: " << c << " C" << endl;

    cout << (5.0 / 9) * (f - 32) << endl;
    cout << 10 % 3 << endl;

    int a, b;
    cout << "Enter a and b: " << endl;
    cin >> a >> b;

    /* Relational Operators */

    bool isEqual = (a == b);
    bool isGreater = (a > b);
    bool isLess = (a < b);

    cout << "Are they equal: " << isEqual << endl;
    cout << "Is a greater: " << isGreater << endl;
    cout << "Is b greater: " << isLess << endl;

    /* Logical Operators */

    bool greaterAndEqualTo = (isGreater && isEqual);
    bool greaterOrEqualTo = (isGreater || isEqual);
    bool notGreaterOrEqualTo = (!greaterOrEqualTo);

    cout << "Greater and Equal to: " << greaterAndEqualTo << endl;
    cout << "Greater or Equal to: " << greaterOrEqualTo << endl;
    cout << "Not Greater or Equal to: " << notGreaterOrEqualTo << endl;

    // double a = 55.5;
    // int b = 55;
    // a = a % 10; // error
    // b = b % 10;
    // cout << a << " " << b << endl;

    return 0;
}

// Division operator logic
/**
 *
 * Note:
 * It will only give you a float if atleast one 
 * of either the numerator or the denominator is 
 * a floating point number.
 * 
 * int / int = int
 * float / int = float
 * double / int = double
 * 
 * 
 * Arithmetic operators
 * 
 * +, -, /, %, *
/*/ 