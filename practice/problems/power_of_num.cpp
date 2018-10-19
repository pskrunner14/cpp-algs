#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int x, n;
    long power;

    cin >> x >> n;

    power = pow(x, n);
    cout << power << endl;
    return 0;
}