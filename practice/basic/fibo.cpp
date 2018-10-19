/**
 * Print Fibonacci series
 * 
 * > Simple While Loop
 * 
 * n = input()
 * prev1 = 0
 * prev2 = 1
 * print(prev1)
 * print(prev2)
 * sum = prev1 + prev2
 * while sum < n:
 *      print(sum)
 *      prev1 = prev2 
 *      prev2 = sum
 *      sum = prev1 + prev2
 * 
 * > Recursion
/*/

#include <iostream>
using namespace std;

int main() {

    int N, index = 2, prev1 = 0, prev2 = 1, sum = 1;
    cin >> N;

    while (index < N) {
        prev1 = prev2;
        prev2 = sum;
        sum = prev1 + prev2;
        index++;
    }
    cout << sum << endl;

    return 0;
}