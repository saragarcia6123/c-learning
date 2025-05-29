#include <stdio.h>

#include "queue.h"
#include "tree.h"
#include "tree_node.h"
#include "traverse.h"

int main(void) {
	const int nums[6] = {83, 27, 56, 91, 14, 13};

 	TreeNode *root = createRoot(nums[0]);

	for (int i = 1; i < 6; i++) {
		insertValue(root, nums[i]);
	}

	Queue *queue = newQueue(100);
	inorder(root, queue);
	printQueue(queue);
	printf("\n");
	printTree(root, 0, 0);
}
