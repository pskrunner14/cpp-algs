#include <iostream>
using namespace std;

int main() {

    int a = 'a', z = 'z', A = 'A', Z = 'Z', alpha;
    char entered;

    cin >> entered;
    alpha = entered;

    if (alpha >= A && alpha <= Z)
        cout << 1 << endl;
    else if (alpha >= a && alpha <= z)
        cout << 0 << endl;
    else
        cout << -1 << endl;

    return 0;
}