#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

#include <boost/range/algorithm_ext/push_back.hpp>
#include <boost/range/irange.hpp>

#include <catch2/catch.hpp>
#include <cpp_algs.hpp>

TEST_CASE("Sorting Alorithms test") {

    auto rng = std::default_random_engine{};

    std::vector<int> v_int;
    boost::push_back(v_int, boost::irange<int>(1, 1001));
    REQUIRE(v_int.size() == 1000);
    std::shuffle(std::begin(v_int), std::end(v_int), rng);
    REQUIRE(!std::is_sorted(std::begin(v_int), std::end(v_int)));

    std::vector<char> v_char;
    for (int i = 0; i < 1000; i++) {
        char c = i % 255;
        v_char.push_back(c);
    }
    REQUIRE(v_char.size() == 1000);
    std::shuffle(std::begin(v_char), std::end(v_char), rng);
    REQUIRE(!std::is_sorted(std::begin(v_char), std::end(v_char)));

    std::vector<double> v_double;
    boost::push_back(v_double, boost::irange<double>(1.0, 1001.0));
    REQUIRE(v_double.size() == 1000);
    std::shuffle(std::begin(v_double), std::end(v_double), rng);
    REQUIRE(!std::is_sorted(std::begin(v_double), std::end(v_double)));

    SECTION("Bubble Sort") {
        al::bubbleSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::bubbleSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::bubbleSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }

    SECTION("Heap Sort") {
        al::heapSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::heapSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::heapSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }

    SECTION("Insertion Sort") {
        al::insertionSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::insertionSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::insertionSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }

    SECTION("Merge Sort") {
        al::mergeSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::mergeSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::mergeSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }

    SECTION("Quick Sort") {
        al::quickSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::quickSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::quickSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }

    SECTION("Selection Sort") {
        al::selectionSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::selectionSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::selectionSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }

    SECTION("Shell Sort") {
        al::shellSort<int>(v_int);
        REQUIRE(std::is_sorted(std::begin(v_int), std::end(v_int)));

        al::shellSort<char>(v_char);
        REQUIRE(std::is_sorted(std::begin(v_char), std::end(v_char)));

        al::shellSort<double>(v_double);
        REQUIRE(std::is_sorted(std::begin(v_double), std::end(v_double)));
    }
}