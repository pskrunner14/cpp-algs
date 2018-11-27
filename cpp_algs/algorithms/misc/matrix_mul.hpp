#pragma once

/**
 * Algorithms - miscellaneous
 * matrix_mul.cpp
 * Purpose: Performs matrix multiplication
 * 
 * @author Prabhsimran Singh
 * @version 2.0 28/11/18 
*/
#include <cassert>
#include <iostream>
#include <vector>

namespace al {

// interface
template <typename T>
std::vector<std::vector<T>> matmul(const std::vector<std::vector<T>> &, const std::vector<std::vector<T>> &);

// implementation

/**
 * Performs matrix multiplication and returns the output matrix.
 * 
 * @param a first mxn matrix.
 * @param b second nxk matrix.
 * 
 * @returns the mxk output matrix.
*/
template <typename T>
std::vector<std::vector<T>> matmul(const std::vector<std::vector<T>> &a, const std::vector<std::vector<T>> &b) {
    std::vector<std::vector<T>> out;
    int m = a.size();
    int n = a[0].size();
    int k = b[0].size();

    assert(n == b.size());

    for (int i = 0; i < m; i++) {
        std::vector<T> current;
        for (int j = 0; j < k; j++) {
            T sum = 0;
            for (int c = 0; c < n; c++) {
                sum += a[i][c] * b[c][j];
            }
            current.push_back(sum);
        }
        out.push_back(current);
    }
    return out;
}
} // namespace al