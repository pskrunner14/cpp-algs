#include <iostream>
using namespace std;

// fibo series: 0 1 1 2 3 5 8 13 21 ....
// we have to output the nth fibo number (0 is 0th and 1 is 1st...)

// here n means index
int fibo(int n) {
    // base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    // return recursive sum of fibo(n - 1) and fibo(n - 2)
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    cout << fibo(4) << endl;
    return 0;
}

/**
 * PMI [START THE QUES WITH PMI NOT CODE 
 * (see how code is working [call stack graph] 
 * after you're done implementing it)]
 * 
 * 1. Base Case: Prove F(0) and F(1) is true.
 * 2. IH: Assume F(i) is true for all 0 <= i <= k. [more powerful]
 * 3. IS: Use (2) to prove F(k + 1) is true.
 */