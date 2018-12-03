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
 * Data Structures - node
 * node.hpp
 * Purpose: Node interfaces and impl.
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

namespace ds {

// Single Node interface
template <typename T>
struct SingleNode {
    T data;
    std::shared_ptr<SingleNode<T>> next;

    explicit SingleNode(const T &);

    SingleNode(const T &, std::shared_ptr<SingleNode<T>> &);
};

// Single Node implementation
template <typename T>
SingleNode<T>::SingleNode(const T &data) : data(data) {}

template <typename T>
SingleNode<T>::SingleNode(const T &data, std::shared_ptr<SingleNode<T>> &next) : data(data), next(next) {}

// Double Node interface
template <typename T>
struct DoubleNode {
    T data;
    std::shared_ptr<DoubleNode<T>> prev;
    std::shared_ptr<DoubleNode<T>> next;

    explicit DoubleNode(const T &);

    DoubleNode(const T &, std::shared_ptr<DoubleNode<T>> &, std::shared_ptr<DoubleNode<T>> &);
};

// Double Node implementation
template <typename T>
DoubleNode<T>::DoubleNode(const T &data) : data(data) {}

template <typename T>
DoubleNode<T>::DoubleNode(const T &data, std::shared_ptr<DoubleNode<T>> &prev, std::shared_ptr<DoubleNode<T>> &next) : data(data), prev(prev), next(next) {}

// Tree Node interface
template <typename T>
struct TreeNode {
    T data;
    std::vector<std::shared_ptr<TreeNode<T>>> children;

    explicit TreeNode(const T &);
};

// Tree Node implementation
template <typename T>
TreeNode<T>::TreeNode(const T &data) : data(data) {}

// Binary Tree Node interface
template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    explicit BinaryTreeNode(const T &);

    BinaryTreeNode(const T &, BinaryTreeNode *, BinaryTreeNode *);
};

// Binary Tree Node implementation
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &data) : data(data), left(NULL), right(NULL) {}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &data, BinaryTreeNode *left, BinaryTreeNode *right) : data(data), left(left), right(right){};

// Trie Node interface
struct TrieNode {
    char data;
    bool isTerminal;
    std::map<char, std::shared_ptr<TrieNode>> children;

    explicit TrieNode(const char &);

    TrieNode(const char &, const bool &);

    bool contains(const char &) const;

    void remove(const char &);
};

// Trie Node implementation
TrieNode::TrieNode(const char &data) : data(data) {
    isTerminal = false;
}

TrieNode::TrieNode(const char &data, const bool &term) : data(data) {
    isTerminal = term;
}

bool TrieNode::contains(const char &data) const {
    return (children.find(data) != std::end(children));
}

void TrieNode::remove(const char &data) {
    children.erase(children.find(data), std::end(children));
}

// Map Node interface
template <typename T>
struct MapNode {
    const std::string key;
    T data;
    MapNode<T> *next;

    MapNode(const std::string &, const T &);
};

// Map Node implementation
template <typename T>
MapNode<T>::MapNode(const std::string &key, const T &data) : key(key), data(data), next(NULL) {}
} // namespace ds