#include <iostream>
using namespace std;

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Queue test") {
    ds::Queue<int> q = ds::Queue<int>(20);
    REQUIRE(q.size() == 0);

    SECTION("adding elements to queue") {
        q.enqueue(10);
        q.enqueue(20);
        REQUIRE(q.size() == 2);
        REQUIRE(q.peek() == 10);
    }
}

TEST_CASE("Deque test") {
    ds::Deque<int> d = ds::Deque<int>(20);
    REQUIRE(d.size() == 0);

    SECTION("adding elements to deque") {
        d.enqueue_back(10);
        d.enqueue_back(20);
        REQUIRE(d.size() == 2);
        REQUIRE(d.peek_front() == 10);
    }
}

TEST_CASE("Stack test") {
    ds::Stack<int> s = ds::Stack<int>(20);
    REQUIRE(s.size() == 0);

    SECTION("adding elements to stack") {
        s.push(10);
        s.push(20);
        REQUIRE(s.size() == 2);
        REQUIRE(s.top() == 20);
    }
}