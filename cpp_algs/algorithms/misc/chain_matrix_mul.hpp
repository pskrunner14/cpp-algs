#pragma once

/**
 * Algorithms - miscellaneous
 * chain_matrix_mul.cpp
 * Purpose: Performs chain matrix multiplication
 * 
 * @author Prabhsimran Singh
 * @version 1.0 28/11/18 
*/
#include <iostream>
#include <limits>
#include <vector>

#include "matrix_mul.hpp"

namespace al {

// interface
template <typename T>
std::vector<std::vector<T>> _matrix_chain_order(const std::vector<std::vector<std::vector<T>>> &, const std::vector<int> &);

template <typename T>
std::vector<std::vector<T>> _chain_matmul_recurse(const std::vector<std::vector<std::vector<T>>> &, const std::vector<std::vector<int>> &, const int &, const int &);

template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &, const std::vector<int> &);

// implementation
template <typename T>
std::vector<std::vector<T>> _matrix_chain_order(const std::vector<std::vector<std::vector<T>>> &matrices, const std::vector<int> &dims) {
    int n = dims.size() - 1;

    // initialization
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));

    // calulate costs
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            m[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + (dims[i] * dims[k + 1] * dims[j + 1]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    // recursive computations
    return _chain_matmul_recurse(matrices, s, 0, n - 1);
}

template <typename T>
std::vector<std::vector<T>> _chain_matmul_recurse(const std::vector<std::vector<std::vector<T>>> &matrices, const std::vector<std::vector<int>> &s, const int &i, const int &j) {
    if (i == j) {
        return matrices[i];
    } else {
        return al::matmul(_chain_matmul_recurse(matrices, s, i, s[i][j]), _chain_matmul_recurse(matrices, s, s[i][j] + 1, j));
    }
}

/**
 * Performs chain matrix multiplication and returns the output matrix.
 *
 * @param matrices the vector of matrices in correct order of multiplication.
 * @param dims the vector of dimensions for the said matrices.
 * 
 * @returns the final output matrix after computing optimal paranthesizations.
*/
template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &matrices, const std::vector<int> &dims) {
    BOOST_ASSERT_MSG(matrices.size() > 1, "Minimum 2 matrices required for Matrix Chain Multiplication");
    BOOST_ASSERT_MSG(dims.size() > 2, "Minimum 3 dimensions required for Matrix Chain Multiplication");

    if (matrices.size() == 2) {
        return al::matmul(matrices[0], matrices[1]);
    } else {
        return _matrix_chain_order(matrices, dims);
    }
}
} // namespace al