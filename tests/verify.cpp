#include <iostream>
#include <vector>
using namespace std;

#include <boost/generator_iterator.hpp>
#include <boost/random.hpp>
#include <boost/timer/timer.hpp>

#include "cpp_algs.hpp"

template <typename T>
void init_matrices(vector<vector<vector<T>>> &, const vector<int> &, const T &, bool = false);

void time_test(const vector<int> &);

int main() {
    // Sorting
    vector<int> v = {541, 12, 56, 62, 1234, 656547, 123, 1, 6546, 51, 1334, 56612};
    al::heapSort(v);
    BOOST_ASSERT_MSG(std::is_sorted(v.begin(), v.end()), "sorting buggy");

    // Stack
    ds::Stack<int> s1;
    s1.push(10);
    s1.push(20);

    ds::Stack<int> s_copy;
    s_copy = s1;

    ds::Stack<int> s_copy2(s1);

    // Singly Linked List
    ds::SinglyLinkedList<int> sing;
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
    BOOST_ASSERT_MSG(s.search("!")->data == "!", "Singly linked list std::string search is buggy");
    BOOST_ASSERT_MSG(s.getSize() == 2, "Singly linked list getSize() is buggy");

    // Matrix Chain Multiplication
    vector<int> dims = {6, 4, 2, 1};

    vector<vector<vector<float>>> matrices;
    init_matrices<float>(matrices, dims, 1.0f);

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

    dims = {1000, 1234, 13, 542, 122, 11};
    time_test(dims);

    // cleanup
    return 0;
}

template <typename T>
void init_matrices(vector<vector<vector<T>>> &matrices, const vector<int> &dims, const T &data, bool random) {
    typedef boost::mt19937 RNGType;
    RNGType rng;
    boost::uniform_int<> random_iter(1, 10);
    boost::variate_generator<RNGType, boost::uniform_int<>> dice(rng, random_iter);

    for (int i = 0; i < dims.size() - 1; i++) {
        if (random) {
            vector<vector<T>> matrix(dims[i], vector<T>(dims[i + 1], dice()));
            matrices.push_back(matrix);
        } else {
            vector<vector<T>> matrix(dims[i], vector<T>(dims[i + 1], data));
            matrices.push_back(matrix);
        }
    }
}

void time_test(const vector<int> &dims) {
    vector<vector<vector<int>>> matrices;
    init_matrices<int>(matrices, dims, 1, true);
    vector<vector<int>> out;
    boost::timer::cpu_timer t;

    // matrix chain using DP
    t.start();
    out = al::chain_matmul<int>(matrices);
    t.stop();
    boost::timer::cpu_times const et1(t.elapsed());
    cout << boost::timer::format(et1) << endl;

    out.clear();

    // naive matrix chain
    out = matrices[0];
    t.start();
    for (int i = 1; i < matrices.size(); i++) {
        out = al::matmul(out, matrices[i]);
    }
    t.stop();
    boost::timer::cpu_times const et2(t.elapsed());
    cout << boost::timer::format(et2);
}