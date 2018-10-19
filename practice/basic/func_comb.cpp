#include <iostream>
using namespace std;

// nCr = n! / r! * (n-r)!

int factorial(int n) {
    int fact = 1;
    int i = 1;
    while (i <= n) {
        fact *= i;
        i++;
    }
    return fact;
}

int main() {

    int n, r, n_C_r, fact_n, fact_r, fact_n_r;
    cin >> n >> r;

    fact_n = factorial(n);
    fact_r = factorial(r);
    fact_n_r = factorial(n - r);

    n_C_r = fact_n / (fact_r * fact_n_r);

    cout << n_C_r << endl;

    return 0;
}