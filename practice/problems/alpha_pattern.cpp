#include <iostream>
using namespace std;

int main() {

    int N;

    cin >> N;
    int base = 'A';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            char alpha = base + i;
            cout << alpha;
        }
        cout << endl;
    }

    return 0;
}