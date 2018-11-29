#include <iostream>
#include <vector>
using namespace std;

#include "cpp_algs.hpp"

int main() {

    cout << "Singly Linked List: " << endl;
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

    cout << "Matrix Chain Multiplication: " << endl;
    vector<int> dims = {6, 4, 2, 1};

    vector<vector<vector<float>>> matrices;
    for (int i = 0; i < dims.size() - 1; i++) {
        int m = dims[i];
        int n = dims[i + 1];
        vector<vector<float>> matrix;
        for (int j = 0; j < m; j++) {
            vector<float> row;
            for (int k = 0; k < n; k++) {
                row.push_back(1.0f);
            }
            matrix.push_back(row);
        }
        matrices.push_back(matrix);
    }

    vector<vector<float>> out = al::chain_matmul<float>(matrices);

    for (int i = 0; i < out.size(); i++) {
        for (int j = 0; j < out[0].size(); j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Trie dictionary: " << endl;
    ds::Trie trie;

    trie.insertWord("hello");
    trie.insertWord("ShiT");
    trie.insertWord("Ships");
    trie.insertWord("help");
    trie.insertWord("hell");

    char c[] = {'a', 'b', 'c', '\0'};
    trie.insertWord(c);
    trie.printWords();

    cout << trie.containsWord("hello") << endl;
    cout << trie.containsWord("woah") << endl;

    trie.removeWord("hello");
    cout << trie.containsWord("hello") << endl;
    cout << trie.containsWord("hell") << endl;
    cout << trie.containsWord("help") << endl;
    trie.printWords();

    cout << "Verified installation of library!" << '\n';

    // cleanup
    return 0;
}