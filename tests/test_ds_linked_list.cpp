#include <iostream>
#include <memory>
#include <vector>
using namespace std;

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Singly Linked List test") {
    ds::SinglyLinkedList<int> s = ds::SinglyLinkedList<int>();
    REQUIRE(s.size() == 0);

    SECTION("adding nodes to singly linked list") {
        s.insertNode(101);
        s.insertNode(432);
        s.insertNode(123);
        REQUIRE(s.size() == 3);
    }

    SECTION("deleting nodes from singly linked list") {
        s.insertNode(101);
        s.insertNode(432);
        s.insertNode(123);
        REQUIRE(s.size() == 3);

        s.deleteNode(432);
        REQUIRE(s.size() == 2);
    }

    SECTION("adding array of nodes to singly linked list") {
        vector<int> vec = {43, 44, 45, 46, 47};
        s.insertArray(vec);

        REQUIRE(s.size() == 5);
    }

    SECTION("searching a node in singly linked list") {
        s.insertNode(44);
        REQUIRE(s.search(44)->data == 44);

        REQUIRE(s.search(103).get() == NULL);
    }
}

TEST_CASE("Double Linked List test") {
    ds::DoublyLinkedList<int> d = ds::DoublyLinkedList<int>();
    REQUIRE(d.size() == 0);

    SECTION("adding nodes to doubly linked list") {
        d.insertNode(101);
        d.insertNode(432);
        d.insertNode(123);
        REQUIRE(d.size() == 3);
    }

    SECTION("deleting nodes from doubly linked list") {
        d.insertNode(101);
        d.insertNode(432);
        d.insertNode(123);
        REQUIRE(d.size() == 3);

        d.deleteNode(432);
        REQUIRE(d.size() == 2);
    }

    SECTION("adding array of nodes to doubly linked list") {
        vector<int> vec = {43, 44, 45, 46, 47};
        d.insertArray(vec);

        REQUIRE(d.size() == 5);
    }

    SECTION("searching a node in doubly linked list") {
        d.insertNode(44);
        REQUIRE(d.search(44)->data == 44);

        REQUIRE(d.search(103).get() == NULL);
    }
}

TEST_CASE("Circular Singly Linked List test") {
    ds::CircularSinglyLinkedList<int> cs = ds::CircularSinglyLinkedList<int>();
    REQUIRE(cs.size() == 0);

    SECTION("adding nodes to circular singly linked list") {
        cs.insertNode(101);
        cs.insertNode(432);
        cs.insertNode(123);
        REQUIRE(cs.size() == 3);
    }

    SECTION("deleting nodes from circular singly linked list") {
        cs.insertNode(101);
        cs.insertNode(432);
        cs.insertNode(123);
        REQUIRE(cs.size() == 3);

        cs.deleteNode(432);
        REQUIRE(cs.size() == 2);
    }

    SECTION("adding array of nodes to circular singly linked list") {
        vector<int> vec = {43, 44, 45, 46, 47};
        cs.insertArray(vec);

        REQUIRE(cs.size() == 5);
    }

    SECTION("searching a node in circular singly linked list") {
        cs.insertNode(44);
        REQUIRE(cs.search(44)->data == 44);

        REQUIRE(cs.search(103).get() == NULL);
    }
}