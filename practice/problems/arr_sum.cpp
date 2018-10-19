#include <iostream>
#include <climits>
using namespace std;

int main() {

    int n, sum = 0;
    cin >> n;

    int b[n];

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }
    cout << sum << endl;

    return 0;
}