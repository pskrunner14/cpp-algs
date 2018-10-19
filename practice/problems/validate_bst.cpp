#include <climits>
#include <iostream>
using namespace std;
// namespace std have been included for this problem.

struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
};

bool is_bst(treeNode* root, int min, int max) {
    if (root == NULL)
        return true;
    if (root->value < min || root->value > max)
        return false;
    return is_bst(root->left, min, root->value) && is_bst(root->right, root->value, max);
}

// Add any helper functions(if needed) above.
bool validate_bst(treeNode* root) {
    return is_bst(root, INT_MIN, INT_MAX);
}