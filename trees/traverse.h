#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "tree_node.h"
#include "queue.h"

void preorder(const TreeNode *root, Queue *queue);
void inorder(const TreeNode *root, Queue *queue);
void postorder(const TreeNode *root, Queue *queue);
void printTree(const TreeNode* root, int space, int depth);

#endif //TRAVERSE_H
