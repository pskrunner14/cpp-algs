#include <iostream>
using namespace std;

// it is not allowed to dynamically alloc 2d array like
// new int[][];
// so we will have to store int* pointers of 1d array rows in
// int** 1d array of pointers essentially making it 2d 
int main() {

    int rows, cols;
    cin >> rows >> cols;
    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]; // each row can also have variable length unlike a 2d array allocated statically
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // delete all rows
    for (int i = 0; i < rows; i++)
        delete [] arr[i];
    // delete the row pointers table
    delete [] arr;


    return 0;
}