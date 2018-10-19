#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, index = 0, remain = 0;
    long bin = 0;
    cin >> num;

    while (num != 0) {
        remain = log2((float) num);
        bin += (long) pow(10, remain);
        num = num % (int) pow(2, remain);
    }
    cout << bin << endl;

    return 0;
}