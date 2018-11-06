#include <iostream>
using namespace std;

#include "doubly_linked_list.hpp"

int main() {
    ds::DoublyLinkedList<int> ll = ds::DoublyLinkedList<int>();
    ll.insertNode(10);
    ll.insertNode(11);
    ll.print();
    return 0;
}