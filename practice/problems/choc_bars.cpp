#include <iostream>
using namespace std;

bool all_eaten(bool* arr, int len) {
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (!arr[i])
            return false;
    }
    return flag;
}

int main() {

    int T;
    cin >> T;

    int **cases = new int*[T];
    bool **eaten = new bool*[T];

    int *steps = new int[T];
    int *case_lens = new int[T];

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        
        cases[i] = new int[N];
        eaten[i] = new bool[N];
        case_lens[i] = N;
        steps[i] = 0;

        for (int j = 0; j < N; j++) {
            eaten[i][j] = false;
        }

        for (int j = 0; j < N; j++)
            cin >> cases[i][j];
    }

    for (int i = 0; i < T; i++) {
        int max_index = 0;
        int max_nums = 0;
        int index = 0;
        int nums = 0;
        while (!all_eaten(eaten[i], case_lens[i])) {
            for (int j = 0; j < case_lens[i] - 1; j++) {
                for (int k = j + 1; k < case_lens[i]; k++) {
                    if (cases[i][k] < cases[i][j] && (!eaten[i][k] && !eaten[i][j])) {
                        nums++;
                    } else {
                        if (nums > max_nums) {
                            max_index = index;
                            max_nums = nums;
                        }
                        index = i + 1;
                        nums = 0;
                    }
                }
            }
            for (int j = max_index; j < max_nums + 1; j++)
                eaten[i][j] = true;
            steps[i]++;
        }
    }

    for (int i = 0; i < T; i++)
        cout << steps[i] << endl;
    return 0;
}