#include <iostream>
using namespace std;

int main() {

    int n, key, index = -1;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    for (int i = 0; i < n; i++) {
        if (key == arr[i])
            index = i;
            break;
    }

    cout << index << endl;
    return 0;
}