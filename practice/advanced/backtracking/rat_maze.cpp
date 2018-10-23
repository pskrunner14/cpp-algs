#include <iostream>
using namespace std;

// Rat in a Maze problem
// we have an NxN 2D maze containing 1 and 0
// 1 means you can pass through but not through 0
// and the rat can move in the 4 directions
// initial position of the rat is (0, 0)
// and it has to reach (N - 1, N - 1)

void print_path_helper(int **arr, int n, bool **visited, int x, int y) {
    // destination
    if (x == n - 1 && y == n - 1) {
        visited[x][y] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    // invalid position
    if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || visited[x][y] == 1) {
        return;
    }
    // valid position
    visited[x][y] = true;
    print_path_helper(arr, n, visited, x - 1, y);
    print_path_helper(arr, n, visited, x + 1, y);
    print_path_helper(arr, n, visited, x, y - 1);
    print_path_helper(arr, n, visited, x, y + 1);
    visited[x][y] = false;
}

bool has_path_helper(int **arr, int n, bool **visited, int x, int y) {
    // destination 
    if (x == n - 1 && y == n - 1) {
        return true;
    }
    // invalid position
    if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || visited[x][y] == 1) {
        return false;
    }
    // valid position
    visited[x][y] = true;
    if (has_path_helper(arr, n, visited, x - 1, y)) {
        return true;
    }
    if (has_path_helper(arr, n, visited, x + 1, y)) {
        return true;
    }
    if (has_path_helper(arr, n, visited, x, y - 1)) {
        return true;
    }
    if (has_path_helper(arr, n, visited, x, y + 1)) {
        return true;
    }
    // remove current from visited since it is not a solution
    visited[x][y] = false;
    return false;
}

void print_path(int **arr, int n) {
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    print_path_helper(arr, n, visited, 0, 0);
}

bool has_path(int **arr, int n) {
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    return has_path_helper(arr, n, visited, 0, 0);
}

int main() {
    int **arr;
    int n;

    cin >> n;
    arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    if (has_path(arr, n)) {
        cout << "Possible paths:" << endl;
        print_path(arr, n);
    } else {
        cout << "Hard luck!" << endl;
    }

    return 0;
}