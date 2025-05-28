#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} NodeStruct;

void printNodeItem(NodeStruct *node) {
	if (node == NULL) {
		return;
	}

	printf("%d\n", node->val);

	return(printNodeItem(node->next));
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Must parse in at least 1 argument.");
		return 1;
	}

	NodeStruct *head, *curr;

	head = malloc(sizeof(NodeStruct));
	head->val = atoi(argv[1]);
	head->next = NULL;

	curr = head;

	for (int i = 2; i < argc; i++) {
		NodeStruct *newNode;
		newNode = malloc(sizeof(NodeStruct));

		newNode->val = atoi(argv[i]);
		newNode->next = NULL;

		curr->next = newNode;
		curr = curr->next;
	}

	printNodeItem(head);

	free(head);

	return 0;
}
