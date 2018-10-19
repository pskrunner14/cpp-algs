#include <iostream>
using namespace std;

int main() {

    int x, num_terms = 0, i = 1;
    cin >> x;

    while (num_terms < x) {
        int term = (3 * i) + 2;
        if (term % 4 != 0) {
            cout << term << " ";
            num_terms++;
        }
        i++;
    }
    cout << endl;
    return 0;
}