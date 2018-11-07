#pragma once

/**
 * Algorithms - miscellaneous
 * matrix_mul.cpp
 * Purpose: Performs matrix multiplication
 * 
 * @author Prabhsimran Singh
 * @version 1.0 28/10/18 
*/
#include <iostream>

namespace al {

/**
 * Performs matrix multiplication and returns the output matrix.
 * 
 * @param a first mxn matrix.
 * @param b second nxk matrix.
 * @param m the no. of rows in a.
 * @param n the no. of cols in a/rows in b.
 * @param k the no. of col in b.
 * 
 * @returns the mxk output matrix.
*/
template <typename T>
T **matmul(T **, T **, const int &, const int &, const int &);

template <typename T>
T **matmul(T **a, T **b, const int &m, const int &n, const int &k) {
    T **out = new T *[m];
    for (int i = 0; i < m; i++) {
        out[i] = new T[k];
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
} // namespace al