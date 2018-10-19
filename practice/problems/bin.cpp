#include <iostream>
#include <cmath>
using namespace std;

unsigned getNumberOfDigits (unsigned i) {
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main() {
    int num, n = 0, index = 0, remain;
    cin >> num;

    while (num != 0) {
        remain = num % 10;
        if (remain == 1)
            n += pow(2, index);
        num /= 10;
        index++;
    }
    cout << n << endl;

    return 0;
}