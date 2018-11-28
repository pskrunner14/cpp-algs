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
BinaryTreeNode<T>::BinaryTreeNode(const T &, BinaryTreeNode *left, BinaryTreeNode *right) : data(data), left(left), right(right){};

// Trie Node interface
class TrieNode {
  public:
    char data;
    bool isTerminal;
    std::vector<TrieNode *> children;

    TrieNode(const char &);

    TrieNode(const char &, const bool &);

    bool contains(const char &) const;

    TrieNode *getChild(const char &) const;

    void addChild(TrieNode *const &);
};

// Trie Node comparator
class TrieNodeCompare {
  public:
    bool operator()(TrieNode *const &first, const char &data) const {
        return (first->data < data);
    }

    bool operator()(const char &data, TrieNode *const &second) const {
        return (data < second->data);
    }

    bool operator()(TrieNode *const &first, TrieNode *const &second) const {
        return (first->data < second->data);
    }
};

// Trie Node implementation
TrieNode::TrieNode(const char &data) : data(data) {
    isTerminal = false;
}

TrieNode::TrieNode(const char &data, const bool &term) : data(data) {
    isTerminal = term;
}

bool TrieNode::contains(const char &data) const {
    return (std::binary_search(std::begin(children), std::end(children), data, TrieNodeCompare()));
}

TrieNode *TrieNode::getChild(const char &data) const {
    auto where = std::lower_bound(std::begin(children), std::end(children), data, TrieNodeCompare());
    bool success = where != std::end(children) && !(TrieNodeCompare()(data, *where));
    return (success) ? children.at(where - std::begin(children)) : NULL;
}

void TrieNode::addChild(TrieNode *const &node) {
    auto where = std::lower_bound(std::begin(children), std::end(children), node, TrieNodeCompare());
    children.insert(where, node);
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