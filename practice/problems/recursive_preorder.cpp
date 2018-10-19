#include <vector>
#include <iostream>
using namespace std;

vector<int> preordered_list;
// Add any helper functions(if needed) below.

struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};

// Add any helper functions(if needed) above.
void preorder(treeNode* root) {
    if (root == NULL)
        return;
    preordered_list.push_back(root->value);
    preorder(root->left);
    preorder(root->right);
}