#include <iostream>
using namespace std;

int factorial(int n) {
    // base condition
    if (n == 0)
        return 1;
    // recursive call with simpler case until we reach base case
    return n * factorial(n - 1);
}

int main() {
    // CALL STACK (LIFO - last in first out)
    cout << factorial(4) << endl;
    return 0;
}

/**
 * RECURSION
 * conventional def: When a fn calls itself
 * 
 * We use recursion when the solution of a problem depends
 * on a smaller part of the problem.
 *
 */