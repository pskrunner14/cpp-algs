#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include "cpp_algs.hpp"

int main() {

    ds::SinglyLinkedList<int> sing = ds::SinglyLinkedList<int>();
    sing.insertNode(10);
    sing.insertNode(20);
    sing.print();
    cout << sing.getSize() << endl;

    ds::SinglyLinkedList<string> s = ds::SinglyLinkedList<string>();
    s.insertNode("hello");
    s.insertNode(", ");
    s.insertNode("world");
    s.insertNode("!");
    s.print();
    cout << s.getSize() << endl;

    vector<int> vec = {43, 44, 45, 46, 47};
    sing.insertArray(vec);
    sing.print();
    cout << sing.getSize() << endl;

    vector<int> dims;
    int dim;

    cout << "Please enter the dims: (-1 for termination)" << endl;
    cin >> dim;
    while (dim != -1) {
        dims.push_back(dim);
        cin >> dim;
    }

    vector<vector<vector<int>>> matrices;
    for (int i = 0; i < dims.size() - 1; i++) {
        int m = dims[i];
        int n = dims[i + 1];
        vector<vector<int>> matrix;
        for (int j = 0; j < m; j++) {
            vector<int> row;
            for (int k = 0; k < n; k++) {
                row.push_back(1);
            }
            matrix.push_back(row);
        }
        matrices.push_back(matrix);
    }

    vector<vector<int>> out = al::chain_matmul(matrices, dims);

    for (int i = 0; i < out.size(); i++) {
        for (int j = 0; j < out[0].size(); j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Verified installation of library!" << '\n';

    // cleanup
    return 0;
}