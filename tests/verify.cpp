#include <iostream>
#include <vector>
using namespace std;

#include "cpp_algs.hpp"

int main() {
    // Singly Linked List
    ds::SinglyLinkedList<int> sing = ds::SinglyLinkedList<int>();
    BOOST_ASSERT_MSG(sing.getSize() == 0, "Singly linked list getSize() is buggy");
    sing.insertNode(10);
    BOOST_ASSERT_MSG(sing.contains(10), "Singly linked list insertion is buggy");
    sing.insertNode(20);
    BOOST_ASSERT_MSG(sing.contains(20), "Singly linked list search is buggy");
    sing.deleteNode(20);
    BOOST_ASSERT_MSG(!sing.contains(20), "Singly linked list deletion is buggy");

    vector<int> vec = {43, 44, 45, 46, 47};
    sing.insertArray(vec);
    for (const auto &v : vec) {
        BOOST_ASSERT_MSG(sing.contains(v), "Singly linked list insertion of std::vector<int> is buggy");
    }
    BOOST_ASSERT_MSG(sing.getSize() == 6, "Singly linked list getSize() is buggy");

    ds::SinglyLinkedList<string> s = ds::SinglyLinkedList<string>();
    BOOST_ASSERT_MSG(s.getSize() == 0, "Singly linked list getSize() is buggy");
    s.insertNode("hello");
    BOOST_ASSERT_MSG(s.contains("hello"), "Singly linked list std::string insertion is buggy");
    s.insertNode("world");
    BOOST_ASSERT_MSG(s.contains("world"), "Singly linked list std::string contains is buggy");
    s.deleteNode("hello");
    BOOST_ASSERT_MSG(!s.contains("hello"), "Singly linked list std::string deletion is buggy");
    s.insertNode("!");
    BOOST_ASSERT_MSG(s.search("!")->value == "!", "Singly linked list std::string search is buggy");
    BOOST_ASSERT_MSG(s.getSize() == 2, "Singly linked list getSize() is buggy");

    // Matrix Chain Multiplication
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
            BOOST_ASSERT_MSG(out[i][j] == 8, "Matrix chain multiplication is buggy");
        }
    }

    // Trie dictionary
    ds::Trie trie;

    trie.insertWord("hello");
    BOOST_ASSERT_MSG(trie.containsWord("hello"), "Trie std::string insertion is buggy");
    trie.insertWord("help");
    BOOST_ASSERT_MSG(trie.containsWord("help"), "Trie std::string insertion is buggy");
    trie.insertWord("hell");
    BOOST_ASSERT_MSG(trie.containsWord("hell"), "Trie std::string insertion is buggy");

    char c[] = {'a', 'b', 'c', '\0'};
    trie.insertWord(c);
    BOOST_ASSERT_MSG(trie.containsWord("abc"), "Trie (char *) insertion is buggy");

    trie.removeWord("hello");
    BOOST_ASSERT_MSG(!trie.containsWord("hello"), "Trie std::string removal is buggy");
    trie.removeWord(c);
    BOOST_ASSERT_MSG(!trie.containsWord(c), "Trie (char *) removal is buggy");

    cout << "Verified installation of library!" << '\n';

    // cleanup
    return 0;
}