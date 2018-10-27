#include "../../../data-structures/singly_linked_list.cpp"
#include <iostream>

using namespace std;

int main() {

    int *arr = new int[10];
    for (int i = 1; i <= 10; i++)
        arr[i - 1] = i;

    SinglyLinkedList<int> *ll = new SinglyLinkedList<int>(arr, 10);
    ll->print();
    ll->insertUsingValue(101);
    ll->print();
    ll->deleteUsingValue(10);
    ll->print();
    ll->deleteUsingIndex(1);
    ll->print();
    ll->deleteUsingIndex(0);
    ll->print();
    LinkNode<int> *elem = ll->search(101);
    if (elem != NULL) {
        cout << "Found " << elem->value << "!" << endl;
    } else {
        cout << "Not Found!" << endl;
    }
    ll->reverse();
    ll->print();

    delete[] arr;
    delete ll;
    return 0;
}