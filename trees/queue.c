#include <stdbool.h>
#include <stdio.h>
#include "queue.h"

bool isEmpty(Queue *q) {
    if (!q) return true;
    return (q->head == q->tail - 1);
}

bool isFull(Queue *q) {
    if (!q) return true;
    return (q->tail == q->capacity);
}

// Get first
int peek(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->items[q->head + 1];
}

// Insert last
void enqueue(Queue *q, const int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->tail] = value;
    q->tail++;
}

// Remove first
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    q->head++;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = q->head + 1; i < q->tail; i++) {
        printf("%d ", q->items[i]);
        if (i < q->tail-1) {
            printf("-> ");
        }
    }
    printf("\n");
}
