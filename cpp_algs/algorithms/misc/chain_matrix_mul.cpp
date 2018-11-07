#pragma once

/**
 * Algorithms - miscellaneous
 * chain_matrix_mul.cpp
 * Purpose: Performs chain matrix multiplication
 * 
 * @author Prabhsimran Singh
 * @version 1.0 28/10/18 
*/
#include <iostream>

namespace al {

/**
 * Performs chain matrix multiplication and returns the output matrix.
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
T **chain_matmul(T **, T **, const int &, const int &, const int &);

template <typename T>
T **chain_matmul(T **a, T **b, const int &m, const int &n, const int &k) {
}
} // namespace al