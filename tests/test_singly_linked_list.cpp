#include <iostream>
using namespace std;

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Singly Linked List test", "[DS]") {
    ds::SinglyLinkedList<int> sing = ds::SinglyLinkedList<int>();
    REQUIRE(sing.getSize() == 0);
    sing.insertNode(101);
    sing.insertNode(432);
    REQUIRE(sing.getSize() == 2);
    sing.deleteNode(432);
    REQUIRE(sing.getSize() == 1);
}