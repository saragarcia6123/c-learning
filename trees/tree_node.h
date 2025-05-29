#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <stdlib.h>

typedef struct Node {
    int val;
    int height;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} TreeNode;

static TreeNode* newTreeNode(const int val, TreeNode *parent) {
    TreeNode *n = malloc(sizeof(TreeNode));

    n->val = val;
    n->parent = parent;

    n->height = 0;
    n->left = NULL;
    n->right = NULL;

    return n;
}

#endif //TREE_NODE_H
