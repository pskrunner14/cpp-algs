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