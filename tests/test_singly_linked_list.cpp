#include <iostream>
using namespace std;

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Singly Linked List test") {
    ds::SinglyLinkedList<int> s = ds::SinglyLinkedList<int>();
    REQUIRE(s.getSize() == 0);

    SECTION("adding nodes to singly linked list") {
        s.insertNode(101);
        s.insertNode(432);
        s.insertNode(123);
        REQUIRE(s.getSize() == 3);
    }

    SECTION("deleting nodes from singly linked list") {
        s.insertNode(101);
        s.insertNode(432);
        s.insertNode(123);
        REQUIRE(s.getSize() == 3);

        s.deleteNode(432);
        REQUIRE(s.getSize() == 2);
    }

    SECTION("adding array of nodes to singly linked list") {
        int *arr = new int[5]{43, 44, 45, 46, 47};
        s.insertArray(arr, 5);
        delete[] arr;

        REQUIRE(s.getSize() == 5);
    }

    SECTION("searching a node in singly linked list") {
        s.insertNode(44);
        REQUIRE(s.search(44)->value == 44);

        REQUIRE(s.search(103) == NULL);
    }
}