/**
 * Data Structures - binary search tree
 * binary_search_tree.cpp
 * Purpose: Implementation of Binary Search Tree
 *
 * @author Kailash Uniyal
 * @version 1.0 28/10/18
*/

#include <climits>
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
  public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

template <typename T>
class BST {
  private:
    BinaryTreeNode<T> *root;

  public:
    BST() {
        this->root = NULL;
        takeInputLevelWise();
    }

    BST(T rootData) {
        insert(rootData);
    }

    BST(T *arr, int n) {
        constructTree(arr, n);
    }

    ~BST() {
        delete this->root;
    }

  private:
    BinaryTreeNode<T> *constructTreeHelper(T *input, T start, T end) {
        if (end < start) {
            return NULL;
        }
        int rootIndex = (start + end) / 2;
        BinaryTreeNode<T> *root = new BinaryTreeNode<T>(input[rootIndex]);
        root->left = constructTreeHelper(input, start, rootIndex - 1);
        root->right = constructTreeHelper(input, rootIndex + 1, end);
        return root;
    }

  public:
    void constructTree(T *input, int n) {
        al::heapSort(input, n);
        this->root = constructTreeHelper(input, 0, n - 1);
    }

  private:
    BinaryTreeNode<T> *takeInputLevelWiseHelper() {
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

  public:
    void takeInputLevelWise() {
        root = takeInputLevelWiseHelper();
    }

  private:
    BinaryTreeNode<T> *insertNode(BinaryTreeNode<T> *node, T element) {
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

  public:
    void insert(T data) {
        this->root = insertNode(this->root, data);
    }

  private:
    BinaryTreeNode<T> *searchTree(BinaryTreeNode<T> *node, T element) {
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

  public:
    BinaryTreeNode<T> *search(T data) {
        return searchTree(this->root, data);
    }

  private:
    BinaryTreeNode<T> *removeNode(BinaryTreeNode<T> *node, T data) {
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

  public:
    void remove(T data) {
        this->root = removeNode(this->root, data);
    }

  private:
    void inOrderTraversal(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return;
        }
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

  public:
    void inOrder() {
        inOrder(this->root);
    }

  private:
    void preOrderTraversal(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

  public:
    void preOrder() {
        preOrder(this->root);
    }

  private:
    void postOrderTraversal(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

  public:
    void postOrder() {
        postOrder(this->root);
    }

  private:
    bool isBinarySearchTree(BinaryTreeNode<T> *node, T min = INT_MIN, T max = INT_MAX) {
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

  public:
    bool isBST() {
        return isBinarySearchTree(this->root);
    }

  private:
    T minimumNode(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return INT_MAX;
        }
        return min(node->data, min(minimumNode(node->left), minimumNode(node->right)));
    }

  public:
    T minimum() {
        return minimumNode(this->root);
    }

  private:
    T maximumNode(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return INT_MIN;
        }
        return max(node->data, max(maximumNode(node->left), maximumNode(node->right)));
    }

  public:
    T maximum() {
        return maximumNode(this->root);
    }

  private:
    int heightTree(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + max(heightTree(node->left), heightTree(node->right));
    }

  public:
    int height() {
        return heightTree(this->root);
    }

  private:
    int sizeTree(BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + sizeTree(node->left) + sizeTree(node->right);
    }

  public:
    int size() {
        return sizeTree(this->root);
    }

  private:
    void printTree(BinaryTreeNode<T> *node) {
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

  public:
    void print() {
        printTree(this->root);
    }
};
