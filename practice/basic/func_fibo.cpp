#include <iostream>
using namespace std;

bool checkMember(int n) {

    int prev1 = 0, prev2 = 1, sum = 1;

    while (sum < n) {
        prev1 = prev2;
        prev2 = sum;
        sum = prev1 + prev2;
    }
    if (sum == n)
        return true;
    return false;
}