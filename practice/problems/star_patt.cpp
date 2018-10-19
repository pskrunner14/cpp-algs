#include <iostream>
using namespace std;

int main() {

    int N, total;

    cin >> N;
    total = 2 * N - 1;

    for (int i = 1; i <= N; i++) {
        int stars = 2 * i - 1;
        int spaces = (total - stars) / 2;
        for (int j = 0; j < spaces; j++)
            cout << " ";
        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}