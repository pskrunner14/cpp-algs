#include <iostream>
using namespace std;

int main() {

    int N, prev, current;
    bool flag = true, break_point = false, strictly_inc = true;
    cin >> N;

    cin >> prev;
    
    for (int i = 1; i < N; i++) {
        cin >> current;
        if (!break_point) {
            if (current > prev && !strictly_inc)
                break_point = true;
            else
                strictly_inc = false;
        } else {
            if (current < prev)
                flag = false;
        }
        prev = current;
    }
    if (flag)
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    return 0;
}