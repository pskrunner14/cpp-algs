#include <iostream>
using namespace std;

int main() {

    int N, c;
    cin >> N >> c;

    if (c == 1) {
        int sum = 0;
        for (int i = 1; i <= N; i++)
            sum += i;
        cout << sum << endl;
    } else if (c == 2) {
        int prod = 1;
        for (int i = 1; i <= N; i++)
            prod *= i;
        cout << prod << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}