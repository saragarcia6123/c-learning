#ifndef TREE_H
#define TREE_H

#include "tree_node.h"

TreeNode* createRoot(int value);
void insertValue(TreeNode *root, int value);
void removeValue(TreeNode *root, int val);

void freeTree(TreeNode *root);

#endif //TREE_H
