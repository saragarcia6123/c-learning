#include <stdio.h>

#include "queue.h"
#include "tree_node.h"

#define MAX_DEPTH 10

void preorder(const TreeNode *root, Queue *queue) {
    enqueue(queue, root->val);
    if (root->left) {
        preorder(root->left, queue);
    }
    if (root->right) {
        preorder(root->right, queue);
    }
}

void inorder(const TreeNode *root, Queue *queue) {
    if (root->left) {
        inorder(root->left, queue);
    }
    enqueue(queue, root->val);
    if (root->right) {
        inorder(root->right, queue);
    }
}

void postorder(const TreeNode *root, Queue *queue) {
    if (root->left) {
        postorder(root->left, queue);
    }
    if (root->right) {
        postorder(root->right, queue);
    }
    enqueue(queue, root->val);
}

void printTree(const TreeNode* root, int space, const int depth) {
    if (root == NULL) {
        return;
    }

    space += 4;
    printTree(root->right, space, depth + 1);

    for (int i = 0; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->val);
    printTree(root->left, space, depth + 1);
}
