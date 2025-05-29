//
// Created by human on 5/29/25.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *items;
    int capacity;
    int head;
    int tail;
} Queue;

static Queue* newQueue(int capacity) {
    Queue* q = malloc(sizeof(Queue));
    q->items = malloc(capacity * sizeof(int));
    q->capacity = capacity;
    q->head = -1;
    q->tail = 0;
    return q;
}

bool isEmpty(Queue *q);
bool isFull(Queue *q);

int peek(Queue* q);

void enqueue(Queue *q, int value);
void dequeue(Queue* q);

void printQueue(Queue* q);

#endif //QUEUE_H
