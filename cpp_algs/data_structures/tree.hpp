#pragma once

/**
 * Data Structures - tree
 * tree.hpp
 * Purpose: Tree interface
 *
 * @author Prabhsimran Singh
 * @version 1.0 27/11/18
*/
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#include "node.hpp"

namespace ds {

// Tree interface
template <typename T>
class Tree {
  private:
    TreeNode<T> *root;

  public:
    Tree();

    ~Tree();
};

// Tree implementation
template <typename T>
Tree<T>::Tree() : root(NULL) {}

template <typename T>
Tree<T>::~Tree() {
    SAFE_DELETE(root);
}

} // namespace ds