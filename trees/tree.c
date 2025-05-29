#include <stdio.h>

#include "helpers.h"
#include "traverse.h"
#include "tree_node.h"

void updateHeights(TreeNode *n) {
    while (n) {
        int lh = (n->left != NULL) ? n->left->height : -1;
        int rh = (n->right != NULL) ? n->right->height : -1;
        n->height = (lh > rh ? lh : rh) + 1;

        if (n == n->parent) {
            // Prevent infinite loops
            printf("Cycle detected: node's parent is itself\n");
            break;
        }

        n = n->parent;
    }
}

// Swaps a parent and child around
void rotate(TreeNode *parent, int balance) {

    TreeNode *newParent;

    //Left imbalance
    if (balance > 0) {
        // Get the current left child
        newParent = parent->left;
        // Hold the current right child
        TreeNode *tempRight = newParent->right;
        // Assign the parent to the right of the child
        newParent->right = parent;
        // Reinsert the previous right child
        parent->left = tempRight;
    }

    // Right imbalance
    else {
        // Get the current right child
        newParent = parent->right;
        // Hold the current left child
        TreeNode *tempLeft = newParent->left;
        // Assign the parent to the left of the child
        newParent->left = parent;
        // Reinsert the previous left child
        parent->right = tempLeft;
    }

    // Update heights
    updateHeights(parent);
    updateHeights(newParent);
}

TreeNode* createRoot(const int value) {
    return newTreeNode(value, NULL);
}

// Insert a new node in the subtree
void insertNode(TreeNode *root, TreeNode *child) {
    if (root == NULL) {
        printf("Root cannot be null.\n");
        return;
    }

    if (child == NULL) {
        printf("Child cannot be null.\n");
        return;
    }

    if (root->val == child->val) {
        printf("Child already exists.\n");
        return;
    }

    // Insert left
    if (child->val < root->val) {
        if (!root->left) {
            root->left = child;
            child->parent = root;
            updateHeights(root->left);
        } else {
            insertNode(root->left, child);
        }
    }

    // Insert right
    if (child->val > root->val) {
        if (!root->right) {
            root->right = child;
            child->parent = root;
            updateHeights(root->right);
        } else {
            insertNode(root->right, child);
        }
    }

}

void insertValue(TreeNode *root, const int value) {
    TreeNode *n = newTreeNode(value, NULL);
    insertNode(root, n);
}

void removeNode(const TreeNode *n) {
    if (n == NULL) {
        printf("Node cannot be null.\n");
        return;
    }

    // No children
    if (n->height == 0) {
        if (n->parent && n->parent->left == n) {
            n->parent->left = NULL;
        }
        if (n->parent && n->parent->right == n) {
            n->parent->right = NULL;
        }
        return;
    }

    // Only left child
    if (n->left && !n->right) {
        if (n->parent && n->parent->left == n) {
            n->parent->left = n->left;
        }
        if (n->parent && n->parent->right == n) {
            n->parent->right = n->left;
        }
    }

    // Only right child
    if (!n->left && n->right) {
        if (n->parent && n->parent->left == n) {
            n->parent->left = n->right;
        }
        if (n->parent && n->parent->right == n) {
            n->parent->right = n->right;
        }
    }

    // Two children
    if (n->left && n->right) {
        // Replace with min leaf from right subtree
        TreeNode* minRight = getMin(n->right);
        if (n->parent && n->parent->left == n) {
            n->parent->left = minRight;
        } else if (n->parent && n->parent->right == n) {
            n->parent->right = minRight;
        }
    }
}

// Remove a node from a subtree
void removeValue(TreeNode *root, const int val) {

    // If less than root search left
    if (root->val < val) {
        if (root->left) {
            removeValue(root->left, val);
        } else {
            printf("Value %d not found.\n", val);
            return;
        }
    }

    // If greater than root search right
    if (root->val > val) {
        if (root->right) {
            removeValue(root->right, val);
        } else {
            printf("Value %d not found.\n", val);
            return;
        }
    }

    // If equal to root remove root
    if (root->val == val) {
        removeNode(root);
        if (root->parent) {
            updateHeights(root);
        }
    }
}

void freeTree(TreeNode *root) {
    if (root->left) {
        freeTree(root->left);
    }

    if (root->right) {
        freeTree(root->right);
    }

    free(root);
}
