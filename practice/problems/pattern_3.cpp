#include <iostream>
using namespace std;

int main() {

    int N;

    cin >> N;

    cout << 1 << endl;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1)
                cout << 1;
            else
                cout << 2;
        }
        cout << endl;
    }

    return 0;
}