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
std::vector<std::vector<T>> _chain_matmul_recurse(const std::vector<std::vector<std::vector<T>>> &, const std::vector<std::vector<int>> &, const int &, const int &);

template <typename T>
std::vector<std::vector<T>> _matrix_chain_order(const std::vector<std::vector<std::vector<T>>> &);

template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &);

// implementation
template <typename T>
std::vector<std::vector<T>> _chain_matmul_recurse(const std::vector<std::vector<std::vector<T>>> &matrices, const std::vector<std::vector<int>> &order, const int &i, const int &j) {
    if (i == j) {
        return matrices[i];
    } else {
        return matmul(_chain_matmul_recurse(matrices, order, i, order[i][j]), _chain_matmul_recurse(matrices, order, order[i][j] + 1, j));
    }
}

template <typename T>
std::vector<std::vector<T>> _matrix_chain_order(const std::vector<std::vector<std::vector<T>>> &matrices) {
    // dimensions
    std::vector<int> dims;
    dims.push_back(matrices[0].size());
    for (const auto &matrix : matrices) {
        dims.push_back(matrix[0].size());
    }

    int n = matrices.size();

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
    // recursive chain matmul product computation
    return _chain_matmul_recurse(matrices, s, 0, n - 1);
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
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &matrices) {
    BOOST_ASSERT_MSG(matrices.size() > 1, "Minimum 2 matrices required for Matrix Multiplication");

    if (matrices.size() == 2) {
        return matmul(matrices[0], matrices[1]);
    } else if (matrices.size() == 3) {
        int a = matrices[0].size();
        int b = matrices[1].size();
        int c = matrices[2].size();
        int d = matrices[2][0].size();

        // matrices of size (a x b) (b x c) (c x d)
        // cost_l is (a x b x c) + (a x c x d)
        int cost_l = (a * c) * (b + d);
        // cost_l is (a x b x d) + (b x c x d)
        int cost_r = (b * d) * (a + c);

        if (cost_l > cost_r) {
            return matmul(matrices[0], matmul(matrices[1], matrices[2]));
        } else {
            return matmul(matmul(matrices[0], matrices[1]), matrices[2]);
        }
    } else {
        return _matrix_chain_order(matrices);
    }
}
} // namespace al