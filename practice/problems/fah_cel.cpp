#include <iostream>
using namespace std;

int main() {

    int S, E, W;

    cin >> S >> E >> W;

    for (int f = S; f <= E; f += W) {
        int c = (5.0 / 9) * (f - 32);
        cout << f << "\t" << c << endl;
    }

    return 0;
}