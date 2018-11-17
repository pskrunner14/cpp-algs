#include <iostream>
using namespace std;

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Queue test", "[DS]") {
    ds::Queue<int> q = ds::Queue<int>();
    REQUIRE(q.size() == 0);

    q.enqueue(10);
    q.enqueue(20);

    REQUIRE(q.size() == 2);
}