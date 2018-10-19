#include <iostream>
using namespace std;

int main() {

    int N, val = 1;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            cout << val;
            val++;
        }
        cout << endl;
        val -= i - 1;
    }

    return 0;
}