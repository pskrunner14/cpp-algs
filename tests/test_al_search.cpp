#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#include <boost/range/algorithm_ext/push_back.hpp>
#include <boost/range/irange.hpp>

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Searching Algorithms test") {

    std::vector<int> v_int;
    boost::push_back(v_int, boost::irange<int>(1, 1001));
    REQUIRE(v_int.size() == 1000);

    std::vector<char> v_char;
    for (int i = 33; i < 128; i++) {
        char c = i;
        if (c != 'z')
            v_char.push_back(c);
    }
    REQUIRE(v_char.size() == 94);

    std::vector<double> v_double;
    boost::push_back(v_double, boost::irange<double>(1.0, 1001.0));
    REQUIRE(v_double.size() == 1000);

    SECTION("Linear Search") {
        REQUIRE(al::linearSearch<int>(v_int, 500) == 499);
        REQUIRE(al::linearSearch<int>(v_int, 0) == -1);

        REQUIRE(al::linearSearch<char>(v_char, 'a') == 64);
        REQUIRE(al::linearSearch<char>(v_char, 'z') == -1);

        REQUIRE(al::linearSearch<double>(v_double, 150.0) == 149);
        REQUIRE(al::linearSearch<double>(v_double, 0.0) == -1);
    }

    SECTION("Binary Search") {
        REQUIRE(al::binarySearch<int>(v_int, 500) == 499);
        REQUIRE(al::binarySearch<int>(v_int, 0) == -1);

        REQUIRE(al::binarySearch<char>(v_char, 'a') == 64);
        REQUIRE(al::binarySearch<char>(v_char, 'z') == -1);

        REQUIRE(al::binarySearch<double>(v_double, 150.0) == 149);
        REQUIRE(al::binarySearch<double>(v_double, 0.0) == -1);
    }

    SECTION("Ternary Search") {
        REQUIRE(al::ternarySearch<int>(v_int, 500) == 499);
        REQUIRE(al::ternarySearch<int>(v_int, 0) == -1);

        REQUIRE(al::ternarySearch<char>(v_char, 'a') == 64);
        REQUIRE(al::ternarySearch<char>(v_char, 'z') == -1);

        REQUIRE(al::ternarySearch<double>(v_double, 150.0) == 149);
        REQUIRE(al::ternarySearch<double>(v_double, 0.0) == -1);
    }
}