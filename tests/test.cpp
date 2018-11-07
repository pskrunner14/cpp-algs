#include <iostream>
using namespace std;

#include "algorithms/searching/ternary_search.hpp"
#include "data_structures/doubly_linked_list.hpp"

int main() {
    ds::DoublyLinkedList<int> ll = ds::DoublyLinkedList<int>();
    ll.insertNode(10);
    ll.insertNode(11);
    ll.print();

    int *arr = new int[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    int index = al::ternarySearch(arr, 1000, 567);
    if (index == 567) {
        cout << "ternary search works!" << endl;
    }
    return 0;
}