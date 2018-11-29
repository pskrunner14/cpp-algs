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
#include <unordered_map>
#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)  \
    {                   \
        if (p) {        \
            delete (p); \
            (p) = NULL; \
        }               \
    }
#endif

namespace ds {

// Single Node interface
template <typename T>
class SingleNode {
  public:
    T value;
    SingleNode<T> *next;

    SingleNode(const T &);

    SingleNode(const T &, SingleNode *);
};

// Single Node implementation
template <typename T>
SingleNode<T>::SingleNode(const T &value) : value(value), next(NULL) {}

template <typename T>
SingleNode<T>::SingleNode(const T &value, SingleNode *next) : value(value), next(next) {}

// Double Node interface
template <typename T>
class DoubleNode {
  public:
    T value;
    DoubleNode<T> *prev;
    DoubleNode<T> *next;

    DoubleNode(const T &);

    DoubleNode(const T &, DoubleNode *, DoubleNode *);
};

// Double Node implementation
template <typename T>
DoubleNode<T>::DoubleNode(const T &value) : value(value), prev(NULL), next(NULL) {}

template <typename T>
DoubleNode<T>::DoubleNode(const T &value, DoubleNode *prev, DoubleNode *next) : value(value), prev(prev), next(next) {}

// Tree Node interface
template <typename T>
class TreeNode {
  public:
    T data;
    std::vector<TreeNode<T> *> children;

    TreeNode(const T &);
};

// Tree Node implementation
template <typename T>
TreeNode<T>::TreeNode(const T &data) : data(data) {}

// Binary Tree Node interface
template <typename T>
class BinaryTreeNode {
  public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(const T &);

    BinaryTreeNode(const T &, BinaryTreeNode *, BinaryTreeNode *);
};

// Binary Tree Node implementation
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &data) : data(data), left(NULL), right(NULL) {}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &data, BinaryTreeNode *left, BinaryTreeNode *right) : data(data), left(left), right(right){};

// Trie Node interface
class TrieNode {
  public:
    char data;
    bool isTerminal;
    std::unordered_map<char, TrieNode *> children;

    TrieNode(const char &);

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
class MapNode {
  public:
    const std::string key;
    T value;
    MapNode<T> *next;

    MapNode(const std::string &, const T &);
};

// Map Node implementation
template <typename T>
MapNode<T>::MapNode(const std::string &key, const T &value) : key(key), value(value), next(NULL) {}
} // namespace ds