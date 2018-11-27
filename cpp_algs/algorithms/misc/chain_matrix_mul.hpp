#pragma once

/**
 * Algorithms - miscellaneous
 * chain_matrix_mul.cpp
 * Purpose: Performs chain matrix multiplication
 * 
 * @author Prabhsimran Singh
 * @version 1.0 28/11/18 
*/
#include <climits>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

#include "matrix_mul.hpp"

namespace al {

template <typename T>
std::vector<std::vector<T>> matrix_chain_order(const std::vector<int> &);

template <typename T>
void get_optimal_parans(const std::vector<std::vector<T>> &s, std::string &str, int &, int &);

template <typename T>
std::vector<std::vector<T>> parse_and_compute(const std::string &, const std::vector<std::vector<std::vector<T>>> &);

/**
 * Performs chain matrix multiplication and returns the output matrix.
 *
 * @returns the final output matrix after computing optimal paranthesizations.
*/
template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &, const std::vector<int> &);

template <typename T>
std::vector<std::vector<T>> matrix_chain_order(const std::vector<int> &p) {
    int n = p.size() - 1;
    vector<vector<int>> m;
    vector<vector<int>> s;

    // initialization
    for (int i = 0; i <= n; i++) {
        vector<int> curr;
        for (int j = 0; j <= n; j++) {
            curr.push_back(0);
        }
        m.push_back(curr);
    }
    for (int i = 0; i <= n - 1; i++) {
        vector<int> curr;
        for (int j = 0; j <= n; j++) {
            curr.push_back(0);
        }
        s.push_back(curr);
    }

    // computation
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return s;
}

template <typename T>
void get_optimal_parans(const std::vector<std::vector<T>> &s, std::string &str, const int &i, const int &j) {
    if (i == j) {
        str += '.' + std::to_string(i - 1) + '.';
    } else {
        str += '(';
        get_optimal_parans<T>(s, str, i, s[i][j]);
        get_optimal_parans<T>(s, str, s[i][j] + 1, j);
        str += ')';
    }
}

template <typename T>
std::vector<std::vector<T>> parse_and_compute(const std::string &exp, const std::vector<std::vector<std::vector<T>>> &matrices) {
    std::vector<std::vector<T>> out;
    std::stack<char> pending;
    pending.push('(');
    int i = 1;
    while (!pending.empty()) {
        if (exp[i] == ')') {
            std::vector<std::vector<std::vector<T>>> current;
            while (pending.top() != '(') {
                current.push_back(matrices[pending.top()]);
                pending.pop();
            }
            if (current.size() == 1) {
                out = al::matmul<int>(out, current[0]);
            } else if (current.size() == 2) {
                out = al::matmul<int>(current[1], current[0]);
            }
            pending.pop();
            i++;
        } else if (exp[i] == '.') {
            string num = "";
            i++;
            while (exp[i] != '.') {
                num += exp[i];
                i++;
            }
            pending.push(std::stoi(num));
            i++;
        } else if (exp[i] == '(') {
            pending.push('(');
            i++;
        }
    }
    return out;
}

template <typename T>
std::vector<std::vector<T>> chain_matmul(const std::vector<std::vector<std::vector<T>>> &matrices, const std::vector<int> &dims) {
    std::vector<std::vector<T>> s = matrix_chain_order<T>(dims);
    string str;
    get_optimal_parans<T>(s, str, 1, dims.size() - 1);
    return parse_and_compute<T>(str, matrices);
}
} // namespace al