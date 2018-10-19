#include <iostream>
#include <cmath>
using namespace std;

// #<> is a preprocessor directive (things we need before compilation)
#define PI 3.14 // can't be changed at runtime and optimizes code
#define MULTIPLY(a, b) a * b
#define SQUARE(x) x * x

int a = 10; // global variable (bad practice tho bec risky)

double calcArea(double radius) {
    cout << a++ << endl;
    return PI * pow(radius, 2); // PI will be replaced by 3.14 before compilation
}

int main() {

    double radius = 5.65;
    cout << calcArea(radius) << endl;
    cout << a << endl;
    
    // Tricky parts
    // add brackets to avoid
    cout << MULTIPLY(2 + 3, 3 + 5) << endl; // 16 = 2 + 9 + 5
    cout << 36 / SQUARE(6) << endl; // 36 = (36 / 6) * 6
    return 0;
}