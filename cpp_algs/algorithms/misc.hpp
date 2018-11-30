/**
 * MIT License
 *
 * Copyright (c) 2018 Prabhsimran Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

/**
 * Algorithms - miscellaneous
 * misc.cpp
 * Purpose: Miscelaneous collection of algorithms
 * 
 * @author Prabhsimran Singh
 * @version 2.0 29/11/18 
*/
#include <iostream>
#include <limits>
#include <vector>

namespace al {

// ---------------------------------------------- Interface ---------------------------------------------------//

// matrix multiplication
template <typename T>
std::vector<std::vector<T>> matmul(const std::vector<std::vector<T>> &, const std::vector<std::vector<T>> &);

// chain matrix multiplication
template <typename T>
std::vector<std::vector<T>> _chain_matmul_recurse(const std::vector<std::vector<std::vector<T>>> &, const std::vector<std::vector<int>> &, const int &, const int &);

template <typename T>
std::vector<std::vector<T>> _matrix_chain_order(const std::vector<std::vector<std::vector<T>>> &);

template <typename T>
std::vector<std::vector<T>> _chain_matmul_three(const std::vector<std::vector<std::vector<T>>> &);

template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &);

// -------------------------------------------- Implementation --------------------------------------------------//

// matrix multiplication
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
    int m = a.size();
    int n = a[0].size();
    int k = b[0].size();

    BOOST_ASSERT_MSG(n == b.size(), "No. of columns in first matrix don't match no. of rows in second.");

    std::vector<std::vector<T>> out(m, std::vector<T>(k));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            T sum = 0;
            for (int c = 0; c < n; c++) {
                sum += a[i][c] * b[c][j];
            }
            out[i][j] = sum;
        }
    }
    return out;
}

// chain matrix multiplication
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
    std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> order(n, std::vector<int>(n, 0));

    // calulate costs
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            cost[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; k++) {
                int q = cost[i][k] + cost[k + 1][j] + (dims[i] * dims[k + 1] * dims[j + 1]);
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                    order[i][j] = k;
                }
            }
        }
    }

    // recursive matrix chain product computation
    return _chain_matmul_recurse(matrices, order, 0, n - 1);
}

template <typename T>
std::vector<std::vector<T>> _chain_matmul_three(const std::vector<std::vector<std::vector<T>>> &matrices) {

    int a = matrices[0].size();
    int b = matrices[1].size();
    int c = matrices[2].size();
    int d = matrices[2][0].size();

    // matrices of size (a x b) (b x c) (c x d)
    // cost_l is (a x b x c) + (a x c x d)
    int cost_l = (a * c) * (b + d);
    // cost_r is (a x b x d) + (b x c x d)
    int cost_r = (b * d) * (a + c);

    if (cost_l > cost_r) {
        return matmul(matrices[0], matmul(matrices[1], matrices[2]));
    } else {
        return matmul(matmul(matrices[0], matrices[1]), matrices[2]);
    }
}

/**
 * Performs chain matrix multiplication and returns the output matrix.
 * 
 * Reference: Introduction to Algorithms [https://mitpress.mit.edu/books/introduction-algorithms-third-edition]
 *
 * @param matrices the vector of matrices in correct order of multiplication.
 * @returns the final output matrix after computing optimal paranthesizations.
*/
template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &matrices) {
    BOOST_ASSERT_MSG(!matrices.empty(), "Matrices are empty");

    if (matrices.size() == 1) {
        return matrices[0];
    } else if (matrices.size() == 2) {
        return matmul(matrices[0], matrices[1]);
    } else if (matrices.size() == 3) {
        // faster than general chain matmul
        return _chain_matmul_three(matrices);
    } else {
        return _matrix_chain_order(matrices);
    }
}
} // namespace al