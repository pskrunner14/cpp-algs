#! /bin/bash

if !(g++ tests/catch_main.cpp -I tests/ -l cpp_algs -I cpp_algs/ && ./a.out) then
    echo "Test cases failed!"
    rm a.out
    exit 1
else
    echo "Test cases passed!"
    rm a.out
    exit 0
fi