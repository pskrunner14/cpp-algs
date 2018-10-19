/**
 * Prime Number problem
 * 
 * to reduce number of computations we can take the
 * terminating condition to be div <= sqrt(n)
/*/

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num) {
    int limit = (int) sqrt((float) num);
    for (int i = num - 1; i >= limit; i--) {
        if (num % i == 0 && i != 1)
            return false;
    }
    return true;
}

int main() {

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        if (is_prime(i))
            cout << i << endl; 
    }
    return 0;
}