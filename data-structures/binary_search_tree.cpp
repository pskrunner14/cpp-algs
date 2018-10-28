/**
 * Data Structures - binary search tree
 * binary_search_tree.cpp
 * Purpose: Implementation of Binary Search Tree
 *
 * @author Kailash Uniyal
 * @version 1.0 28/10/18
*/

#include <iostream>
#include <climits>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
  public:
     T data;
	 BinaryTreeNode* left;
	 BinaryTreeNode* right;

	 BinaryTreeNode(T data){
		 this->data = data;
		 left = NULL;
		 right = NULL;
	 }
	 ~BinaryTreeNode(){
		 delete left;
		 delete right;
	 }
};

template <typename T>
class BST {
  public:
    BinaryTreeNode<T>* root;

    BST(){
	    root = NULL;
    }

    ~BST(){
	    delete root;
    }

	BinaryTreeNode<T>* takeInputLevelWiseHelper() {
		T rootData;
		cout << "Enter root data" << endl;
		cin >> rootData;
		if(rootData == -1) {             // if data is -1 consider it as no child node.
			return NULL;
		}
		BinaryTreeNode<T>* root = new BinaryTreeNode<T>(rootData);
		queue<BinaryTreeNode<T>*> pendingNodes;               // queue used to input levelwise
		pendingNodes.push(root);

		while(pendingNodes.size() != 0) {
			BinaryTreeNode<T>* front = pendingNodes.front();
			pendingNodes.pop();
			cout << "Enter left child of " << front->data << endl;
			T leftChildData;
			cin >> leftChildData;
			if(leftChildData != -1) {
				BinaryTreeNode<T>* child = new BinaryTreeNode<T>(leftChildData);
				front->left = child;
				pendingNodes.push(child);               // Push child node for inputing there child nodes.
			}
			cout << "Enter right child of " << front->data << endl;
			T rightChildData;
			cin >> rightChildData;
			if(rightChildData != -1) {
				BinaryTreeNode<T>* child = new BinaryTreeNode<T>(rightChildData);
				front->right = child;
				pendingNodes.push(child);               // Push child node for inputing there child nodes.
			}
		}
		return root;
	}

	void takeInputLevelWise(){
		root = takeInputLevelWiseHelper();
	}

	bool search(BinaryTreeNode<T>* root, T element){
		if(root == NULL){
			return false;
		}
		if(root->data == element){
			return true;
		}
		if(root->data < element){
			return search(root->right, element);
		} else {
			return search(root->left, element);
		}
	}

	void search(T data){
		if(search(root, data)){
			cout << "Found!" << endl;
		} else {
			cout << "Not Found!" << endl;
		}
	}

	BinaryTreeNode<T>* insert(T element, BinaryTreeNode<T>* node){
		if(node == NULL){
			BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(element);
			return newNode;
		}
		if(element < node->data){
			node->left = insert(element, node->left);
		} else {
			node->right = insert(element, node->right);
		}
		return node;
	}

	void insert(T data){
		this->root = insert(data, this->root);
	}

	void printTree(BinaryTreeNode<T>* root){
		if(root == NULL){
			return;
		}
		cout << root->data << ": ";
		if(root->left != NULL){
			cout << "L:" << root->left->data << ",";
		}
		if(root->right != NULL){
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}

	void printTree(){
		printTree(this->root);
	}

    BinaryTreeNode<T>* deleteData(T data, BinaryTreeNode<T>* node){
        if(node == NULL){
            return NULL;
        }
        if(data > node->data){
            node->right = deleteData(data, node->right);
            return node;
        } else if(data < node->data){
            node->left = deleteData(data, node->left);
            return node;
        } else {
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            } else if(node->left == NULL){
                BinaryTreeNode<T>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } else if(node->right == NULL){
                BinaryTreeNode<T>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            } else {
                BinaryTreeNode<T>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                T rightMinData = minNode->data;
				node->data = rightMinData;
				node->right = deleteData(rightMinData, node->right);
				return node;
            }
        }
    }

	void deleteData(T data){
		root = deleteData(data, root);
	}

	void inOrder(BinaryTreeNode<T>* root){
		if(root == NULL) {
			return;
		}
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

	void inOrder(){
		inOrder(root);
	}

	void preOrder(BinaryTreeNode<T>* root){
		if(root == NULL) {
			return;
		}
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

	void preOrder(){
		preOrder(root);
	}

	void postOrder(BinaryTreeNode<T>* root){
		if(root == NULL) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}

	void postOrder(){
		postOrder(root);
	}

	bool isBST(BinaryTreeNode<T>* root, T min = INT_MIN, T max = INT_MAX){
		if(root == NULL) {
			return true;
		}
		if(root->data < min || root->data >= max) {
			return false;
		}
		bool isLeftOk = isBST(root->left, min, root->data);
		bool isRightOk = isBST(root->right, root->data, max);
		return isLeftOk && isRightOk;
	}

	void isBST(){
		if(isBST(root)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	BinaryTreeNode<T>* constructTreeHelper(T *input, T start, T end){
		if(end < start){
			return NULL;
		}
		int rootIndex = (start + end) / 2;
		BinaryTreeNode<T>* root = new BinaryTreeNode<T>(input[rootIndex]);
		root->left = constructTreeHelper(input, start, rootIndex - 1);
		root->right = constructTreeHelper(input, rootIndex + 1, end);
		return root;
	}

	void constructTree(T *input, int n){
		root = constructTreeHelper(input, 0, n - 1);
	}

	T minimum(BinaryTreeNode<T>* root){
		if(root == NULL){
			return INT_MAX;
		}
		return min(root->data, min(minimum(root->left), minimum(root->right)));
	}

	void minimum(){
		cout << minimum(root);
	}

	T maximum(BinaryTreeNode<T>* root){
		if(root == NULL){
			return INT_MIN;
		}
		return max(root->data, max(maximum(root->left), maximum(root->right)));
	}

	void maximum(){
		cout << maximum(root);
	}

	int height(BinaryTreeNode<T>* root){
		if(root == NULL) {
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));
	}

	void height(){
		cout << height(root);
	}

	int numNodes(BinaryTreeNode<T>* root){
		if(root == NULL) {
			return 0;
		}
		return 1 + numNodes(root->left) + numNodes(root->right);
	}

	void numNodes(){
		cout << numNodes(root);
	}
};
