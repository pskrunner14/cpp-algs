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
 * Data Structures - binary search tree
 * binary_search_tree.hpp
 * Purpose: Binary Search Tree interface
 *
 * @author Kailash Uniyal, Prabhsimran Singh
 * @version 2.0 26/11/18
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#include "node.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class BinarySearchTree {
  private:
    // pointer to root node
    BinaryTreeNode<T> *root;

  public:
    // BST default constructor
    BinarySearchTree();

    // BST copy constructor
    BinarySearchTree(const T &);

    // BST constructor to create tree with vector of elements
    BinarySearchTree(const vector<T> &);

    // BST destructor
    ~BinarySearchTree();

  private:
    // recursive construct tree helper func.
    BinaryTreeNode<T> *constructTreeHelper(const vector<T> &, const T &, const T &);

  public:
    // constructs the BST using vector
    void constructTree(const vector<T> &);

  private:
    BinaryTreeNode<T> *takeInputLevelWiseHelper();

  public:
    // takes level wise input to create BST
    void takeInputLevelWise();

  private:
    // recursive insert node func.
    BinaryTreeNode<T> *insertNode(BinaryTreeNode<T> *, const T &);

  public:
    // inserts a node into BST
    void insert(const T &);

  private:
    // recursive search tree func.
    BinaryTreeNode<T> *searchTree(BinaryTreeNode<T> *, const T &) const;

  public:
    // searches the BST for data
    BinaryTreeNode<T> *search(const T &) const;

  private:
    BinaryTreeNode<T> *removeNode(BinaryTreeNode<T> *, const T &);

  public:
    void remove(const T &);

  private:
    void inOrderTraversal(BinaryTreeNode<T> *) const;

  public:
    void inOrder() const;

  private:
    void preOrderTraversal(BinaryTreeNode<T> *) const;

  public:
    void preOrder() const;

  private:
    void postOrderTraversal(BinaryTreeNode<T> *) const;

  public:
    void postOrder() const;

  private:
    bool isBinarySearchTree(BinaryTreeNode<T> *, const T & = INT_MIN, const T & = INT_MAX) const;

  public:
    bool isBinarySearchTree() const;

  private:
    T &minimumNode(BinaryTreeNode<T> *) const;

  public:
    T &minimum() const;

  private:
    T &maximumNode(BinaryTreeNode<T> *) const;

  public:
    T &maximum() const;

  private:
    int heightTree(BinaryTreeNode<T> *) const;

  public:
    int height() const;

  private:
    int sizeTree(BinaryTreeNode<T> *) const;

  public:
    int size() const;

  private:
    void printTree(BinaryTreeNode<T> *) const;

  public:
    void print() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(NULL) {
    takeInputLevelWise();
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const T &rootData) {
    insert(rootData);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const vector<T> &vec) {
    constructTree(vec);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::constructTreeHelper(const vector<T> &input, const T &start, const T &end) {
    if (end < start) {
        return NULL;
    }
    int rootIndex = (start + end) / 2;
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(input[rootIndex]);
    root->left = constructTreeHelper(input, start, rootIndex - 1);
    root->right = constructTreeHelper(input, rootIndex + 1, end);
    return root;
}

template <typename T>
void BinarySearchTree<T>::constructTree(const vector<T> &vec) {
    std::sort(std::begin(vec), std::end(vec));
    root = constructTreeHelper(vec, 0, vec.size() - 1);
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::takeInputLevelWiseHelper() {
    T rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1) { // if data is -1 consider it as no child node.
        return NULL;
    }
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);
    queue<BinaryTreeNode<T> *> pendingNodes; // queue used to input levelwise
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        BinaryTreeNode<T> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        T leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<T> *child = new BinaryTreeNode<T>(leftChildData);
            front->left = child;
            pendingNodes.push(child); // Push child node for inputing there child nodes.
        }
        cout << "Enter right child of " << front->data << endl;
        T rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<T> *child = new BinaryTreeNode<T>(rightChildData);
            front->right = child;
            pendingNodes.push(child); // Push child node for inputing there child nodes.
        }
    }
    return root;
}

template <typename T>
void BinarySearchTree<T>::takeInputLevelWise() {
    root = takeInputLevelWiseHelper();
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::insertNode(BinaryTreeNode<T> *node, const T &element) {
    if (node == NULL) {
        BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(element);
        return newNode;
    }
    if (element < node->data) {
        node->left = insertNode(node->left, element);
    } else {
        node->right = insertNode(node->right, element);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::insert(const T &data) {
    root = insertNode(root, data);
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::searchTree(BinaryTreeNode<T> *node, const T &element) const {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == element) {
        return node;
    } else if (node->data < element) {
        return searchTree(node->right, element);
    } else {
        return searchTree(node->left, element);
    }
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::search(const T &data) const {
    return searchTree(root, data);
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::removeNode(BinaryTreeNode<T> *node, const T &data) {
    if (node == NULL) {
        return NULL;
    }
    if (data > node->data) {
        node->right = removeNode(node->right, data);
        return node;
    } else if (data < node->data) {
        node->left = removeNode(node->left, data);
        return node;
    } else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        } else if (node->left == NULL) {
            BinaryTreeNode<T> *temp = node->right;
            node->right = NULL;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            BinaryTreeNode<T> *temp = node->left;
            node->left = NULL;
            delete node;
            return temp;
        } else {
            BinaryTreeNode<T> *minNode = node->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            T rightMinData = minNode->data;
            node->data = rightMinData;
            node->right = removeNode(node->right, rightMinData);
            return node;
        }
    }
}

template <typename T>
void BinarySearchTree<T>::remove(const T &data) {
    root = removeNode(this->root, data);
}

template <typename T>
void BinarySearchTree<T>::inOrderTraversal(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

template <typename T>
void BinarySearchTree<T>::inOrder() const {
    inOrder(root);
}

template <typename T>
void BinarySearchTree<T>::preOrderTraversal(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <typename T>
void BinarySearchTree<T>::preOrder() const {
    preOrder(root);
}

template <typename T>
void BinarySearchTree<T>::postOrderTraversal(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}

template <typename T>
void BinarySearchTree<T>::postOrder() const {
    postOrder(root);
}

template <typename T>
bool BinarySearchTree<T>::isBinarySearchTree(BinaryTreeNode<T> *node, const T &min, const T &max) const {
    if (node == NULL) {
        return true;
    }
    if (node->data < min || node->data >= max) {
        return false;
    }
    bool isLeftOk = isBinarySearchTree(node->left, min, node->data);
    bool isRightOk = isBinarySearchTree(node->right, node->data, max);
    return isLeftOk && isRightOk;
}

template <typename T>
bool BinarySearchTree<T>::isBinarySearchTree() const {
    return isBinarySearchTree(root);
}

template <typename T>
T &BinarySearchTree<T>::minimumNode(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return INT_MAX;
    }
    return min(node->data, min(minimumNode(node->left), minimumNode(node->right)));
}

template <typename T>
T &BinarySearchTree<T>::minimum() const {
    return minimumNode(root);
}

template <typename T>
T &BinarySearchTree<T>::maximumNode(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return INT_MIN;
    }
    return max(node->data, max(maximumNode(node->left), maximumNode(node->right)));
}

template <typename T>
T &BinarySearchTree<T>::maximum() const {
    return maximumNode(root);
}

template <typename T>
int BinarySearchTree<T>::heightTree(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(heightTree(node->left), heightTree(node->right));
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return heightTree(root);
}

template <typename T>
int BinarySearchTree<T>::sizeTree(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return 0;
    }
    return 1 + sizeTree(node->left) + sizeTree(node->right);
}

template <typename T>
int BinarySearchTree<T>::size() const {
    return sizeTree(this->root);
}

template <typename T>
void BinarySearchTree<T>::printTree(BinaryTreeNode<T> *node) const {
    if (node == NULL) {
        return;
    }
    cout << node->data << ": ";
    if (node->left != NULL) {
        cout << "L:" << node->left->data << ",";
    }
    if (root->right != NULL) {
        cout << "R:" << node->right->data;
    }
    cout << endl;
    printTree(node->left);
    printTree(node->right);
}

template <typename T>
void BinarySearchTree<T>::print() const {
    printTree(this->root);
}
} // namespace ds