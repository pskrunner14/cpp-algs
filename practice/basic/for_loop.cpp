#include <iostream>
using namespace std;

int main() {

    for (int i = 0, j = 5; i < 5, j < 10; i++, j++) {
        cout << i << j << endl;
    }
    return 0;
}