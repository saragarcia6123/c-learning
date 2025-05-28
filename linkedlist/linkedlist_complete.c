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

Node* getFirst(LinkedList *list) {
	if (list->size == 0) {
		return NULL;
	}
	return list->head;
}

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

Node* get(LinkedList *list, int index) {
	if (list->size == 0) {
		return NULL;
	}

	if (index >= list->size) {
		return NULL;
	}

	Node *cur = list->head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur;
}

void insertFirst(LinkedList *list, int val) {
	Node *n = newNode(val);

	if (list->head) {
		n->next = list->head;
	}

	list->head = n;
	list->size++;

	printf("Inserted node at head with value %d.\n", val);
}

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

void deleteFirst(LinkedList *list) {
	if (!list->head) {
		printf("List is empty.\n");
		return;
	}

	if (list->head->next) {
		list->head = list->head->next;
	} else {
		list->head = NULL;
	}

	list->size--;

	printf("Deleted node at head.\n");
}

void deleteLast(LinkedList *list) {
	if (!list->head) {
		printf("List is empty.\n");
		return;
	}

	if (list->head->next) {
		Node *prev = list->head;
		while (prev->next->next) {
			prev = prev->next;
		}

		prev->next = NULL;
	} else {
		list->head = NULL;
	}

	list->size--;
	
	printf("Deleted node at tail.\n");
}

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
		insertFirst(list, val);
		return;
	}
	
	if (index == list->size) {
		insertLast(list, val);
		return;
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

void delete(LinkedList *list, int index) {
	if (list->size == 0) {
		printf("List is empty.\n");
		return;
	}

	if (index < 0) {
		printf("Index cannot be negative.\n");
		return;
	}

	if (index >= list->size) {
		printf("Index exceeds size.\n");
		return;
	}

	if (index == 0) {
		deleteFirst(list);
		return;
	}

	if (index == list->size-1) {
		deleteLast(list);
		return;
	}
	
	Node *prev = list->head;
	for (int i = 0; i < index; i++) {
		prev = prev->next;
	}

	Node *target = prev->next;
	if (target->next) {
		prev->next = target->next;
	} else {
		prev->next = NULL;	
	}
	
	free(target);
	list->size--;

	printf("Deleted node at index %d.\n", index);
}

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

	for (int i = 0; i < NUMS; i++) {
		int r = randInt(MIN_VAL, MAX_VAL);
		insertLast(list, r);
	}

	printList(list);

	insert(list, 0, 5);
	insert(list, 4, -25);

	insertFirst(list, 42);

	delete(list, 1);
	delete(list, list->size-1);

	update(list, 8, 200);

	printList(list);

	printf("%d: %d\n", 8, get(list, 8)->val);
	printf("%d: %d\n", 4, get(list, 4)->val);
	printf("%d: %d\n", 0, getFirst(list)->val);
	printf("%d: %d\n", list->size-1, getLast(list)->val);

	freeList(list);
	return 0;
}
