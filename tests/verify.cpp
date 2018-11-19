#include <cassert>
#include <iostream>
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

    int *arr = new int[5]{43, 44, 45, 46, 47};
    sing.insertArray(arr, 5);
    sing.print();
    cout << sing.getSize() << endl;

    cout << "Verified installation of library!" << '\n';

    // cleanup
    delete[] arr;
    return 0;
}