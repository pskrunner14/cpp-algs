#include <iostream>
using namespace std;

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Singly Linked List test", "[DS]") {
    ds::SinglyLinkedList<int> *sing = new ds::SinglyLinkedList<int>();
    REQUIRE(sing->getSize() == 0);

    sing->insertNode(101);
    sing->insertNode(432);
    REQUIRE(sing->getSize() == 2);

    sing->deleteNode(432);
    REQUIRE(sing->getSize() == 1);

    int *arr = new int[5]{43, 44, 45, 46, 47};
    sing->insertArray(arr, 5);
    REQUIRE(sing->getSize() == 6);

    // cleanup
    delete[] arr;
    delete sing;
}