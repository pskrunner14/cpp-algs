#include <iostream>
using namespace std;

#include "cpp_algs.hpp"

int main() {

    ds::SinglyLinkedList<int> sing = ds::SinglyLinkedList<int>();
    sing.insertNode(10);
    sing.insertNode(20);
    sing.print();

    cout << "Verified installation of library!" << '\n';
    return 0;
}