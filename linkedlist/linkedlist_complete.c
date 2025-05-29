#include <stdio.h>
#include <stdlib.h>

typedef struct NodeP {
	int val;
	struct NodeP *next;
} Node;

typedef struct {
	Node *head;
	int size;
} LinkedList;

Node* newNode(int val) {
	Node *n = malloc(sizeof(Node));
	n->val = val;
	n->next = NULL;
	return n;
}

LinkedList* newLinkedList() {
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->size = 0;
	return list;
}

/* Returns the head of a list or null if empty */
Node* getFirst(LinkedList *list) {
	if (list->size == 0) {
		return NULL;
	}
	return list->head;
}

/* Returns the tail of a list or null if empty */
Node* getLast(LinkedList *list) {
	if (list->size == 0) {
		return NULL;
	}

	Node *cur = list->head;
	while (cur->next) {
		cur = cur->next;
	}
	return cur;
}

/* Returns node at given index */
Node* get(LinkedList *list, int index) {

	if (index >= list->size) {
		return NULL;
	}

	Node *cur = list->head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}

	return cur;
}

/* Inserts new node at the start and sets new head */
void insertFirst(LinkedList *list, int val) {
	Node *n = newNode(val);

	n->next = list->head;

	list->head = n;
	list->size++;

	printf("Inserted node at head with value %d.\n", val);
}

/* Inserts new node at the end */
void insertLast(LinkedList *list, int val) {
	Node *n = newNode(val);

	if (!list->head) {
		list->head = n;
	} else {
		Node *prev = list->head;
		while(prev->next) {
			prev = prev->next;
		}
		prev->next = n;
	}

	list->size++;

	printf("Inserted node at tail with value %d.\n", val);
}

/* Removes and returns head */
Node* removeFirst(LinkedList *list) {
	if (!list->head) {
		printf("List is empty.\n");
		return NULL;
	}

	Node *target = list->head;
	
	list->head = list->head->next;
	list->size--;

	printf("Removed node at head with value %d.\n", target->val);

	return target;
}

/* Removes and returns tail */
Node* removeLast(LinkedList *list) {
	if (!list->head) {
		printf("List is empty.\n");
		return NULL;
	}
	
	Node *target = NULL;

	if (list->head->next) {
		Node *prev = list->head;
		while (prev->next->next) {
			prev = prev->next;
		}
		target = prev->next;
		prev->next = NULL;
	} else {
		target = list->head;
		list->head = NULL;
	}

	list->size--;
	
	printf("Removed node at tail with value %d.\n", target->val);
	return target;
}

/* Inserts new node at given index with given value */
void insert(LinkedList *list, int index, int val) {

	if (index < 0) {
		printf("Index cannot be negative.\n");
		return;
	}

	if (index > list->size) {
		printf("Index cannot be greater than list size.\n");
		return;
	}

	if (index == 0 || list->size == 0) {
		return insertFirst(list, val);
	}
	
	if (index == list->size) {
		return insertLast(list, val);
	}

	Node *n = newNode(val);
	Node *prev = list->head;

	for (int i = 0; i < index-1; i++) {
		prev = prev->next;
	}

	// Assumed to be true because of last index check but just in case
	if (prev->next) {
		n->next = prev->next;
	}

	prev->next = n;
	list->size++;

	printf("Inserted node at index %d with value %d.\n", index, val);
}

/* Removes node at given index */
Node* removeNode(LinkedList *list, int index) {
	if (list->size == 0) {
		printf("List is empty.\n");
		return NULL;
	}

	if (index < 0) {
		printf("Index cannot be negative.\n");
		return NULL;
	}

	if (index >= list->size) {
		printf("Index exceeds size.\n");
		return NULL;
	}

	if (index == 0) {
		return removeFirst(list);
	}

	if (index == list->size-1) {
		return removeLast(list);
	}
	
	Node *prev = list->head;
	for (int i = 0; i < index-1; i++) {
		prev = prev->next;
	}

	Node *target = prev->next;
	if (target->next) {
		prev->next = target->next;
	} else {
		prev->next = NULL;	
	}
	
	list->size--;

	printf("Removed node at index %d with value %d.\n", index, target->val);

	return target;
}

/* Updates value of node at given index */
void update(LinkedList *list, int index, int val) {
	if (list->size == 0) {
		printf("List is empty.\n");
		return;
	}

	if (index > list->size-1) {
		printf("Index exceeds size.\n");
		return;
	}

	Node *target = list->head;

	for (int i = 0; i < index; i++) {
		target = target->next;
	}
	
	int prevVal = target->val;
	target->val = val;

	printf("Updated node at index %d from %d to %d.\n", index, prevVal, val);
}

/* Iterates through and prints each element in the list */
void printList(LinkedList *list) {
	if (list->size == 0) {
		return;
	}
	
	Node *cur = list-> head;
	while(cur) {
		if (cur->next) {
			printf("%d -> ", cur->val);
		} else {
			printf("%d", cur->val);
		}
		cur = cur->next;
	}

	printf("\n");
}

/* Frees all node objects in list */
void freeList(LinkedList *list) {
	if (!list->head) {
		free(list);
		printf("List is empty. Freed 1 object.\n");
		return;
	}

	Node *cur = list->head;
	Node *next;

	int freed = 0;
	int expected = list->size;

	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
		freed++;
		list->size--;
	}

	free(list);
	// +1 to account for list itself
	printf("Freed %d objects. (Expected: %d)\n", freed+1, expected+1);
}

int randInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

int main(void) {
	int NUMS = 10;
	int MIN_VAL = -99;
	int MAX_VAL = 99;

	LinkedList *list = newLinkedList();

	Node *cur = NULL;

	for (int i = 0; i < NUMS; i++) {
		int r = randInt(MIN_VAL, MAX_VAL);
		insertLast(list, r);
	}

	printList(list);

	insert(list, 0, 5);
	insert(list, 4, -25);
	insertFirst(list, 42);

	printList(list);

	cur = removeNode(list, 1);
	free(cur);
	
	cur = removeNode(list, list->size-2);
	free(cur);

	cur = removeFirst(list);
	free(cur);

	cur = removeLast(list);
	free(cur);

	printList(list);

	update(list, 8, 200);
	update(list, 0, 0);
	update(list, list->size - 1, 100);

	printList(list);

	printf("%d: %d\n", 8, get(list, 8)->val);
	printf("%d: %d\n", 4, get(list, 4)->val);
	printf("%d: %d\n", 0, getFirst(list)->val);
	printf("%d: %d\n", list->size-1, getLast(list)->val);

	freeList(list);

	return 0;
}
