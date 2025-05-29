#include <stdbool.h>
#include "tree_node.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getHeight(const TreeNode *n) {
    if (!n->left && !n->right) {
        return 0;
    }

    const int lh = (n->left != NULL) ? n->left->height : 0;
    const int rh = (n->right != NULL) ? n->right->height : 0;

    return MAX(lh, rh) + 1;
}

int getBalance(const TreeNode *n) {
    if (n->height == 0) {
        return 0;
    }

    const int lh = (n->left != NULL) ? n->left->height : 0;
    const int rh = (n->right != NULL) ? n->right->height : 0;

    return lh - rh;
}

TreeNode* getMinOrMax(TreeNode *root, bool isMax) {

    // Base case: no children
    if (root->height == 0) {
        return root;
    }

    if (root->height == 1) {
        if (!isMax) {
            return root->left;
        } else {
            return root->right;
        }
    }

    // Only left child
    if(root->left && !root->right) {
        return getMinOrMax(root->left, isMax);
    }

    // Only right child
    if (!root->left && root->right) {
        return getMinOrMax(root->right, isMax);
    }

    // 2 children
    if (root->left) {
        if (!isMax) {
            return getMinOrMax(root->left, isMax);
        } else {
            return getMinOrMax(root->right, isMax);
        }
    }

    return NULL;
}

// Find minimum value in a subtree
TreeNode* getMin(TreeNode *root) {
    return getMinOrMax(root, false);
}

// Find maximum value in a subtree
TreeNode* getMax(TreeNode *root) {
    return getMinOrMax(root, true);
}